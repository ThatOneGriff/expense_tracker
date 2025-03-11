#ifndef EXPENSE
#define EXPENSE

#include <math.h>
#include "helper.hpp"



class Daily_Expenses
{
public:

    unsigned int total_expenses = 0;

    
    void add(const unsigned int expense, const unsigned int urgency)
    {
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

    unsigned int entry_amount = 0;
    float urgency_sum = 0;
    float avg_urgency = 0;
};



#endif