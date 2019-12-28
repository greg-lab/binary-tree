#pragma once

/**
 * Following class is a generic class which represents a single node in binary tree.
 * Every node has data, pointer to the left node and pointer to the right node.
 * 
 * @author greg-lab
 */

template <class T>
class Node {
public:
	explicit Node();
	explicit Node(T data);

	// setters
	void setData(T data);
	void setRight(Node<T> *leaf);
	void setLeft(Node<T> *leaf);

	// getters
	T getData();
	Node<T> *getRight();
	Node<T> *getLeft();

private:
	T data_;
	Node<T> *right_;
	Node<T> *left_;
};

template <class T>
Node<T>::Node() {
	right_ = nullptr;
	left_ = nullptr;
}

template <class T>
Node<T>::Node(T data) {
	right_ = nullptr;
	left_ = nullptr;
	data_ = data;
}

template <class T>
void Node<T>::setData(T data) {
	data_ = data;
}

template <class T>
void Node<T>::setRight(Node<T> *leaf) {
	right_ = leaf;
}

template <class T>
void Node<T>::setLeft(Node<T> *leaf) {
	left_ = leaf;
}

template <class T>
T  Node<T>::getData() {
	return data_;
}

template <class T>
Node<T> *Node<T>::getRight() {
	return right_;
}

template <class T>
Node<T> *Node<T>::getLeft() {
	return left_;
}