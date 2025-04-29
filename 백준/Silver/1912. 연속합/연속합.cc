#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    int maxSum = 0;
    
    int currentSum = 0;
    
    cin >> n;
    
    vector<int> numbers(n);
    
    for (int index = 0; index < n; ++index)
    {
        cin >> numbers[index];
        
        currentSum += numbers[index];
        
        if (currentSum <= 0)
        {
            currentSum = 0;
            continue;
        }
        
        maxSum = max(currentSum, maxSum);
    }
    
    if (maxSum == 0)
    {
        maxSum = *max_element(numbers.begin(), numbers.end());
    }
    
    cout << maxSum << endl;

    return 0;
}