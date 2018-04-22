//
// Created by Мхитарян Нарек on 22.04.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_AIR_DECORATOR_H
#define MY_FIRST_REAL_STRATEGY_AIR_DECORATOR_H

#include "base_decorator.h"
/**
 * brief if army/squad will have to fight in air it will be wrapped in this decorator
 */
class air_decorator: public base_decorator
{
    /**
     * func that will attack in air another army/squad
     */
    void air_attack()
    {
        //stub
    }
    air_decorator(squad *s)
    {
        wrappee = s;
    }
};

#endif //MY_FIRST_REAL_STRATEGY_AIR_DECORATOR_H
