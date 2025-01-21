#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    
    int size = food.size();
    int count = 0;
    
    for (int i = size - 1; i >= 1; i--)
    {
        count = food[i] / 2;
        
        for (int j = 0; j < count; j++)
        {
            answer = to_string(i) + answer + to_string(i);
        }
    }
    
    return answer;
}