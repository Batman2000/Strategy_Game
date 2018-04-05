#include <iostream>
#include "main_lib.h"
#include "human_tree.h"
#include <thread>
#include <chrono>
#include <vector>
#include "dark_fraction.h"
#include <string>

void thread_for_energy_change()
{
    while(true) {
        if(energy::energy_of_player < 0)
            return;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        energy::increase_energy(generator_of_energy::how_many*10);
        //std::cout << energy::energy_of_player << std::endl;
    }
}

void check_point_1()
{
    //This is just created to make life easier
    //I don't know how to name it in English, so we usually call it "заглушка"
    using namespace std;
    thread thread_of_moment(thread_for_energy_change);
    vector <main_unit *> commander(2);
    commander[0] = new human_main_unit;
    commander[1] = new dark_main_unit;
    vector <surface_factory *> sur_fact(2);
    sur_fact[0] = new human_surface_factory;
    sur_fact[1] = new dark_surface_factory;
    vector <air_factory *> air_fact(2);
    air_fact[0] = new human_air_factory;
    air_fact[1] = new dark_air_factory;
    vector <unit *> all_units;
    vector <surface_factory*> Sfactories;
    vector <air_factory *> Afactories;
    cout << "Choose your fraction commander :" << endl << "human" << endl << "dark" << endl;
    string s;
    cin >> s;
    int i = 0;
    if(s == "human")
    {
        i = 0;
    }
    else
    {
        i = 1;
    }
    help(i);
    while(true) {
        string s;
        cin >> s;
        if(s == "help")
            help(i);
        if(s == "0") {
            energy::energy_of_player = -1000000000;
            break;
        }
        if(s == "1")
        {
            if(energy::energy_of_player >= sur_fact[i]->get_price()) {
                auto d = commander[i]->create_surface_factory();
                Sfactories.push_back(d);
            }
            else
            {
                cout << "Sorry, u don't have enough energy" << endl;
            }
        }
        if(s == "2")
        {
            if(energy::energy_of_player >= air_fact[i]->get_price()) {
                auto d = commander[i]->create_air_factory();
                Afactories.push_back(d);
            }
            else
            {
                cout << "Sorry, u don't have enough energy" << endl;
            }
        }
        if(s == "3")
        {
            if(Sfactories.size() + Afactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 30)
            {
                if(Sfactories.size() > 0)
                {
                    all_units.push_back(Sfactories[0]->build_engineer());
                }
                if(Afactories.size() > 0)
                {
                    all_units.push_back(Afactories[0]->build_engineer());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "4")
        {
            if(Afactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 80)
            {
                {
                    all_units.push_back(Afactories[0]->build_fighter());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "5")
        {
            if(Afactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 75)
            {
                {
                    all_units.push_back(Afactories[0]->build_bomber());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "6")
        {
            if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 50)
            {
                {
                    all_units.push_back(Sfactories[0]->build_fast_unit());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "7")
        {
            if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 100)
            {
                {
                    all_units.push_back(Sfactories[0]->build_armor_unit());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "8")
        {
            if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 75)
            {
                {
                    all_units.push_back(Sfactories[0]->build_airdefence());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "9")
        {
            if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 150)
            {
                {
                    all_units.push_back(Sfactories[0]->build_extra_unit());
                }
            }
            else
            {
                cout << "Error, u don't have enough energy or u have too many units or any factories" << endl;
            }

        }
        if(s == "10")
        {
            commander[i]->create_generator();
        }
        if(s == "11")
        {
            cout << energy::energy_of_player << endl;
        }
    }
    for(int i = 0; i < all_units.size(); ++i)
    {
        delete all_units[i];
    }
    for(int i = 0; i < Sfactories.size(); ++i)
    {
        delete Sfactories[i];
    }
    for(int i = 0; i < Afactories.size(); ++i)
    {
        delete Afactories[i];
    }
    for(int j = 0; j < 2; ++j)
    {
        delete commander[j];
        delete sur_fact[j];
        delete air_fact[j];
    }
    if(thread_of_moment.joinable())
        thread_of_moment.join();
}

int main() {
    check_point_1();
    return 0;
}