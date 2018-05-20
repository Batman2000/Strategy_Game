//
// Created by Мхитарян Нарек on 20.05.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_COMMAND_H
#define MY_FIRST_REAL_STRATEGY_COMMAND_H

#include "squad.h"
/**
 * brief A command pattern main class
 */
class command
{
protected:
squad* num1, *num2;
public:
    command() = default;
    command(squad* _num1, squad *_num2)
    {
        num1 = _num1;
        num2 = _num2;
    }
    virtual void execute(){};
    virtual void execute(int i, vector<main_unit *> &commander, vector<surface_factory *> &Sfactories,
                 vector<surface_factory *> &sur_fact){};
    virtual void execute(int i, vector<main_unit *> &commander, vector<air_factory *> &Afactories,
                 vector<air_factory *> &air_fact){};
    virtual void
    execute(vector<surface_factory *> &Sfactories, vector<air_factory *> &Afactories, vector<unit *> &all_units){};
    virtual void execute(vector<air_factory *> &Afactories, vector<unit *> &all_units){};
    virtual void execute(vector <surface_factory *> &Sfactories, vector <unit *> &all_units){};

};

#endif //MY_FIRST_REAL_STRATEGY_COMMAND_H
