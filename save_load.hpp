#ifndef SAVE_LOAD
#define SAVE_LOAD

#include <fstream>
#include <nlohmann/json.hpp>
#include <unordered_map>

#include "expense.hpp"
using json = nlohmann::json;


const std::string SAVE_PATH = "data.json";


/* Basically, the structure of a savefile element is:
{
    "day": 2, // !!!
    "total_expenses": 1000,
    <...>
} */

std::unordered_map<int, Daily_Expenses> load()
{
    std::unordered_map<int, Daily_Expenses> expenses;
    std::ifstream f(SAVE_PATH);
    if (f.peek() == std::ifstream::traits_type::eof())
    {
        //std::cout << textcolor(YELLOW) << "No tasks loaded: data file '" << SAVE_PATH << "' not found.\n\n" << textcolor(WHITE);
        f.close();
        return expenses;
    }
    
    const json data = json::parse(f);
    f.close();

    expenses.reserve(data.size());
    for (const auto& element: data)
    {
        // IDEA: a less fragile load system that avoids errors
        if (element.find("entry_amount") != element.end())
        {
            Daily_Expenses expense(element["total_expenses"], element["avg_urgency"], element["entry_amount"]);
            expenses[element["day"]] = expense;
        }
        else
        {
            Daily_Expenses expense(element["total_expenses"], element["avg_urgency"]);
            expenses[element["day"]] = expense;
        }
    }

    return expenses;

    /*switch (tasks.size())
    {
    case 0:
        std::cout << textcolor(YELLOW) << "No tasks loaded: data file '" << SAVE_PATH << "' is empty.\n\n" << textcolor(WHITE);
        break;
    case 1:
        std::cout << "1 task loaded.\n\n";
        break;
    default:
        std::cout << tasks.size() << " tasks loaded.\n\n";
        break;
    }*/
}


#endif