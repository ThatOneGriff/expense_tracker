#ifndef HELPER_HPP
#define HELPER_HPP

#include <iomanip>
#include <string>
#include <time.h>
#include <windows.h>



std::string get_date()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d.%m.%Y");
    return oss.str();
}



int get_day_of_month()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d");
    return stoi(oss.str());
}


bool is_midnight()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%H%M");

    return (oss.str() == "0000");
}



bool is_num(const std::string& str)
{
    for (const char& c: str)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}



void lower(std::string& str)
{
    for (char& c: str)
        c = tolower(c);
}



// Negative numbers in this program are never needed, so minimal return is always 0
int limit(const int target, const int max = __INT_MAX__)
{
    if (target < 0) return 0;
    if (target > max) return max;
    return target;
}


#endif