#ifndef EXPENSE_HPP
#define EXPENSE_HPP


class Daily_Expenses
{
public:

    unsigned int total_expenses = 0;
    unsigned int avg_urgency = 0;

    
    void add(const unsigned int expense, const unsigned int urgency)
    {
        total_expenses += expense;
        
        if (amount == 0)
        {
            avg_urgency = urgency;
            ++amount;
            return;
        }

        urgency_sum += urgency;
        avg_urgency = urgency_sum / ++amount;
    }


private:

    unsigned int amount = 0;
    float urgency_sum = 0;
};


#endif