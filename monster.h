#ifndef MONSTER_H
#define MONSTER_H



#include "citizen.h"

template <typename T>
class Monster {
	T h, aP;
public:
	Monster(T health, T attackPower):
	h(health), aP(attackPower) {}
	T getHealth() const { return h; }
	T getAttackPower() const { return aP; }
	void takeDamage(T damage) {
		if (h > damage) {
			h -= damage;
		}
		else {
			h -= h;
		}
	}
};

template <typename T>
using Zombie = Monster<T>;

template <typename T>
using Mummy = Monster<T>;

template <typename T>
using Vampire = Monster<T>;

template <typename M, typename U>
void attack(M &monster, U &victim) {
	victim.takeDamage(monster.getAttackPower());
}


template <typename M, typename U, typename T>
//Tutaj T trzeba jakoś z U wyciągnąć
void attack(M &monster, Sheriff<T> &victim) {
	victim.takeDamage(monster.getAttackPower());
	monster.takeDamage(victim.getAttackPower());
}

#endif //MONSTER_H