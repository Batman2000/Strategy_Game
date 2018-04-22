//
// Created by Мхитарян Нарек on 22.04.2018.
//

#ifndef MY_FIRST_REAL_STRATEGY_BASE_DECORATOR_H
#define MY_FIRST_REAL_STRATEGY_BASE_DECORATOR_H

#include "squad.h"
/**
 * brief just base decorator which will be used to wrap a squad or army
 */
class base_decorator: public squad
{
public:
    squad *wrappee;
    base_decorator() = default;
    ~base_decorator() = default;
    base_decorator(squad *s)
    {
        wrappee = s;
    }
    virtual const int get_air_power {};
    virtual const int get_surface_power {};
};

#endif //MY_FIRST_REAL_STRATEGY_BASE_DECORATOR_H
