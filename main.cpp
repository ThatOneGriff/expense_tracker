#include <iostream>
#include <string>
#include <vector>

#include "expense.hpp"


/* Every 1st, a new 'month.json' is created.
The previous 'month.json' is renamed to '[MONTH_NUMBER].json.

Full data is available for 3 previous months, and each month before that gets transformed: only expense amounts daily. */

// Commands: add, delete, list (week, month (?)), overview (week, month, year, all)


int main()
{
    std::cout << " === Expense Tracker (type 'help' to list all commands) ===\n\n";

    std::vector<Expense> expenses_month;

    std::string command;
    std::string arg1, arg2, arg3;
    
    while(true)
    {
        // cleaning leftover input
        std::cin.clear();
        std::cout << "> ";
        getline(std::cin, command);


        if (command == "add")
        {
            std::cout << "Name: ";
            getline(std::cin, arg1);

            std::cout << "Amount: ";
            getline(std::cin, arg2);
            if (! is_num(arg2))
            {
                std::cout << "Invalid input!";
                continue;
            }

            std::cout << "Necessity (0-10): ";
            getline(std::cin, arg3);
            if (! is_num(arg3))
            {
                std::cout << "Invalid input!";
                continue;
            }

            Expense new_expense(arg1, limit(stoi(arg2)), limit(stoi(arg3), 10));
            expenses_month.push_back(new_expense);
        }


        
    }

    return 0;
}