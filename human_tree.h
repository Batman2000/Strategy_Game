//
// Created by Мхитарян Нарек on 16.03.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_HUMAN_TREE_H
#define MY_FIRST_REAL_STRATEGY_HUMAN_TREE_H
#pragma once
#include "main_lib.h"
#include <thread>
class small_mecha: public unit_war{
public:
    small_mecha()
    {
        set_health(10);
        set_power(15);
        set_speed(20);
        set_cost(50);
    }
    void get_health()
    {
        std::cout << health;
    }
    int get_healthy()
    {
        return health;
    }
    ~small_mecha() = default;

};

class armored_mecha: public unit_war{
public:
    armored_mecha()
    {
        set_health(20);
        set_power(25);
        set_speed(10);
        set_cost(100);
    }
    ~armored_mecha() = default;
};

class fast_scout: public unit_war{
public:
    fast_scout()
    {
        set_health(10);
        set_power(5);
        set_speed(25);
        set_cost(30);
    }
    ~fast_scout() = default;
};

class human_engineer: public unit_engineer{
public:
    human_engineer()
    {
        set_speed(15);
        set_health(17);
        set_speed_of_building(10);
        set_cost(30);
    }
    ~human_engineer() = default;
};

class anti_aircraft: public unit_war{
public:
    int air_deff;
    void set_air_deff(int damage)
    {
        air_deff = damage;
    }
    const int get_air_deffence() override
    {
        return air_deff;
    }
    anti_aircraft()
    {
        set_speed(10);
        set_power(0);
        set_health(25);
        set_air_deff(15);
        set_cost(75);
    }
    ~anti_aircraft() = default;
};



class human_surface_factory: public surface_factory{
public:
    human_surface_factory()
    {
        set_speed_build(3);
        set_cost_of_factory(500);
    }
    small_mecha *build_fast_unit() override {
        auto *f = new small_mecha;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    armored_mecha *build_armor_unit() override {
        auto *f = new armored_mecha;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    fast_scout *build_scout() override {
        auto *f = new fast_scout;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    human_engineer *build_engineer() override {
        auto *f = new human_engineer;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    void ME() override
    {
        std::cout << "human";
    }
    ~human_surface_factory() = default;

};

class human_bomber: public flying_unit
{
public:
    human_bomber()
    {
        set_health(30);
        set_speed(25);
        set_cost(75);
        set_air_attack(0);
        set_ground_attack(35);
    }
    ~human_bomber() = default;
};

class human_air_fighter: public flying_unit
{
public:
    human_air_fighter()
    {
        set_health(50);
        set_speed(40);
        set_cost(80);
        set_air_attack(40);
        set_ground_attack(0);
    }
    ~human_air_fighter() = default;
};

class human_air_factory: public air_factory{
public:
    human_air_factory()
    {
        set_speed_build(2);
        set_cost_of_factory(400);
    }
    human_bomber *build_bomber() override
    {
        auto f = new human_bomber;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    human_air_fighter *build_fighter() override
    {
        auto f = new human_air_fighter;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    human_engineer *build_engineer() override {
        auto *f = new human_engineer;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    ~human_air_factory() = default;
};

class human_main_unit: public main_unit{
    human_surface_factory *create_surface_factory() override
    {
        auto f = new human_surface_factory;
        energy::decrease_energy(f->get_price());
        return f;
    }
    human_air_factory *create_air_factory() override
    {
        auto f = new human_air_factory;
        energy::decrease_energy(f->get_price());
        return f;
    }
    void who_am_i() override
    {
        std::cout << "human" << '\n';
    }
    ~human_main_unit() = default;
};

#endif //MY_FIRST_REAL_STRATEGY_HUMAN_TREE_H