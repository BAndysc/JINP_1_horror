template <typename T, char x>
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

/*
template <typename T, 'z'>
class Zombie { };

template <typename T, 'z'>
class Mummy { };

template <typename T, 'z'>
class Vampire { };
*/
template <typename M, typename U>
void attack(M monster, U victim) {
	victim.takeDamage(monster.getAttackPower());
	defend(monster, victim);
}


template <typename M, typename U>
void defend(M monster, U victim) { }

template <typename M>
void defend(M monster, Sheriff<T> victim) {
	moster.takeDamage(victim.getAttackPower());
}
