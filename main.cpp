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



void distribute_unprocessed_input()
{
    std::stringstream unprocessed_stream(unprocessed_input);
    std::string word;
    bool parentheses_open = false;
    int i = 0;
    while (unprocessed_stream >> word && i < 4)
    {
        if (word[0] == '"')
        {
            parentheses_open = true;
            processed_input[i] += word;
            continue;
        }
        else if (word[word.size() - 1] == '"')
            parentheses_open = false;
        
        if (! parentheses_open)
            processed_input[i++] += word;
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