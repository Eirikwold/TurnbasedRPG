#include "Character.h"
#include "HP.h"
#include <iostream>

Character::Character(std::string type, std::string userClass, const HP& hp, std::string name,
	int attack, int special, int cooldownSpecial) :
	m_type(type), m_name(name), m_class(userClass), p_hp(hp),
	m_attack(attack), m_special(special), m_cooldownSpecial(cooldownSpecial) {

	this->m_cooldownSpecialMax = m_cooldownSpecial;

}

Character::~Character() {

}



void Character::printStats() {
	std::cout << "==============================" << std::endl;
	std::cout << m_type << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Class: " << m_class << std::endl;
	p_hp.printHP();
	std::cout << "==============================\n" << std::endl;
}

std::string Character::getName() {
	return m_name;
}

std::string Character::getType() {
	return m_type;
}

int Character::getAttack() {
	return m_attack;
}

int Character::getSpecial() {
	return m_special;
}

int Character::getCD() {
	return m_cooldownSpecial;
}

int Character::getCDMax() {
	return m_cooldownSpecialMax;
}

void Character::setCD(int value) {
	m_cooldownSpecial = value;
}


bool Character::isReady() {
	if (m_cooldownSpecial == 0) {
		return true;
	} else {
		return false;
	}
}


