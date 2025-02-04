#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    
    unordered_map<char, int> keyCount;
    
    // 문자의 입력을 위한 필요 누름 횟수 저장
    for (string& key : keymap)
    {
        for (int i = 0; i < key.size(); i++)
        {
            // 문자가 첫 등장이거나, 현재 저장된 것보다 적은 횟수라면
            if (keyCount.find(key[i]) == keyCount.end() || i + 1 < keyCount[key[i]])
            {
                keyCount[key[i]] = i + 1;
            }
        }
    }
    
    // 누른 횟수
    int count = 0;
    
    for (string& target : targets)
    {
        count = 0;
        
        for (char& targetChar : target)
        {
            // 없는 문자이면 -1
            if (keyCount.find(targetChar) == keyCount.end())
            {
                count = -1;
                break;
            }
            
            else
            {
                count = count + keyCount[targetChar];
            }
        }
        
        answer.push_back(count);
    }
    
    return answer;
}