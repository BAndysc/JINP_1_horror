template <typename T, char x>
class Citizen {
	T h, aP;
public:
	Citizen(T health, T attackPower):
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
class Sheriff {
	T h, aP;
public:
	Sheriff(T health, T attackPower):
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

