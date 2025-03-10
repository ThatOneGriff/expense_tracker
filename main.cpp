#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "expense.hpp"
#include "helper.hpp"

/* = STRUCTURE =

Only expense and urgency are saved. Data is stored in identical by structure 'MM_YY.json' files that get fetched if needed.
IDEA: once a file is fetched, it stays loaded. => a check for being loaded pre-fetch. */

// Commands: add, overview (day, week, month, year, all), undo (???)

/* ====  TODO:  ====
- All the new functions in 'helper.hpp' are not tested
- Converting 'unordered_map' into .json
- Find a way to append into the savefile.
- Implement any improvements you can into 'task_tracker'. */

void clean_input(); // BUGGED
void distribute_input();



int DAY_OF_MONTH;
std::string raw_input;
const int INPUT_VAR_AMOUNT = 3; // 1 command, 2 args
std::string input[INPUT_VAR_AMOUNT] = {};



int main()
{
    std::cout << " === Expense Tracker v0.0.1 (type 'help' to list all commands) ===\n";
    std::unordered_map<int, Daily_Expenses> expenses_by_day;

    DAY_OF_MONTH = get_day_of_month();

    while(true)
    {
        clean_input();
        std::cout << "\n> ";
        getline(std::cin, raw_input);
        lower(raw_input); // input has no point in being case-sensitive
        distribute_input();


        if (input[0] == "add")
        {
            // This is to not fetch date every time an expense is added,
            // but only at midnight, when dates change.
            if (is_midnight())
            {
                DAY_OF_MONTH = get_day_of_month(); // TODO: if month changes
            }
            
            if (! is_num(input[1]) || ! is_num(input[2]))
            {
                continue; // TODO:
            }
            
            expenses_by_day[DAY_OF_MONTH].add(stoi(input[1]), limit(stoi(input[2]), 10));
        }


        std::cout << expenses_by_day[DAY_OF_MONTH].total_expenses << ' ';
        std::cout << expenses_by_day[DAY_OF_MONTH].avg_urgency;
    }

    return 0;
}



void clean_input()
{
    std::cin.clear();
    for (int i = 0; i < 4; i++)
        input[i] = "";
}



void distribute_input()
{
    std::stringstream input_stream(raw_input);
    int i = 0;

    while (input_stream >> input[i] && i++ < INPUT_VAR_AMOUNT);

    /*std::string word;
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
    }*/
}