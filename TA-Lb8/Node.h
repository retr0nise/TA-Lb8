#pragma once
#include <iostream>

template<typename T, typename K>
class TreeNode
{
public:
	T Value;
	K Key;
	TreeNode<T, K>* Left = nullptr;
	TreeNode<T, K>* Right = nullptr;

	TreeNode(T value, K key)
		: Value(value), Key(key) {
	}

	friend std::ostream& operator <<(std::ostream& os, const TreeNode<T, K>& node) {
		return os << '[' << node.Value << ']';
	}
};