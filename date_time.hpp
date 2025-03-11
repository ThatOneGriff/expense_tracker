#ifndef DATE_TIME
#define DATE_TIME

#include <iomanip>
#include <time.h>
#include <windows.h>

// TODO: month lengths; IDEA: month names?

// WARNING: leap years not accounted for; the array below might not even be all that useful.
//const int MONTH_LENGTHS[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


/*std::string get_date()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d.%m.%Y");
    return oss.str();
}*/



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


#endif