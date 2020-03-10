#pragma once
#include <string>
#include <vector>
#include "Character.h"
#include <memory>
#include <time.h>
#include <stdlib.h>

class GameManager
{
private:
	std::vector<std::unique_ptr<Character>> characters;
	std::vector<std::unique_ptr<Character>>::iterator iterator;

public:
	void startGame();
	void run();
	void viewCharacters();
};
