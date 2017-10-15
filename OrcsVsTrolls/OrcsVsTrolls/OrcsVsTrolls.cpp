///@author: Savannah Bolger
///@student no: C00215747
///@date: 15/10/2017

#include <iostream>


class Character
{
public:
	void flip() { std::cout << "I know how to flip and I will flipping do it" << std::endl; }
	virtual void walk() { std::cout << "just in case they are too young to walk yet" << std::endl; }
	virtual void fly() = 0; //pure virtual function
};

class Orc : public Character
{
public:
	void barrelRoll() { std::cout << "rooooooollllllllllinggggggg" << std::endl; }
	void walk() { std::cout << "Doopers have a really cool walk!" << std::endl; }
	void fly() { std::cout << "Dooper is flapping and flying" << std::endl; }
};

class Troll : public Character
{
public:
	void fly() { std::cout << "Average Dooper is flapping and flying" << std::endl; }
};

int main(void)
{
	std::cout << "Let go virtual" << std::endl;
	//Character character;
	//character.flip();
	//character.walk();

	std::cout << "Let go create an Orc" << std::endl;
	Orc orc;
	orc.walk();
	orc.fly();
	orc.flip();

	std::cout << "Let go ceate an Troll" << std::endl;
	Troll troll;
	troll.walk();
	troll.fly();
	troll.flip();

	Character* npc = &orc;
	npc->flip();
	npc->fly();
	npc->walk();

	npc = &troll;
	npc->flip();
	npc->fly();
	npc->walk();

	std::cin.get();
}