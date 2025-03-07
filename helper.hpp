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



// Never do you negative numbers in this program, so min return is always 0 EXCEPT for errors
int limit(const int target, const int max = __INT_MAX__)
{
    if (target < 0) return 0;
    if (target > max) return max;
    return target;
}


#endif