///@author: Savannah Bolger
///@student no: C00215747
///@date: 15/10/2017

#include <iostream>
#include <ctime>


class Character
{
public:
	//Character dialogue
	virtual void welcome() = 0;
	virtual void attack1() = 0;
	virtual void attack2() = 0;
	virtual void magic() = 0;
	virtual void shields() = 0;
};

class Orc : public Character
{
public:
	//Orc species player welcome
	void welcome() { std::cout << "The Orcs will rise!!" << std::endl; }
	//Orc Battle Cries
	void attack1() { std::cout << "Take That!!" << std::endl; }
	void attack2() { std::cout << "Your no match for me!!" << std::endl; }
	//Orc Magic
	void magic() { std::cout << "1: Disruption\n2: Dragon Breath\n3: Firearow\n4: Heal\n5: Fate" << std::endl; }
	//Orc Shields
	void shields() { std::cout << "1: Wooden Shield\n2: Bronze Shield\n3: Iron Shield" << std::endl; }
	
};

class Troll : public Character
{
public:
	//Troll species player welcome
	void welcome() { std::cout << "Trolls will crush all enemies!!" << std::endl; }
	//Troll Battle Cries
	void attack1() { std::cout << "This is for all Trolls!!" << std::endl; }
	void attack2() { std::cout << "Your no match for my strength!!" << std::endl; }
	//Troll Magic
	void magic() { std::cout << "1: Disruption\n2: Dragon Breath\n3: Firearow\n4: Heal\n5: Fate" << std::endl; }
	//Troll Shields
	void shields() { std::cout << "1: Wooden Shield\n2: Bronze Shield\n3: Iron Shield" << std::endl; }
};


void game(Character *orc, Character *troll)
{
	//whether game is over or not
	bool gameover = false;
	//whether player turn or not
	bool playerTurn = false;
	//has player chosen a species
	bool playerChosen = false;
	//has the player and enemy equiped a shield 
	bool equipShield = false;
	bool enemyEquipShield = false;
	//is the player or enemy fate link activated or not
	bool fateLink = false;
	bool enemyFateLink = false;
	//player and enemy health
	int health = 50;
	int enemyHealth = 50;
	//player and enemy sheild
	int shield = -1;
	int enemyShield = -1;
	//player and enemy defense due to shield
	int defense = -1;
	int enemyDefense = -1;
	//player's chosen a side
	int playerSide = -1;
	int player = -1;
	int enemy = -1;
	//pointer to pointer for speech
	Character **character[2];
	character[0] = &orc;
	character[1] = &troll;

	//if player hasn't chosen a side then this if statment will be executed
	if (!playerChosen)
	{
		std::cout << "1: Orc\n2: Troll" << std::endl;
		std::cout << "Choose a side: ";
		std::cin >> playerSide;

		//chosen side will be put into a switch statement
		switch (playerSide)
		{
		case 1:
			//if player enters #1 then the player will be an Orc
			player = playerSide - 1;
			enemy = playerSide;
			(**character[player]).welcome();
			std::cout << "------------------------------" << std::endl;
			playerTurn = true;
			break;
		case 2:
			//if player enters #1 then the player will be an Troll
			player = playerSide - 1;
			enemy = playerSide - 2;
			(**character[player]).welcome();
			std::cout << "------------------------------" << std::endl;
			playerTurn = true;
			break;
		default:
			//if player enters any other number then the player will default to an Orc
			playerSide = 1;
			player = playerSide - 1;
			enemy = playerSide; 
			(**character[player]).welcome();
			std::cout << "------------------------------" << std::endl;
			playerTurn = true;
			break;
		}
	}

	//game will continue until gameover == true
	while (gameover == false)
	{
		//is it the player's turn
		//if so this if statement will be executed
		if (playerTurn)
		{
			//has the player's chosen a shield
			//if not this if statement will be executed
			if (!equipShield)
			{
				int enemyHealth = 50;

				(**character[player]).shields();
				std::cout << "Choose a shield: ";
				std::cin >> shield;
				//chosen shield will be put into a switch statement
				switch (shield)
				{
				case 1:
					//if player enters #1 the shield will be a wooden shield
					shield = 10;
					defense = 1;
					std::cout << "Chosen wooden shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					equipShield = true;
					break;
				case 2:
					//if player enters #2 the shield will be a bronze shield
					shield = 30;
					defense = 3;
					std::cout << "Chosen bronze shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					equipShield = true;
					break;
				case 3:
					//if player enters #3 the shield will be a iron shield
					shield = 50;
					defense = 5;
					std::cout << "Chosen iron shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					equipShield = true;
					break;
				default:
					//if player enters any other number then the player's shield will default to an iron shield
					shield = 50;
					defense = 5;
					std::cout << "Chosen iron shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					equipShield = true;
					break;
				}
			}

			//magic attacks
			int magic = -1;
			int attack = -1;
			int attackMessage = -1;
			int fate = -1;

			//attle cries will be random
			srand((int)(time(NULL)));
			attackMessage = rand() % 4 + 1;
			(**character[player]).magic();
			std::cout << "Choose a magic: ";
			std::cin >> magic;
			//chosen spell will be put into a switch statement
			switch (magic)
			{
			case 1:
				//if player enters #1 the spell will be a discruption spell
				attack = 5;
				enemyShield -= attack;
				attack -= defense;
				enemyHealth -= attack;
				std::cout << "Chosen a discruption spell!" << std::endl;
				if (attackMessage == 1 || attackMessage == 3)
				{
					(**character[player]).attack1();
				}
				else
				{
					(**character[player]).attack2();
				}
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = false;
				break;
			case 2:
				//if player enters #2 the spell will be a dragon breath spell
				attack = 10;
				enemyShield -= attack;
				attack -= defense;
				enemyHealth -= attack;
				std::cout << "Chosen a dragon breath spell!" << std::endl;
				if (attackMessage == 1)
				{
					(**character[player]).attack1();
				}
				else
				{
					(**character[player]).attack2();
				}
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = false;
				break;
			case 3:
				//if player enters #3 the spell will be a firearrow spell
				attack = 15;
				enemyShield -= attack;
				attack -= defense;
				enemyHealth -= attack;
				std::cout << "Chosen a firearrow spell!" << std::endl;
				if (attackMessage == 1)
				{
					(**character[player]).attack1();
				}
				else
				{
					(**character[player]).attack2();
				}
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = false;
				break;
			case 4:
				//if player enters #4 the spell will be a healing spell
				health += 5;
				if (health >= 50)
				{
					health = 50;
				}
				std::cout << "Chosen a heal spell!" << std::endl;
				std::cout << "I feel better already!" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = false;
				break;
			case 5:
				//if player enters #3 the spell will be a fate spell
				fate++;
				std::cout << "Chosen a fate spell!" << std::endl;
				//fate spell wears off if the fate equals 4
				if (fate == 4)
				{
					std::cout << "Your fate link has woren off!" << std::endl;
					fateLink = false;
					fate = -1;
				}
				else
				{
					std::cout << "Your fate has been linked to the enemies!" << std::endl;
					fateLink = true;

				}
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = false;
				break;
			default:
				//if player enters any other number the spell will default to a discruption spell
				attack = 5;
				enemyShield -= attack;
				attack -= defense;
				enemyHealth -= attack;
				std::cout << "Chosen a discruption spell!" << std::endl;
				if (attackMessage == 1 || attackMessage == 3)
				{
					(**character[player]).attack1();
				}
				else
				{
					(**character[player]).attack2();
				}
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = false;
				break;
			}

			//if the fate link is activated it updates every turn
			if (fateLink)
			{
				fate++;
			}
			//if you die and the fate link is active you can kill your enemy
			else if (fateLink == true && health == 0)
			{
				std::cout << "I've failed but at least I can take you down with me!!" << std::endl;
				enemyHealth = 0;
			}			

			if (shield <= 0)
			{
				std::cout << "Dammit! My shield has been broken" << std::endl;
			}

			if (health <= 0)
			{
				std::cout << "Ugh! I have failed my people!!" << std::endl;
				std::cout << "GAMEOVER!!" << std::endl;
				gameover = true;
				break;
			}
		}
		else
		{
			srand((int)(time(NULL)));
			//has the enemy's chosen a shield
			//if not this if statement will be executed
			if (!enemyEquipShield)
			{
				int enemyHealth = 50;
				//enemy's shield is random
				enemyShield = rand() % 3 + 1;
				//chosen shield will be put into a switch statement
				switch (enemyShield)
				{
				case 1:
					enemyShield = 10;
					enemyDefense = 1;
					std::cout << "------------------------------" << std::endl;
					enemyEquipShield = true;
					break;
				case 2:
					enemyShield = 30;
					enemyDefense = 3;
					std::cout << "The enemy has chosen bronze shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					enemyEquipShield = true;
					break;
				case 3:
					enemyShield = 50;
					enemyDefense = 5;
					std::cout << "The enemy has chosen iron shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					enemyEquipShield = true;
					break;
				default:
					enemyShield = 50;
					enemyDefense = 5;
					std::cout << "The enemy has chosen iron shield!" << std::endl;
					std::cout << "------------------------------" << std::endl;
					equipShield = true;
					break;
				}
			}

			//enemy magic
			int enemyMagic = -1;
			int enemyAttack = -1;
			int enemyFate = -1;
			
			//enemy's spells will be random
			enemyMagic = rand() % 5 + 1;
			//chosen spell will be put into a switch statement
			switch (enemyMagic)
			{
			case 1:
				//if player enters #1 the spell will be a discruption spell
				enemyAttack = 5;
				shield -= enemyAttack;
				enemyAttack -= defense;
				health -= enemyAttack;
				std::cout << "The enemy has chosen a discruption spell!" << std::endl;
				
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = true;
				break;
			case 2:
				//if player enters #2 the spell will be a dragon breath spell
				enemyAttack = 10;
				shield -= enemyAttack;
				enemyAttack -= defense;
				health -= enemyAttack;
				std::cout << "The enemy has chosen a dragon breath spell!" << std::endl;
				
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = true;
				break;
			case 3:
				//if player enters #3 the spell will be a firearrow spell
				enemyAttack = 15;
				shield -= enemyAttack;
				enemyAttack -= defense;
				health -= enemyAttack;
				std::cout << "The enemy has chosen a firearrow spell!" << std::endl;
				
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = true;
				break;
			case 4:
				//if player enters #4 the spell will be a healing spell
				enemyHealth += 5;
				if (enemyHealth >= 50)
				{
					enemyHealth = 50;
				}
				std::cout << "The enemy has chosen a heal spell!" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = true;
				break;
			case 5:
				//if player enters #5 the spell will be a fate spell
				enemyFate++;
				std::cout << "The enemy has chosen a fate spell!" << std::endl;
				if (enemyFate == 4)
				{
					std::cout << "Your fate link has woren off!" << std::endl;
					enemyFateLink = false;
					enemyFate = 0;
				}
				else
				{
					std::cout << "Your fate has been linked to the enemies!" << std::endl;
					enemyFateLink = true;

				}
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = true;
				break;
			default:
				//if player enters any other number the spell will default to a discruption spell
				enemyAttack = 5;
				shield -= enemyAttack;
				enemyAttack -= defense;
				health -= enemyAttack;
				std::cout << "The enemy has chosen a discruption spell!" << std::endl;
				
				std::cout << "------------------------------" << std::endl;
				std::cout << "Player Health: " << health << "\nEnemy Health: " << enemyHealth << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				std::cout << "------------------------------" << std::endl;
				playerTurn = true;
				break;
			}

			//if the enemy fate link is activated it updates every turn
			if (enemyFateLink)
			{
				enemyFate++;
			}
			//if the enemy dies and the enemy's fate link is active you can die
			else if (enemyFateLink == true && enemyHealth <= 0)
			{
				std::cout << "I've failed but at least I can take you down with me!!" << std::endl;
			}

			//if the enemy shiels's endurance wears down it can be broken
			if (enemyShield <= 0)
			{
				std::cout << "Great! The enemy's shield has been broken" << std::endl;
			}

			//if the enemy's health equals zero then you win the game
			if (enemyHealth <= 0)
			{
				std::cout << "Congratulations!!" << std::endl;
				std::cout << "After centuries of fitting the war is finally over!!" << std::endl;
				std::cout << "You Win!!" << std::endl;
				std::cout << "Your name will go down in history!!" << std::endl;
				gameover = true;
			}
		}

	}
	
}
int main(void)
{
	std::cout << "Welcome to Orcs Versus Trolls" << std::endl;
	std::cout << "The war between the Orcs and the Trolls has continued on for centuries!!" << std::endl;
	std::cout << "It is up to you to defeat the Leader of the Enemy!!" << std::endl;
	std::cout << std::endl;

	Character *orc = &Orc();
	Character *troll = &Troll();

	game(orc, troll);


	system("pause");
}


