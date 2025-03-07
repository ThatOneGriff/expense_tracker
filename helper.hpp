#ifndef HELPER_HPP
#define HELPER_HPP



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



// Тegative numbers in this program are never needed, so minimal return is always 0
int limit(const int target, const int max = __INT_MAX__)
{
    if (target < 0) return 0;
    if (target > max) return max;
    return target;
}


#endif