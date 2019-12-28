#include "bintree.hpp"
#include <iostream>

void print(std::string str) {
	std::cout << str << std::endl;
}

int main() {

	BinTree<std::string> tree;
	tree.insert("hello");
	tree.insert("good luck");
	tree.insert("see you");
	tree.insert("enjoy");

	tree.postorder(print);

	return 0;
}