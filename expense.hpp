#ifndef EXPENSE_HPP
#define EXPENSE_HPP

#include <iostream>
#include "helper.hpp"


class Expense
{
public:
    const std::string date_created;

    // Console constructor
    Expense(const std::string _name, const int _amount, const int _neccessity)
    : name(_name.substr(0, 20)), amount(_amount), necessity(limit(_neccessity, 10)), date_created(get_date())
    {}


    // Out-of-file constructor
    Expense(const std::string _name, const int _amount, const int _neccessity, const std::string _date_created)
    : name(_name), amount(_amount), necessity(_neccessity), date_created(_date_created)
    {}

private:
    const std::string name; // not longer than 20 symbols
    const int amount;
    const int necessity; // 0 - least, 10 - most
};


#endif