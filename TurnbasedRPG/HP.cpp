#include "HP.h"
#include <iostream>


//Constructors

HP::HP() : m_hitpoints(), m_powerArmour(), m_maxHP(){}

HP::HP(int hitpoints, int powerArmour) {
	this->m_hitpoints = hitpoints;
	this->m_powerArmour = powerArmour;
	this->m_maxHP = m_hitpoints;
}

HP HP::operator+=(int value) {
	HP hp;
	
	while (value < 0 && m_hitpoints != m_maxHP) {
		m_hitpoints++;
		value++;
	}
	return hp;
}

//Regular functions

void HP::printHP() {
	std::cout << "HP: " << m_hitpoints << "/" << m_maxHP << std::endl;
	std::cout << "Armour: " << m_powerArmour << std::endl;
}

int HP::getHitpoints() {
	return m_hitpoints;
}	


// OPERATOR OVERLOADING

HP HP::operator-=(int value) {
	HP hp;
	int m_tempPA = m_powerArmour;

	while (value != 0 && m_tempPA != 0) {
		m_tempPA--;
		value--;
	}

	while (value != 0 && m_hitpoints != 0) {
		m_hitpoints--;
		value--;
	}
	return hp;
}

bool operator == (int value, HP& obj) {
	if (value == obj.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator < (int value, HP& obj) {
	if (value < obj.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator > (int value, HP& obj) {
	if (value > obj.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator >= (int value, HP& obj) {
	if (value >= obj.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator <= (int value, HP& obj) {
	if (value <= obj.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

// Turned

bool operator <= (HP& obj, int value) {
	if (obj.m_hitpoints <= value) {
		return true;
	}
	else {
		return false;
	}
}

bool operator >= (HP& obj, int value) {
	if (obj.m_hitpoints >= value) {
		return true;
	}
	else {
		return false;
	}
}

bool operator < (HP& obj, int value) {
	if (obj.m_hitpoints < value) {
		return true;
	}
	else {
		return false;
	}
}

bool operator > (HP& obj, int value) {
	if (obj.m_hitpoints < value) {
		return true;
	}
	else {
		return false;
	}
}

bool operator == (HP& obj, int value) {
	if (obj.m_hitpoints == value) {
		return true;
	}
	else {
		return false;
	}
}


// OBJECT TO OBJECT

bool operator <= (HP& obj1, HP& obj2) {
	if (obj1.m_hitpoints <= obj2.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator >= (HP& obj1, HP& obj2) {
	if (obj1.m_hitpoints >= obj2.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator < (HP& obj1, HP& obj2) {
	if (obj1.m_hitpoints < obj2.m_hitpoints) {
		return true;
	}
	else {
		return false;
	}
}

bool operator > (HP& obj1, HP& obj2) {
	if (obj1.m_hitpoints > obj2) {
		return true;
	}
	else {
		return false;
	}
}



