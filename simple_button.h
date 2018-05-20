//
// Created by Мхитарян Нарек on 20.05.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_SIMPLE_BUTTON_H
#define MY_FIRST_REAL_STRATEGY_SIMPLE_BUTTON_H

#include "command.h"

/**
 * brief SImple version of the buttons, there will be more complicated one with full usage
 * of command pattern later, in release version
 */
class button
{
public:
    button(){};
    command *some_command;
};

#endif //MY_FIRST_REAL_STRATEGY_SIMPLE_BUTTON_H
