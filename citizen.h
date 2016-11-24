#ifndef CITIZEN_H
#define CITIZEN_H


template <typename T, T, T>
class Citizen {
	T h, a;
public:
	Citizen(T health, T age):
	h(health), a(age) {}
	T getHealth() const { return h; }
	T getAge() const { return a; }
	void takeDamage(T damage) {
		if (h > damage) {
			h -= damage;
		}
		else {
			h = 0;
		}
	}
};

template <typename T>
using Teenager = Citizen <T, 11, 17>;

template <typename T>
using Adult = Citizen <T, 18, 100>;

//Szeryfa inaczej trzeba ogarnąć
template <typename T>
class Sheriff {
	T h, a, aP;
public:
	Sheriff(T health, T age, T attackPower):
	h(health), a(age), aP(attackPower) {}
	T getHealth() const { return h; }
	T getAge() const { return a; }
	T getAttackPower() const { return aP; }
	void takeDamage(T damage) {
		if (h > damage) {
			h -= damage;
		}
		else {
			h = 0;
		}
	}
};

#endif //CITIZEN_H