#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> sum;
    
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            sum.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(sum.begin(), sum.end());
    
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    
    return sum;
}

vector<int> solution3(vector<int> numbers)
{
    set<int> sum;
    
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            sum.insert(numbers[i] + numbers[j]);
        }
    }
    
    return vector<int>(sum.begin(), sum.end());
}

vector<int> solution2(vector<int> numbers) {
    vector<bool> result(201);
    
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            result[numbers[i] + numbers[j]] = true;
        }
    }
    
    vector<int> answer;
    
    for (int i = 0; i < 200; i++) {
        if (result[i]) {
            answer.push_back(i);
        }
    }
    
    return answer;
}