#pragma once
#include <memory>
#include <type_traits>
#include "monster.h"
#include "pet.h"

// Статический адаптер (шаблон)
template <typename MonsterType,
          typename = std::enable_if_t<std::is_base_of<Monster, MonsterType>::value>>
class PetAdapterStatic : public Pet {
public:
    std::string Name() const override { return monster_.Name(); }
    int CutenessAbility() const override { return monster_.DefenseAbility() - 2 * monster_.AttackAbility(); }
    int BattleBonus() const override { return monster_.AttackAbility() + monster_.DefenseAbility() / 2; }

private:
    MonsterType monster_;
};

// Динамический адаптер (композиция с unique_ptr)
class PetAdapterDynamic : public Pet {
public:
    explicit PetAdapterDynamic(std::unique_ptr<Monster>&& monster)
        : monster_(std::move(monster)) {}

    std::unique_ptr<Monster> ChangeMonster(std::unique_ptr<Monster>&& monster) {
        std::unique_ptr<Monster> returnedMonster = std::move(monster_);
        monster_ = std::move(monster);
        return returnedMonster;
    }

    std::string Name() const override { return monster_->Name(); }
    int CutenessAbility() const override { return monster_->DefenseAbility() - 2 * monster_->AttackAbility(); }
    int BattleBonus() const override { return monster_->AttackAbility() + monster_->DefenseAbility() / 2; }

private:
    std::unique_ptr<Monster> monster_;
};
