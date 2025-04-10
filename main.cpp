#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "date_time.hpp"
#include "expense.hpp"
#include "helper.hpp"
#include "save_load.hpp"

/* = STRUCTURE =

Data is stored in identical by structure 'MM_YY.json's files that get fetched if needed.
IDEA: once a file is fetched, it stays loaded. => a check for being loaded pre-fetch. */

// Commands: add, overview (day, week, month, year, all), undo (???)

/* ====  TODO:  ====
- All the new functions in 'helper.hpp' are not tested
- Converting 'unordered_map' into .json
- Find a way to append into the savefile and implement same system into 'task_tracker'. */

void clean_input();
void distribute_input();


int DAY_OF_MONTH;

std::string raw_input;

const int INPUT_VAR_AMOUNT = 3; // 1 command, 2 args
std::string input[INPUT_VAR_AMOUNT];
#define command input[0]
#define arg1    input[1]
#define arg2    input[2]



int main()
{
    std::cout << " === Expense Tracker v0.0.1 (type 'help' to list all commands) ===\n";
    DAY_OF_MONTH = get_day_of_month();

    std::unordered_map<int, Daily_Expenses> expenses_this_month = load();

    while(true)
    {
        clean_input();
        std::cout << "\n > ";
        getline(std::cin, raw_input);
        lower(raw_input); // input has no point in being case-sensitive
        distribute_input();


        if (command == "add")
        {
            // This is to not fetch date every time an expense is added,
            // but only at midnight, when dates change.
            if (is_midnight())
            {
                DAY_OF_MONTH = get_day_of_month(); // TODO: if month changes
            }
            
            if (! is_num(arg1) || ! is_num(arg2))
            {
                continue; // TODO
            }
            
            expenses_this_month[DAY_OF_MONTH].add(stoi(arg1), limit(stoi(arg2), 10));
        }


        else if (command == "overview")
        {
            // TODO: basically the proper function after save/load is done
            // TODO: day/week/month/year
            if (expenses_this_month.empty())
                continue; // TODO: message
            
            
            std::cout << "\n DAY | AVG--URG | TOTAL\n";
            for (int i = 1; i <= 31; i++)
            {
                if (expenses_this_month.find(i) == expenses_this_month.end())
                    continue;
                
                std::cout <<    "  " << (i <= 9 ? "0" : "") << i     << " |   " // day formatted to always be 2 characters long
                          << expenses_this_month[i].formatted_urgency()  << "   | "
                          <<    expenses_this_month[i].total_expenses    << '\n';
            }
            
            continue;
        }

        save(expenses_this_month);
    }

    return 0;
}



void clean_input()
{
    std::cin.clear();
    for (int i = 0; i < INPUT_VAR_AMOUNT; i++)
        input[i] = "";
}



void distribute_input()
{
    std::stringstream input_stream(raw_input);
    int i = 0;

    while (input_stream >> input[i] && i++ < INPUT_VAR_AMOUNT);
}