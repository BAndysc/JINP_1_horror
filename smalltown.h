#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include <iostream>
#include <tuple>
#include <cassert>

template <typename M, typename U, U TIME_START, U TIME_END, typename... C>
class SmallTown {

	M monster;
	U time;
	std::tuple<C...> citizens;
	size_t aliveCitizens;

public:
	SmallTown(M const& _monster, C... _citizens) : monster(_monster), time(TIME_START) {
		citizens = std::tuple<C...>(_citizens...);
		aliveCitizens = sizeof...(_citizens);
	}

	std::tuple<std::string, typename M::valueType, size_t> getStatus() {
		return std::make_tuple(monster.getName(), monster.getHealth(), 0);
	}

	void tick(U timeStep) {
		// gdy trzeba zaatakować, należy użyć:
		// attackAll();
		// computeResult();
	}

private:

	bool isMonsterDead() const {
		return monster.getHealth() == 0;
	}

	void computeResult() {
		if (isMonsterDead()) {
			if (aliveCitizens == 0)
				std::cout << "DRAW\n";
			else
				std::cout << "CITIZENS WON\n";
		} else if (aliveCitizens == 0)
			std::cout << "MONSTER WON\n";
	}

	void attackAll() {
		attackAllHelper<0, C...>();
	}

	template<size_t N>
	void attackOne() {
		auto& citizen = std::get<N>(citizens);

		if (citizen.getHealth() > 0) {
			attack(monster, citizen);
			if (citizen.getHealth() == 0)
				--aliveCitizens;
		}

	}

	template <int>
	void attackAllHelper() { }

	template <int,typename Arg,typename...Args>
	void attackAllHelper() {
		attackAllHelper<0, Args...>();
		attackOne<sizeof...(Args)>();
	}
};

#endif