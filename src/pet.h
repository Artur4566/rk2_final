#pragma once
#include <string>

class Pet {
public:
    virtual ~Pet() = default;
    virtual std::string Name() const = 0;
    virtual int CutenessAbility() const = 0;
    virtual int BattleBonus() const = 0;
};

class Puppy : public Pet {
public:
    std::string Name() const override { return "Puppy"; }
    int CutenessAbility() const override { return 50; }
    int BattleBonus() const override { return 5; }
};

class Cat : public Pet {
public:
    std::string Name() const override { return "Cat"; }
    int CutenessAbility() const override { return 40; }
    int BattleBonus() const override { return 10; }
};
