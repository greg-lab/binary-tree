#include "bintree.hpp"
#include <iostream>

void print(int data) {
	std::cout << data << " ";
}

int main() {

	BinTree<int> tree;
	tree.insert(8);
	tree.insert(3);
	tree.insert(10);
	tree.insert(1);
	tree.insert(6);
	tree.insert(14);
	tree.insert(4);
	tree.insert(7);
	tree.insert(13);

	tree.inorder(print);
	std::cout << std::endl;

	auto node = tree.find(6);
	tree.preorder(print, node);
	
	tree.preorder([](int &data)->void { data++; });
	tree.preorder(print);

	return 0;
}
