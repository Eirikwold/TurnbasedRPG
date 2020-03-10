#pragma once
#include <string>
#include "HP.h"
class Character
{

private:
	int m_attack, m_special, m_cooldownSpecial, m_cooldownSpecialMax;
	std::string m_name, m_class, m_type;



public:
	HP p_hp; // Public HP

	Character() = delete;
	Character(std::string type, std::string userClass, const HP& hp, std::string name, int attack,
		int special, int cooldownSpecial);
	~Character();

	// Functions

	std::string getName();
	std::string getType();
	

	bool isReady();
	
	// Getters
	int getAttack();
	int getSpecial();

	int getCD();
	int getCDMax();

	//Setter
	void setCD(int value);


	void printStats();



};

