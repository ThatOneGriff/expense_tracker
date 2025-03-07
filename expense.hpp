#ifndef EXPENSE_HPP
#define EXPENSE_HPP

#include <iostream>
#include "helper.hpp"


class Expense
{
public:
    const std::string name;
    const int amount;
    const int necessity; // 0 - least, 10 - most

    Expense(const std::string _name, const int _amount, const int _neccessity)
    : name(_name), amount(_amount), necessity(_neccessity)
    {}
};


#endif