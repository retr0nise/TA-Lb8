#pragma once
#include <iostream>
#include "Node.h"

template<typename T, typename K>
class SearchTree
{
private:
	int _count = 0;
	char _aroundMode = 0;
	TreeNode<T, K>* _coreNodePtr = nullptr;
public:
	int getCount() const {
		return _count;
	}
	char getAroundMode() const {
		return _aroundMode;
	}
	void setAroundMode(char mode) {
		if (mode < 0 || mode > 2) {
			throw std::invalid_argument("Invalid around mode!");
		}
		_aroundMode = mode;
	}
	void add(T value, K key) {
		if (_coreNodePtr == nullptr) {
			_coreNodePtr = new TreeNode<T, K>(value, key);
			_count++;
		}
		else {
			addNode(_coreNodePtr, new TreeNode<T, K>(value, key));
		}
	}
	void remove(K key) {
		_coreNodePtr = deleteNode(_coreNodePtr, key);
	}
	T peek(K key) const {
		TreeNode<T, K>* nodePtr = searchNode(_coreNodePtr, key);
		if (nodePtr == nullptr) {
			throw std::invalid_argument("A node with this key doesn't exist!");
		}
		return nodePtr->Value;
	}
	bool isContains(K key) const {
		return searchNode(_coreNodePtr, key) != nullptr;
	}
	int getHeight() const {
		return getHeightFrom(_coreNodePtr);
	}
	int getDepth(K key) const {
		return getDepthFrom(_coreNodePtr, key);
	}
private:
	void addNode(TreeNode<T, K>* corePtr, TreeNode<T, K>* nodePtr) {
		if (nodePtr->Key < corePtr->Key) {
			if (corePtr->Left == nullptr) {
				corePtr->Left = nodePtr;
				_count++;
			}
			else {
				addNode(corePtr->Left, nodePtr);
			}
		}
		else if (nodePtr->Key > corePtr->Key) {
			if (corePtr->Right == nullptr) {
				corePtr->Right = nodePtr;
				_count++;
			}
			else {
				addNode(corePtr->Right, nodePtr);
			}
		}
		else {
			
			throw std::invalid_argument("Вузол з цим ключем вже існує!");
			
		}
	}
	TreeNode<T, K>* searchNode(TreeNode<T, K>* node, K key) const {
		if (node == nullptr) {
			return nullptr;
		}
		else if (node->Key == key) {
			return node;
		}
		else {
			return (key < node->Key) ? searchNode(node->Left, key) : searchNode(node->Right, key);
		}
	}
	TreeNode<T, K>* getMin(TreeNode<T, K>* node) const {
		if (node == nullptr) {
			return nullptr;
		}
		else if (node->Left == nullptr) {
			return node;
		}
		else {
			return getMin(node->Left);
		}
	}
	TreeNode<T, K>* getMax(TreeNode<T, K>* node) const {
		if (node == nullptr) {
			return nullptr;
		}
		else if (node->Right == nullptr) {
			return node;
		}
		else {
			return getMax(node->Right);
		}
	}
	TreeNode<T, K>* deleteNode(TreeNode<T, K>* node, K key) {
		if (node == nullptr) {
			throw std::invalid_argument("Вузол з цим ключем не існує!");
		}
		else if (key < node->Key) {
			node->Left = deleteNode(node->Left, key);
		}
		else if (key > node->Key) {
			node->Right = deleteNode(node->Right, key);
		}
		else {
			if (node->Left == nullptr || node->Right == nullptr) {
				TreeNode<T, K>* tmp = node;
				node = (node->Left == nullptr) ? node->Right : node->Left;
				delete tmp;
				_count--;
			}
			else {
				TreeNode<T, K>* maxInLeft = getMax(node->Left);
				node->Key = maxInLeft->Key;
				node->Value = maxInLeft->Value;
				node->Left = deleteNode(node->Left, maxInLeft->Key);
			}
		}
		return node;
	}
	int getHeightFrom(TreeNode<T, K>* node) const {
		if (node == nullptr) {
			return 0;
		}

		int leftHeight = getHeightFrom(node->Left) + 1;
		int rightHeight = getHeightFrom(node->Right) + 1;
		return leftHeight > rightHeight ? leftHeight : rightHeight;
	}
	int getDepthFrom(TreeNode<T, K>* node, K key) const {
		if (node == nullptr) {
			throw std::invalid_argument("Вузол з цим ключем не існує!");
		}
		else if (node->Key == key) {
			return 1;
		}
		else {
			return key < node->Key ? getDepthFrom(node->Left, key) + 1 : getDepthFrom(node->Right, key) + 1;
		}
	}
	void aroundDirectly(std::ostream& os, TreeNode<T, K>* node) const {
		if (node == nullptr) {
			return;
		}
		os << " " << *node;
		aroundDirectly(os, node->Left);
		aroundDirectly(os, node->Right);
	}
	void aroundReversely(std::ostream& os, TreeNode<T, K>* node) const {
		if (node == nullptr) {
			return;
		}
		aroundReversely(os, node->Left);
		aroundReversely(os, node->Right);
		os << " " << *node;
	}
	void aroundSymmetrically(std::ostream& os, TreeNode<T, K>* node) const {
		if (node == nullptr) {
			return;
		}
		aroundSymmetrically(os, node->Left);
		os << " " << *node;
		aroundSymmetrically(os, node->Right);
	}
	friend std::ostream& operator <<(std::ostream& os, const SearchTree<T, K>& searchTree) {
		char aroundMode = searchTree.getAroundMode();
		if (aroundMode == 0) {
			searchTree.aroundDirectly(os, searchTree._coreNodePtr);
		}
		else if (aroundMode == 1) {
			searchTree.aroundReversely(os, searchTree._coreNodePtr);
		}
		else {
			searchTree.aroundSymmetrically(os, searchTree._coreNodePtr);
		}
		return os;
	}
};