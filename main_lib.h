//
// Created by Мхитарян Нарек on 15.03.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_MAIN_LIB_H
#define MY_FIRST_REAL_STRATEGY_MAIN_LIB_H
#pragma once

#include <string>

class energy{
public:
    energy() = delete;
    ~energy() = delete;
    energy(const energy&) = delete;
    energy &operator = (energy&) = delete;
    static int energy_of_player;
    static void increase_energy(int energetic)
    {
        energy_of_player+=energetic;
    }
    static void decrease_energy(int energy_cost)
    {
        energy_of_player-=energy_cost;
    }
};
int energy::energy_of_player = 0;
class unit_main{
    int speed, power, health;
    void build_energy_reactor(){

    }
    void build_extractor(){

    }
    void build_surface_factory(){

    }
    void build_air_factory() {

    }
};
class unit{
protected:
    static int amount_of_units;
    int health, speed, energy_cost;
    virtual void set_speed(int a){
        speed = a;
    }
    virtual void set_health(int c){
        health = c;
    }
    void set_cost(int price)
    {
        energy_cost = price;
    }

public:
    virtual int get_cost()
    {
        return energy_cost;
    }
    virtual ~unit() = default;
    int get_speed()
    {
        return speed;
    }
};

int unit::amount_of_units = 1;

class unit_engineer: public unit{

    int speed_of_building;
protected:
    void set_speed_of_building(int setted_speed)
    {
        speed_of_building = setted_speed;
    }

public:
    int get_speed_of_engineer()
    {
        return speed_of_building;
    }
    ~unit_engineer() = default;
};

class unit_war: public unit{
protected:
    int power;

    virtual void set_power(int b){
        power = b;
    }
    int get_power()
    {
        return power;
    }
    void decrease_health(int damage)
    {
        health-=damage;
        if(health <= 0)
        {
            std::cout << "unit is dead";
            delete this;
        }
    }
    void attack()
    {

    }

public:
    unit_war()
    {
        speed = 0;
        power = 0;
        health = 0;
    }
    ~unit_war() = default;
};

class flying_unit: public unit{
    int attack_of_planes, attack_of_ground_units;
protected:
    void set_air_attack(int damage)
    {
        attack_of_planes = damage;
    }
    void set_ground_attack(int damage)
    {
        attack_of_ground_units = damage;
    }
    ~flying_unit() = default;
};

class extra_unit_builder: public unit_war
{
    int air_deff;
public:
    void set_air_deff(int damage)
    {
        air_deff = damage;
    }
    void set_speed(int _speed) override
    {
        speed = _speed;
    }
    void set_health(int _health) override
    {
        health = _health;
    }
    void set_power(int _power) override
    {
        power = _power;
    }
    int get_cost() override
    {
        return 2*(air_deff+speed+health+get_power());
    }
    ~extra_unit_builder() = default;
};


class generator_of_energy{
public:
    static int how_many;
    int energy_per_second;
};

int generator_of_energy::how_many = 0;

class main_factory{

protected:
    int cost = 0;
    int speed_of_building_units;
    void set_cost_of_factory(int price)
    {
        cost = price;
    }
    void set_speed_build(int speed)
    {
        speed_of_building_units = speed;
    }
public:
    virtual unit_engineer *build_engineer(){
        auto f = new unit_engineer;
        return f;
    }

    int get_price()
    {
        return cost;
    }
    virtual ~main_factory() = default;
};

class air_factory: public main_factory{
public:
    virtual flying_unit *build_bomber()
    {
        auto f = new flying_unit;
        return f;
    }
    virtual flying_unit *build_fighter()
    {
        auto f = new flying_unit;
        return f;
    }
    ~air_factory() = default;
};

class surface_factory: public main_factory{
public:
    virtual unit_war *build_airdefence(){
        auto f = new unit_war;
        return f;
    }
    virtual unit_war *build_armor_unit(){
        auto f = new unit_war;
        return f;
    }
    virtual unit_war *build_fast_unit(){
        auto f = new unit_war;
        return f;
    }
    virtual unit_war *build_scout() {
        auto f = new unit_war;
        return f;
    }
    virtual extra_unit_builder *build_extra_unit(){
        auto f = new extra_unit_builder;
        std::cout << "Please type speed, health, power and air_deffence of extra unit" << std::endl;
        int speed, health, power, air_deff;
        std::cin >> speed >> health >> power >> air_deff;
        f->set_air_deff(air_deff);
        f->set_speed(speed);
        f->set_power(power);
        f->set_health(health);
        energy::decrease_energy(f->get_cost());
        std::cout << "extra unit is built" << std::endl;
        return f;
    }


    virtual void ME()
    {
        std::cout << "???";
    }
    ~surface_factory() = default;
};

class main_unit {
public:
    void create_generator()
    {
        generator_of_energy::how_many++;
    }
    virtual surface_factory *create_surface_factory()
    {
        auto f = new surface_factory;
        return f;
    }
    virtual air_factory *create_air_factory()
    {
        auto f = new air_factory;
        return f;
    }
    virtual void who_am_i()
    {
        std::cout << "nuetral";
    }
    virtual ~main_unit() = default;
};


std::string trend(int i)
{
    if(i)
        return "Dark";
    else
        return "Human";
}
using namespace std;
void help(int i)
{
    cout << "You can build:" << endl;
    cout << trend(i) << ' ' << "surface factory - press 1" << endl;
    cout << trend(i) << ' ' << "air factory - press 2" << endl;
    cout << trend(i) << ' ' << "engineer - press 3" << endl;
    cout << trend(i) << ' ' << "air fighter - press 4" << endl;
    cout << trend(i) << ' ' << "air bomber - press 5" << endl;
    cout << trend(i) << ' ' << "standart surface unit - press 6" << endl;
    cout << trend(i) << ' ' << "armored surface unit - press 7" << endl;
    cout << trend(i) << ' ' << "air deffence unit - press 8" << endl;
    cout << trend(i) << ' ' << "extra surface unit - press 9" << endl;
    cout << trend(i) << ' ' << "generator of energy - press 10" << endl;
    cout << "energy level - press 11" << endl;
    cout << "You can build only 50 units in total" << endl;
    cout << "you can end session by pressing 0" << endl;
}

#endif //MY_FIRST_REAL_STRATEGY_MAIN_LIB_H