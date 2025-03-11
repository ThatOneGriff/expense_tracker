#ifndef HELPER
#define HELPER

#include <math.h>


std::string cut_float_to(const float target, const float target_view)
{
    std::string result = std::to_string(target);
    int places_after_pt = -log10(target_view); // 0.1 => 1 etc
    int cutoff_place = result.find('.') + places_after_pt;

    return result.substr(0, cutoff_place);
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
int limit(const unsigned int target, const unsigned int max)
{
    if (target < 0) return 0;
    if (target > max) return max;
    return target;
}


#endif