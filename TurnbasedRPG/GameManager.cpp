//STL

// ONE BUG: is listed down below in the check for winner part of the code.
#include <iostream>
#include <string>
#include <vector>
#include <memory>
//Files
#include "GameManager.h"
#include "Character.h"

void GameManager::startGame() {

	//PLAYER COUNT
	std::string m_class, userName, m_type; //Player-class-selection

	int userInput = 0, enemyCount = 0, m_hitpoints = 0, m_powerArmour = 0, userClass = 0,
		m_attack = 0, m_special = 0, m_cooldownSpecial = 0;

	//Numbers of players

	bool outOfBounds = false;
	do { //"Faulty" when putting in char*/string instead of typing integers, can't retype valid input. (Try starting with typing name to break)

		system("CLS");
		std::cout << "Welcome to this turn-based RPG! How many are playing?: " << std::endl;
		std::cin >> userInput;

		if (userInput < 2 || userInput > 5) {

			outOfBounds = true;
			std::cout << "Must be between 2 and 5 players" << std::endl;
			system("PAUSE");
		} else {

			outOfBounds = false;

		}


	} while (outOfBounds);

	do{

		system("CLS");
		std::cout << "How many enemy players do you want?: " << std::endl;
		std::cin >> enemyCount;

		if (enemyCount < 1 || enemyCount > 3) {
			
			outOfBounds = true;
			std::cout << "Must be between 1 and 3 players" << std::endl;
			system("PAUSE");
		
		} else {

			outOfBounds = false;

		}
	} while (outOfBounds);

	//CHARACTER CREATION

	//Player Characters

	characters.reserve(userInput + enemyCount);

	for (int i = 0; i < userInput; i++) {
		system("CLS");

		std::cout << "Whats is your username player " << i + 1 << "?: " << std::endl;
		std::cin >> userName;


		do {

			system("CLS");
			std::cout << "What class will you play?\n 1: Caster\n 2: Infanterist\n 3: Warmonger\n " << std::endl;
			std::cin >> userClass;
		

			if (userClass < 1 || userClass > 3) {

				outOfBounds = true;
				std::cout << "Can only choose between 1 and 3" << std::endl;
				system("PAUSE");
			
			} else {
				outOfBounds = false;
			}
		} while (outOfBounds);


		switch (userClass) {

		case 1:
			m_class = "Caster";
			m_hitpoints = 100;
			m_powerArmour = 5;
			m_attack = 30;
			m_special = 50;
			m_cooldownSpecial = 3;
			break;
		case 2:
			m_class = "Infanterist";
			m_hitpoints = 150;
			m_powerArmour = 10;
			m_attack = 22;
			m_special = 35;
			m_cooldownSpecial = 3;
			break;
		case 3:
			m_class = "Warmonger";
			m_hitpoints = 200;
			m_powerArmour = 15;
			m_attack = 15;
			m_special = 25;
			m_cooldownSpecial = 3;
			break;
		}

		characters.emplace_back(new Character("PLAYER", m_class, HP(m_hitpoints, m_powerArmour), userName,
			m_attack, m_special, m_cooldownSpecial));
	}


		//Get error when not constructing with new keyword, shouldn't need "new" keyword when using emplace_back?

	//Enemy characters

	for (int j = 1; j <= enemyCount; j++) {
		std::string name;
		switch (j) {
		case 1: name = "Maximus";
			break;
		case 2: name = "Spartacus";
			break;
		case 3: name = "Gladius";
			break;
		}
		characters.emplace_back(new Character("COMPUTER", "Gladiator", HP(110, 5), name, 18, 25, 3));
	}

	//Print Characters "CHECK"

	system("CLS");
	viewCharacters();
	std::cout << "CHARACTERS: " << characters.size() << std::endl;

}


void GameManager::viewCharacters() {
	int i = 0;

	for (auto& GameManager : characters) {
		characters[i]->printStats();
		i++;
	}
}


void GameManager::run() {

	bool gameOver = false;

	while (!gameOver) {
		int characterIndex = 0;


		// NOT "fool-proof" method for target selection
		for (auto& GameManager : characters) {
			
			bool invalidAction = false;

			system("CLS");
			viewCharacters();
			int inputTarget = 0;
			int inputAttack = 0;

			if (characters[characterIndex]->getType() == "PLAYER") {
				do{

					std::cout << "It is " << characters[characterIndex]->getName() << "'s turn" << std::endl;
					std::cout << "Who do you want to attack?" << std::endl;
					int j = 0;

					for (auto& GameManager : characters) {

						std::cout << j + 1 << ": " << characters[j]->getName() << std::endl;
						j++;
					}
						std::cin >> inputTarget;
						
						inputTarget--;

						if ((inputTarget < 0 || inputTarget >= characters.size()) || inputTarget == characterIndex) {
							invalidAction = true;
							std::cout << "Invalid target: Target has to exist, and cannot be yourself." << std::endl;
							system("PAUSE");

						} else {
							invalidAction = false;
						}

				

				} while (invalidAction);

					do {
						std::cout << "Choose your attack: " << std::endl;
						std::cout << "1: Attack (" << characters[characterIndex]->getAttack() << " damage)" << std::endl;
						std::cout << "2: Special attack (" << characters[characterIndex]->getSpecial() << " damage): ";

						if (characters[characterIndex]->isReady()) {
							std::cout << "Available" << std::endl;
						}
						else {
							std::cout << "Available in : " << characters[characterIndex]->getCD() << " turns." << std::endl;
						}

						std::cin >> inputAttack;


						// Attack out of bounds check, and special attack CD check
						if (inputAttack < 1 || inputAttack > 2) {
							invalidAction = true;
							std::cout << "Can only choose between 1 or 2" << std::endl;
							system("PAUSE");

						} else if (inputAttack == 2 && characters[characterIndex]->getCD() > 0) {
								std::cout << "Special attack isn't ready yet, wait for: " << characters[characterIndex]->getCD() << " turns." << std::endl;
								invalidAction = true;
								system("PAUSE");
						} else {
							invalidAction = false;
						}

					} while (invalidAction);

			} else {


				do {
					int computerTargets = characters.size();
					inputTarget = rand() % computerTargets + 1;
					inputTarget--;


					if (inputTarget == characterIndex) {
						invalidAction = true;
					}
					else {
						invalidAction = false;
					}
				} while (invalidAction);

				if (characters[characterIndex]->isReady()) {
					inputAttack = 2;
				}
				else {
					inputAttack = 1;
				}

			}


			// Attacks
			switch (inputAttack) {


			case 1:
				characters[characterIndex]->getAttack();
				characters[inputTarget]->p_hp -= characters[characterIndex]->getAttack();
				std::cout << characters[characterIndex]->getName() << " Used normal attack on: "
					<< characters[inputTarget]->getName() << " and dealt " << characters[characterIndex]->getAttack() << " damage." << std::endl;
				break;
			case 2:
				characters[characterIndex]->getSpecial();
				characters[inputTarget]->p_hp -= characters[characterIndex]->getSpecial();
				std::cout << characters[characterIndex]->getName() << " Used Special attack on: "
					<< characters[inputTarget]->getName() << " and dealt " << characters[characterIndex]->getSpecial() << " damage." << std::endl;

				characters[characterIndex]->setCD(characters[characterIndex]->getCDMax());
				break;
			}
			system("PAUSE");


			//Reduces cooldown on special attack;
			if (characters[characterIndex]->getCD() > 0) {
				characters[characterIndex]->setCD(characters[characterIndex]->getCD() - 1);
			}

			int eraseCheck = 0;



			/* HAVE ONE KNOWN BUG:
				* Atleast players cannot win the game without it crashing when finishing a player with lower index. I reckon the fault stems from
				  the code below, but couldn't figure it out.
				  ** Might also stem from the dowhile() where "inputTarget--" is called, making index negative for last run-through. But i'm not sure.
			*/
			//Cleans the trash to find the diamond
			for (auto& GameManager : characters) {

				if (characters[eraseCheck]->p_hp == 0) {
					characters.erase(characters.begin() + eraseCheck);

					if (characters.size() == 1) {
						std::cout << "The winner is: " << characters[characterIndex]->getName() << "!" << std::endl;
						gameOver = true;

						if (eraseCheck < characterIndex) {
							characterIndex--; //Reduce "i" if you erase a lower index than current character
						}
					}
					if (eraseCheck < characterIndex) {
						characterIndex--;
					}
					else if (eraseCheck < characterIndex) {
						continue;
					}
					else {
						characterIndex++; //Increase "i" if you erase a higher index than current character
					}

					break;

				}
				else {
					if (characters.size() == eraseCheck + 1) {
						characterIndex++;

					}

				}
				eraseCheck++;
			}

			if (gameOver || characters.size() == characterIndex) {
				break;
			}
		}
	}
}