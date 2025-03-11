#ifndef EXPENSE
#define EXPENSE

#include <math.h>
#include <nlohmann/json.hpp>
#include "helper.hpp"
using json = nlohmann::json;



class Daily_Expenses
{
public:

    unsigned int total_expenses = 0;


    Daily_Expenses(const unsigned int _total_expenses, const float _avg_urgency, const int _entry_amount = -1)
    : total_expenses(_total_expenses), avg_urgency(_avg_urgency), entry_amount(_entry_amount)
    {}

    
    void add(const unsigned int expense, const unsigned int urgency)
    {
        // Basically, only today's expenses have their amount saved.
        // And you can't edit yesterday's expenses. IDEA: add expense at certain dates?
        if (entry_amount == -1)
        {
            return; // TODO: message
        }

        total_expenses += expense;
        
        if (entry_amount == 0)
        {
            avg_urgency = urgency;
            urgency_sum = urgency;
            ++entry_amount;
            return;
        }

        urgency_sum += urgency;
        avg_urgency = urgency_sum / ++entry_amount;
    }


    json as_json()
    {
        json data = {
            {"total_expenses", total_expenses},
            {"avg_urgency", avg_urgency}
        };
        return data;
    }


    std::string formatted_urgency()
    {
        std::string formatted_urgency = cut_float_to(avg_urgency, 0.01);
        
        switch(formatted_urgency.size())
        {
            case 1: // X
                formatted_urgency += ".00";
                break;
            case 2: // 10
                formatted_urgency += ".0";
                break;
            case 3: // X.X
                formatted_urgency += '0';
        }
        return formatted_urgency;
    }


private:

    int entry_amount = 0;
    float urgency_sum = 0;
    float avg_urgency = 0;

friend void save(std::unordered_map<int, Daily_Expenses>& expenses);
};



#endif