#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;
    
    // ex) usun, ebed, acar
    for (string& str : strings)
    {
        answer.push_back(str[n] + str);
    }
    
    sort(answer.begin(), answer.end());
    
    for (string& str : answer)
    {
        str.erase(0, 1);
    }
    
    return answer;
}