#pragma once
#include "node.hpp"

/**
 * Following class represents binary tree. It has a single attribute - a pointer to the first node in the tree.
 * 
 * @author greg-lab
 */

template <class T>
class BinTree {
public:
	explicit BinTree();

	~BinTree();

	// getter
	Node<T> *getRoot();

	/**
	 * Inserts a given value into the binary tree starting from a given node.
	 * If the second parameter is not specified, Algorithm starts from the root node.
	 * 
	 * @param data - value to be inserted into the structure
	 * @param leaf - pointer to node	
	 */
	void insert(T data, Node<T> *leaf);
	void insert(T data);

	/**
	 * Searches for node which data equals to desired data. Algorithm starts from the node specified in the second argument.
	 * If the second argument is not specified, method searches from the root node.
	 *
	 * @param data - desired data.
	 * @param leaf - pointer to node
	 *
	 * @return - If the data found, pointer to the appropriate node is returned. Otherwise, nullptr is returned.
	 */
	Node<T> *find(T data, Node<T> *leaf);
	Node<T> *find(T data);

	/**
	 * Removes nodes from the data structure. Method starts from the node given in argument.
	 * If the argument is not specified, every node is removed.
	 *
	 * @param leaf - pointer to node
	 */
	void clear(Node<T> *leaf);
	void clear();

	// Checks whether the tree is empty
	bool empty();

	/**
	 * Calls a given function for every node in the tree in the following order:
	 * node-left-right
	 * If the second parameter is specified, Algorithms starts from the given node.
	 *
	 * @param func - function to be called
	 * @param leaf - pointer to node
	 */
	template <class Function>
	void preorder(Function func, Node<T> *leaf);

	template <class Function>
	void preorder(Function func);

	/**
	 * Calls a given function for every node in the tree in the following order:
	 * left-node-right
	 * If the second parameter is specified, Algorithms starts from the given node.
	 *
	 * @param func - function to be called
	 * @param leaf - pointer to node
	 */
	template <class Function>
	void inorder(Function func, Node<T> *leaf);

	template <class Function>
	void inorder(Function func);

	/**
	 * Calls a given function for every node in the tree in the following order:
	 * left-right-node
	 * If the second parameter is specified, Algorithms starts from the given node.
	 *
	 * @param func - function to be called
	 * @param leaf - pointer to node
	 */
	template <class Function>
	void postorder(Function func, Node<T> *leaf);

	template <class Function>
	void postorder(Function func);



private:
	Node<T> *root_;
};

template <class T>
BinTree<T>::BinTree() {
	root_ = nullptr;
}

template <class T>
void BinTree<T>::insert(T data, Node<T> *leaf) {
	if (data < leaf->getData()) {
		if (leaf->getLeft() != nullptr) {
			insert(data, leaf->getLeft());
		} else {
			auto node = new Node<T>(data);
			if (node == nullptr)
				return;
			leaf->setLeft(node);
		}
	} else {
		if (leaf->getRight() != nullptr) {
			insert(data, leaf->getRight());
		} else {
			auto node = new Node<T>(data);
			if (node == nullptr)
				return;
			leaf->setRight(node);
		}
	}
}

template <class T>
void BinTree<T>::insert(T data) {
	if (root_ != nullptr) {
		insert(data, root_);
	} else {
		auto node = new Node<T>(data);
		root_ = node;
	}
}

template <class T>
Node<T> *BinTree<T>::find(T data, Node<T> *leaf) {
	if (leaf != nullptr) {
		if (leaf->getData() == data) {
			return leaf;
		}

		if (data < leaf->getData()) {
			return find(data, leaf->getLeft());
		} else {
			return find(data, leaf->getRight());
		}
	}

	return nullptr;
}

template <class T>
Node<T> *BinTree<T>::find(T data) {
	return find(data, root_);
}

template <class T>
void BinTree<T>::clear() {
	clear(root_);
}

template <class T>
void BinTree<T>::clear(Node<T> *leaf) {
	if (leaf != nullptr) {
		clear(leaf->getLeft());
		clear(leaf->getRight());
		delete leaf;
	}
}

template <class T>
BinTree<T>::~BinTree() {
	clear();
}

template <class T>
bool BinTree<T>::empty() {
	return root_ == nullptr;
}

template <class T> template <class Function>
void BinTree<T>::preorder(Function func) {
	preorder(func, root_);
}

template <class T> template <class Function>
void BinTree<T>::preorder(Function func, Node<T> *leaf) {
	if (leaf != nullptr) {
		func(leaf->getData());
		preorder(func, leaf->getLeft());
		preorder(func, leaf->getRight());
	}
}

template <class T> template <class Function>
void BinTree<T>::inorder(Function func) {
	inorder(func, root_);
}

template <class T> template <class Function>
void BinTree<T>::inorder(Function func, Node<T> *leaf) {
	if (leaf != nullptr) {
		inorder(func, leaf->getLeft());
		func(leaf->getData());
		inorder(func, leaf->getRight());
	}
}

template <class T> template <class Function>
void BinTree<T>::postorder(Function func) {
	postorder(func, root_);
}

template <class T> template <class Function>
void BinTree<T>::postorder(Function func, Node<T> *leaf) {
	if (leaf != nullptr) {
		postorder(func, leaf->getLeft());
		postorder(func, leaf->getRight());
		func(leaf->getData());
	}
}