#pragma once
#include <string>

class Monster {
public:
    virtual ~Monster() = default;
    virtual std::string Name() const = 0;
    virtual int AttackAbility() const = 0;
    virtual int DefenseAbility() const = 0;
};

class Slime : public Monster {
public:
    std::string Name() const override { return "Slime"; }
    int AttackAbility() const override { return 6; }
    int DefenseAbility() const override { return 20; }
};

class Goblin : public Monster {
public:
    std::string Name() const override { return "Goblin"; }
    int AttackAbility() const override { return 30; }
    int DefenseAbility() const override { return 10; }
};

class Dragon : public Monster {
public:
    std::string Name() const override { return "Dragon"; }
    int AttackAbility() const override { return 1000; }
    int DefenseAbility() const override { return 500; }
};
