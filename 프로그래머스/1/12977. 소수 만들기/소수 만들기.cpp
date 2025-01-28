#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    int count = 0;

    vector<bool> isPrimeNumbers(3001);
    
    for (int i = 2; i * i <= 3000; i++)
    {
        for (int j = 2 * i; j <= 3000; j += i)
        {
            isPrimeNumbers[j] = true;
        }
    }
    
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (!isPrimeNumbers[nums[i] + nums[j] + nums[k]])
                {
                    count++;
                }
            }
        }
    }

    return count;
}