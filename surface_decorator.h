//
// Created by Мхитарян Нарек on 22.04.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_SURFACE_DECORATOR_H
#define MY_FIRST_REAL_STRATEGY_SURFACE_DECORATOR_H

#include "base_decorator.h"
/**
 * brief if army/squad will have to fight on surface it will be wrapped in this decorator
 */
class surface_decorator: public base_decorator
{
    /**
     * func that will attack on surface another army/squad
     */
    void surface_attack()
    {
        //stub
    }
    surface_decorator(squad *s)
    {
        wrappee = s;
    }
};

#endif //MY_FIRST_REAL_STRATEGY_SURFACE_DECORATOR_H
