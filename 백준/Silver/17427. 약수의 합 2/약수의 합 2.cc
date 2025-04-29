#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long answer = 0;
    int number;
    
    cin >> number;
    
    for (int num = 1; num <= number; ++num)
    {
        answer = answer + num * (number / num);
    }
    
    cout << answer << endl;

    return 0;
}