#include "bintree.hpp"
#include <iostream>

class Player {
public:
	Player() {}
	Player(std::string name, int age) {
		this->name = name;
		this->age = age;
	}

	// Operators == and < must be overloaded.
	bool operator ==(Player obj) {
		return this->age == obj.age;
	}

	bool operator <(Player obj) {
		return this->age < obj.age;
	}

	std::string name;
	int age;
};

void print(Player obj) {
	std::cout << obj.name << " " << obj.age << std::endl;
}

int main() {

	BinTree<Player> tree;

	Player player1("Lionel Messi", 32);
	Player player2("Robert Lewandowski", 30);
	Player player3("Cristiano Ronaldo", 34);

	tree.insert(player1);
	tree.insert(player2);
	tree.insert(player3);

	tree.postorder(print);


	return 0;
}