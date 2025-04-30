#include <string>

using namespace std;

string solution(string number, int k)
{
    const int size = number.size();
    
    int index = 0;
    
    while (index < size)
    {
        if (k <= 0)
        {
            break;
        }
        
        if (index > 0 && number[index - 1] < number[index])
        {
            number.erase(number.begin() + index - 1);
            --k;
            --index;
        }
        
        else
        {
            ++index;
        }
    }
    
    if (k > 0)
    {
        number.erase(number.end() - k, number.end());
    }
    
    return number;
}