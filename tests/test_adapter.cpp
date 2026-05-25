#include <gtest/gtest.h>
#include <memory>
#include "monster.h"
#include "adapter.h"

TEST(PetAdapterDynamicTest, SlimeAbilities) {
    auto slime = std::make_unique<Slime>();
    PetAdapterDynamic adapter(std::move(slime));
    
    EXPECT_EQ(adapter.Name(), "Slime");
    // Cuteness = Defense - 2*Attack = 20 - 12 = 8
    EXPECT_EQ(adapter.CutenessAbility(), 8);
    // BattleBonus = Attack + Defense/2 = 6 + 10 = 16
    EXPECT_EQ(adapter.BattleBonus(), 16);
}

TEST(PetAdapterDynamicTest, ChangeMonsterWorks) {
    auto slime = std::make_unique<Slime>();
    auto goblin = std::make_unique<Goblin>();
    
    PetAdapterDynamic adapter(std::move(slime));
    auto returned = adapter.ChangeMonster(std::move(goblin));
    
    // Теперь внутри должен быть Goblin
    EXPECT_EQ(adapter.Name(), "Goblin");
    // Cuteness = 10 - 2*30 = -50
    EXPECT_EQ(adapter.CutenessAbility(), -50);
    // BattleBonus = 30 + 10/2 = 35
    EXPECT_EQ(adapter.BattleBonus(), 35);
    
    // Возвращённый монстр – это исходный Slime
    ASSERT_NE(returned, nullptr);
    EXPECT_EQ(returned->Name(), "Slime");
}
