//
// Created by Мхитарян Нарек on 18.03.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_TESTS_H
#define MY_FIRST_REAL_STRATEGY_TESTS_H
#pragma once
#include <gtest/gtest.h>
#include "human_tree.h"
#include "squad.h"
TEST(Unit, small_mecha_param)
{
    small_mecha *a = new small_mecha;
    int b = a->get_cost();
    int c = a->get_healthy();
    EXPECT_EQ(50, b);
    EXPECT_EQ(10, c);
    delete a;
}

TEST(Unit_big, armor_mecha_param)
{
    armored_mecha* key = new armored_mecha;
    int a = key->get_cost();
    int b = key->get_speed();
    EXPECT_EQ(100, a);
    EXPECT_EQ(10, b);
    delete key;
}

TEST(Hard_air, air_factory)
{
    auto *expert = new human_air_factory;
    int a = expert->get_price();
    auto b = expert->build_bomber();
    auto c = expert->build_fighter();
    auto d = expert->build_engineer();
    int price_of_bomber = b->get_cost();
    int speed_of_fighter = c->get_speed();
    int speed_of_building = d->get_speed_of_engineer();
    EXPECT_EQ(75, price_of_bomber);
    EXPECT_EQ(40, speed_of_fighter);
    EXPECT_EQ(400, a);
    EXPECT_EQ(10, speed_of_building);
    delete b;
    delete c;
    delete d;
    delete expert;

}

TEST(Hard_surface, surface_factory)
{
    auto *control_factory = new human_surface_factory;
    auto test_1 = control_factory->build_engineer();
    auto test_3 = control_factory->build_armor_unit();
    auto test_4 = control_factory->build_fast_unit();
    auto test_5 = control_factory->build_scout();
    int price_of_engineer = test_1->get_cost();
    int speed_of_armor_unit = test_3->get_speed();
    int price_of_fast_unit = test_4->get_cost();
    int speed_of_scout = test_5->get_speed();
    EXPECT_EQ(30, price_of_engineer);
    EXPECT_EQ(10, speed_of_armor_unit);
    EXPECT_EQ(50, price_of_fast_unit);
    EXPECT_EQ(25, speed_of_scout);
    delete test_1;
    delete test_3;
    delete test_4;
    delete test_5;
    delete control_factory;
}

TEST(Squad, squad_units)
{
    unit_war* f = new human_air_fighter;
    squad w;
    w.add(f);
    EXPECT_EQ(1, w.get_number());
}

#endif //MY_FIRST_REAL_STRATEGY_TESTS_H