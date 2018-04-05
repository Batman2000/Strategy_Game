//
// Created by Мхитарян Нарек on 18.03.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_DARK_FRACTION_H
#define MY_FIRST_REAL_STRATEGY_DARK_FRACTION_H
#pragma once
#include "main_lib.h"
#include <thread>
#include <iostream>

class dark_solider: public unit_war{
public:
    dark_solider()
    {
        set_health(7);
        set_power(10);
        set_speed(15);
        set_cost(50);
    }
    void get_health()
    {
        std::cout << health;
    }
    ~dark_solider() = default;
};

class armored_solider: public unit_war{
public:
    armored_solider()
    {
        set_health(20);
        set_power(20);
        set_speed(15);
        set_cost(100);
    }
    ~armored_solider() = default;
};

class fast_dark_scout: public unit_war{
public:
    fast_dark_scout()
    {
        set_health(5);
        set_power(5);
        set_speed(40);
        set_cost(25);
    }
    ~fast_dark_scout() = default;
};

class dark_engineer: public unit_engineer{
public:
    dark_engineer()
    {
        set_speed(15);
        set_health(18);
        set_speed_of_building(5);
        set_cost(30);
    }
    ~dark_engineer() = default;
};

class dark_anti_aircraft: public unit_war{
public:
    int air_deff;
    void set_air_deff(int damage)
    {
        air_deff = damage;
    }
    dark_anti_aircraft()
    {
        set_speed(10);
        set_power(0);
        set_health(25);
        set_air_deff(15);
        set_cost(75);
    }
    ~dark_anti_aircraft() = default;
};



class dark_surface_factory: public surface_factory{
public:
    dark_surface_factory()
    {
        set_speed_build(2);
        set_cost_of_factory(450);
    }
    dark_solider *build_fast_unit() override {
        auto *f = new dark_solider;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    armored_solider *build_armor_unit() override {
        auto *f = new armored_solider;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    fast_dark_scout *build_scout() override {
        auto *f = new fast_dark_scout;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    dark_engineer *build_engineer() override {
        auto *f = new dark_engineer;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    void ME() override
    {
        cout << "dark";
    }
    ~dark_surface_factory() = default;
};

class dark_bomber: public flying_unit
{
public:
    dark_bomber()
    {
        set_health(35);
        set_speed(20);
        set_cost(75);
        set_air_attack(0);
        set_ground_attack(30);
    }
    ~dark_bomber() = default;
};

class dark_air_fighter: public flying_unit
{
public:
    dark_air_fighter()
    {
        set_health(52);
        set_speed(45);
        set_cost(80);
        set_air_attack(39);
        set_ground_attack(0);
    }
    ~dark_air_fighter() = default;
};

class dark_air_factory: public air_factory{
public:
    dark_air_factory()
    {
        set_speed_build(3);
        set_cost_of_factory(450);
    }
    dark_bomber *build_bomber() override
    {
        auto f = new dark_bomber;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    dark_air_fighter *build_fighter() override
    {
        auto f = new dark_air_fighter;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    dark_engineer *build_engineer() override {
        auto *f = new dark_engineer;
        energy::decrease_energy(f->get_cost());
        std::this_thread::sleep_for(std::chrono::seconds(speed_of_building_units));
        return f;
    }
    ~dark_air_factory() = default;
};

class dark_main_unit: public main_unit{
    dark_surface_factory *create_surface_factory() override
    {
        auto f = new dark_surface_factory;
        energy::decrease_energy(f->get_price());
        return f;
    }
    dark_air_factory *create_air_factory() override
    {
        auto f = new dark_air_factory;
        energy::decrease_energy(f->get_price());
        return f;
    }
    void who_am_i() override
    {
        std::cout << "dark" << '\n';
    }
    ~dark_main_unit() = default;
};

#endif //MY_FIRST_REAL_STRATEGY_DARK_FRACTION_H