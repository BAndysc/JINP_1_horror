#ifndef CITIZEN_H
#define CITIZEN_H

#include <cassert>
#include <type_traits>


struct YES { constexpr static bool value = true; };
struct NO { constexpr static bool value = false; };

template<typename T, T MIN_AGE, T MAX_AGE, typename CAN_SHOOT>
class Citizen {

    T health, age, attackPower;

public:

    Citizen() { }


    template<typename U = CAN_SHOOT>
    Citizen(T _health, T _age,  typename std::enable_if<!U::value>::type* = 0)
            : health(_health), age(_age) {
        assert(age >= MIN_AGE && age <= MAX_AGE);
    }

    template<typename U = CAN_SHOOT>
    Citizen(T _health, T _age, T _attackPower, typename std::enable_if<U::value>::type* = 0)
            : health(_health), age(_age), attackPower(_attackPower) {
        assert(age >= MIN_AGE && age <= MAX_AGE);
    }

    T getHealth() const { return health; }

    T getAge() const { return age; }


    template<typename U = CAN_SHOOT>
    T getAttackPower(typename std::enable_if<U::value>::type* = 0) const { return attackPower; }

    void takeDamage(T damage) {
        if (health > damage)
            health -= damage;
        else
            health -= health;
    }
};

template<typename T>
using Teenager = Citizen<T, 11, 17, NO>;

template<typename T>
using Adult = Citizen<T, 18, 100, NO>;

template<typename T>
using Sheriff = Citizen<T, 18, 100, YES>;


#endif //CITIZEN_H