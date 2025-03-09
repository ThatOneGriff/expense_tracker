#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "expense.hpp"

/* Every 1st, a new 'month.json' is created.
The previous 'month.json' is renamed to '[MONTH_NUMBER].json.

Full data is available for 3 previous months, and each month before that gets transformed: only expense amounts daily. */

// Commands: add, delete, list (day, week, month (?)), overview (week, month, year, all)


std::string raw_input;
const int INPUT_VAR_AMOUNT = 4; // 1 command, 3 args
std::string input[INPUT_VAR_AMOUNT] = {};
void distribute_input();


int main()
{
    std::cout << " === Expense Tracker v0.0.1 (type 'help' to list all commands) ===\n";
    std::vector<Expense> expenses_month;


    while(true)
    {
        // cleaning leftover input
        std::cin.clear();
        std::cout << "\n> ";
        getline(std::cin, raw_input);
        distribute_input();


        if (input[0] == "add")
        {
            // TODO: Empty input, NaN input checks
            Expense new_expense(input[0], stoi(input[1]), stoi(input[2]));
            expenses_month.push_back(new_expense);
        }


        else if (input[0] == "list")
        {
            
        }
    }

    return 0;
}



// I may implement a 50-symbol limit to all words to prevent breaking the program by inputs that are too long.
// It may mess with a quotation mark check though.
void distribute_input()
{
    // cleaning previous input
    for (int i = 0; i < 4; i++)
        input[i] = "";
    
    std::stringstream input_stream(raw_input);
    std::string word;
    bool quote_marks_open = false;
    int i = 0;
    while (input_stream >> word && i < 4)
    {
        if (word[0] == '"') // start of a multi-word argument [MWA]
        {
            quote_marks_open = true;
            input[i] += word.substr(1, word.size() - 1);
            continue;
        }

        if (quote_marks_open)
            input[i] += ' ' + word;
        if (word[word.size() - 1] == '"') // last word in an MWA cascades through the previous 'if' to here
        {
            quote_marks_open = false;
            input[i] = input[i].substr(0, input[i].size() - 1);
            ++i;
            continue;
        }
        
        if (! quote_marks_open)
            input[i++] += word;
    }
}