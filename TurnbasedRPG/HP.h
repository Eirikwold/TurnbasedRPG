#pragma once
class HP
{
private:
	int m_hitpoints, m_maxHP, m_powerArmour;

public:

	HP();
	HP(int hitpoints, int powerArmour);

	int getHitpoints();

	HP operator+= (int value);
	HP operator-= (int value);

	friend bool operator== (int value, HP& obj);
	friend bool operator< (int value, HP& obj);
	friend bool operator> (int value, HP& obj);
	friend bool operator<= (int value, HP& obj);
	friend bool operator>= (int value, HP& obj);

	friend bool operator== (HP& obj, int value);
	friend bool operator< (HP& obj, int value);
	friend bool operator> (HP& obj, int value);
	friend bool operator<= (HP& obj, int value);
	friend bool operator>= (HP& obj, int value);

	friend bool operator< (HP& obj1, HP& obj2);
	friend bool operator> (HP& obj1, HP& obj2);
	friend bool operator<= (HP& obj1, HP& obj2);
	friend bool operator>= (HP& obj1, HP& obj2);

	void printHP();
};

