#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "expense.hpp"

/* Every 1st, a new 'month.json' is created.
The previous 'month.json' is renamed to '[MONTH_NUMBER].json.

Full data is available for 3 previous months, and each month before that gets transformed: only expense amounts daily. */

// Commands: add, delete, list (week, month (?)), overview (week, month, year, all)


std::string unprocessed_input;
const int INPUT_VAR_AMOUNT = 4; // 1 command, 3 args
std::string processed_input[INPUT_VAR_AMOUNT] = {};
void process_input();


int main()
{
    std::cout << " === Expense Tracker v0.0.1 (type 'help' to list all commands) ===\n\n";
    std::vector<Expense> expenses_month;

    
    while(true)
    {
        // cleaning leftover input
        std::cin.clear();
        std::cout << "> ";
        getline(std::cin, unprocessed_input);
        process_input();

        for (int i = 0; i < 4; i++)
            std::cout << '"' << processed_input[i] << "\"\n";


        //if (processed_input[0] == "add")
        //{
        //    std::cout << 1;
        //    Expense new_expense(processed_input[0], stoi(processed_input[1]), stoi(processed_input[2]));
        //    expenses_month.push_back(new_expense);
        //}
    }

    return 0;
}



// TODO: Streamline this function. Maybe add a 'must_save' bool.
void distribute_unprocessed_input()
{
    int var_id = 0;
    std::string curr_val;
    bool open_parentheses = false;
    for (int i = 0; i < unprocessed_input.size() && var_id < INPUT_VAR_AMOUNT; i++)
    {
        bool ready_to_save = false;
        if (unprocessed_input[i] == '"')
        {
            open_parentheses = ! open_parentheses;
            if (! open_parentheses)
                ready_to_save = true;
            else
                continue;
        }

        if (unprocessed_input[i] == ' ')
        {
            if (open_parentheses)
                curr_val += unprocessed_input[i];
            else if (curr_val != "")
                ready_to_save = true;
        }

        if (i == unprocessed_input.size() - 1)
        {
            curr_val += unprocessed_input[i];
            ready_to_save = true;
        }

        if (ready_to_save)
        {
            processed_input[var_id++] = curr_val;
            curr_val = "";
        }
        else
            curr_val += unprocessed_input[i];
    }
}



void process_input()
{
    // cleaning previous input
    for (int i = 0; i < 4; i++)
        processed_input[i] = "";

    // distributing into 4 variables
    distribute_unprocessed_input();
}