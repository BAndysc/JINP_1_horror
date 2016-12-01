#include "citizen.h"
#include "monster.h"
#include "smalltown.h"
#include <iostream>
#include <cassert>

constexpr auto abl = make_array<how_many_fib(13)>(nTh);


using namespace std;

int main() {
	auto smallTown = SmallTown<Zombie<float>, int, 1, 23, Sheriff<int>, Adult<int>, Teenager<long>>(
			Zombie<float>(100.0f, 1.5f),
			Sheriff<int>(100, 35, 20),
			Adult<int>(100, 21),
			Teenager<long>(50, 14)
	);

	for(int x : abl)
		std::cout << x << " ";

	smallTown.tick(8);
	//smallTown.tick(22);

	/*auto status = smallTown.getStatus();
	assert(get<0>(status) != "");
	assert(get<1>(status) == 60);
	assert(get<2>(status) == 3);
*/
	Mummy<float> m(100.0f, 2.0f);
	Sheriff<int> s(100, 35, 20);
	Adult<int> a(100, 20);

	//A b = 12;

	attack(m, s);
	attack(m, a);

	assert(m.getHealth() == 80);
	assert(s.getHealth() == 98);
	assert(a.getHealth() == 98);
	return 0;
}
