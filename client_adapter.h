//
// Created by Мхитарян Нарек on 22.04.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_CLIENT_ADAPTER_H
#define MY_FIRST_REAL_STRATEGY_CLIENT_ADAPTER_H
#include <iostream>
#include "main_lib.h"
#include "human_tree.h"
#include <vector>
#include "dark_fraction.h"
#include <string>
#include "squad.h"
#include "math.h"
#include <thread>
#include <chrono>
#include "army.h"
/**
 * brief special thread for works with energy
 */
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
/**
 * brief class of adapter which connects client with system
 */
class adapter_main
{
public:
    adapter_main() = default;
    ~adapter_main() = default;
    template <typename T>
    void delete_v(vector <T> &a)
    {
        for(int i = 0; i < a.size(); ++i)
        {
            delete a[i];
        }
    }

    void error_message()
    {
        std::cout << "Error, u don't have enough energy or u have too many units or any factories" << std::endl;
    }

    void energy_error_message()
    {
        std::cout << "Sorry, u don't have enough energy" << std::endl;
    }

    void command_1(int i, vector <main_unit *> &commander, vector <surface_factory *> &Sfactories, vector <surface_factory *> &sur_fact)
    {
        if(energy::energy_of_player >= sur_fact[i]->get_price()) {
            auto d = commander[i]->create_surface_factory();
            Sfactories.push_back(d);
        }
        else
        {
            energy_error_message();
        }
    }

    void command_2(int i, vector <main_unit *> &commander, vector <air_factory *> &Afactories, vector<air_factory *> &air_fact)
    {
        if(energy::energy_of_player >= air_fact[i]->get_price()) {
            auto d = commander[i]->create_air_factory();
            Afactories.push_back(d);
        }
        else
        {
            energy_error_message();
        }
    }

    void command_3(vector <surface_factory *> &Sfactories, vector <air_factory *> &Afactories, vector <unit *> &all_units)
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
            error_message();
        }
    }

    void command_4(vector <air_factory *> &Afactories, vector <unit *> &all_units)
    {
        if(Afactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 80)
        {
            {
                all_units.push_back(Afactories[0]->build_fighter());
            }
        }
        else
        {
            error_message();
        }
    }


    void command_5(vector <air_factory *> &Afactories, vector <unit *> &all_units)
    {
        if(Afactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 75)
        {
            {
                all_units.push_back(Afactories[0]->build_bomber());
            }
        }
        else
        {
            error_message();
        }
    }

    void command_6(vector <surface_factory *> &Sfactories, vector <unit *> &all_units)
    {
        if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 50)
        {
            {
                all_units.push_back(Sfactories[0]->build_fast_unit());
            }
        }
        else
        {
            error_message();
        }
    }

    void command_7(vector <surface_factory *> &Sfactories, vector <unit *> &all_units)
    {
        if(Sfactories.size() > 0 && unit::amount_of_units < 50 && energy::energy_of_player >= 100)
        {
            {
                all_units.push_back(Sfactories[0]->build_armor_unit());
            }
        }
        else
        {
            error_message();
        }
    }

    void command_8(vector <surface_factory *> &Sfactories, vector <unit *> &all_units)
    {
        if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 75)
        {
            {
                all_units.push_back(Sfactories[0]->build_airdefence());
            }
        }
        else
        {
            error_message();
        }
    }

    void command_9(vector <surface_factory *> &Sfactories, vector <unit *> &all_units)
    {
        if(Sfactories.size() > 0 && all_units.size() < 50 && energy::energy_of_player >= 150)
        {
            {
                all_units.push_back(Sfactories[0]->build_extra_unit());
            }
        }
        else
        {
            error_message();
        }
    }

    void command_10(int i, vector <main_unit *> &commander)
    {
        commander[i]->create_generator();
    }

    void status_of_energy()
    {
        std::cout << energy::energy_of_player << std::endl;
    }
    /**
     * brief a stub for check point 2
     */
    void check_point_2()
    {
        //This is just created to make life easier
        //stub
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
        vector <squad *> squads;
        vector <army *> armies;
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
        help_2(i);
        while(true) {
            string s;
            cin >> s;
            if(s == "help")
                help_2(i);
            if(s == "0") {
                energy::energy_of_player = -1000000000;
                break;
            }
            if(s == "1")
            {
                command_1(i, commander, Sfactories, sur_fact);
            }
            if(s == "2")
            {
                command_2(i, commander, Afactories, air_fact);
            }
            if(s == "3")
            {
                command_3(Sfactories, Afactories, all_units);
            }
            else {
                int size1 = all_units.size();
                if (s == "4") {

                    command_4(Afactories, all_units);
                }
                if (s == "5") {
                    command_5(Afactories, all_units);
                }
                if (s == "6") {
                    command_6(Sfactories, all_units);
                }
                if (s == "7") {
                    command_7(Sfactories, all_units);
                }
                if (s == "8") {
                    command_8(Sfactories, all_units);
                }
                if (s == "9") {
                    command_9(Sfactories, all_units);
                }
                int size2 = all_units.size();
                if(size2 > size1)
                {
                    string w;
                    int y;
                    cin >> w >> y;
                    unit_war *u = (unit_war *)all_units[all_units.size() - 1];
                    all_units.pop_back();
                    if(w == "s")
                    {
                        squads[y-1]->add(u);
                    }
                    if(w == "a")
                    {
                        armies[y-1]->add(u);
                    }
                }
            }
            if(s == "10")
            {
                command_10(i, commander);
            }
            if(s == "11")
            {
                status_of_energy();
            }
            if(s == "12")
            {
                squad *f = new squad;
                squads.push_back(f);
            }
            if(s == "13")
            {
                army *f = new army;
                armies.push_back(f);
            }
            //cout << squads.size() << endl;
        }
        delete_v(squads);
        delete_v(armies);
        delete_v(all_units);
        delete_v(Sfactories);
        delete_v(Afactories);
        delete_v(commander);
        delete_v(sur_fact);
        delete_v(air_fact);
        if(thread_of_moment.joinable())
            thread_of_moment.join();
    }

};

#endif //MY_FIRST_REAL_STRATEGY_CLIENT_ADAPTER_H
