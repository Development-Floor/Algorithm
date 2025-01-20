#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<char, int> sCharacter;
    
    int length = s.size();
    
    for (int i = 0; i < length; i++)
    {
        if (sCharacter.find(s[i]) == sCharacter.end())
        {
            //처음 등장했다면 -1
            answer.push_back(-1);
        }
        else
        {
            //처음이 아니라면 현 인덱스에서 전 인덱스 빼기
            answer.push_back(i - sCharacter[s[i]]);
        }
        
        //인덱스 최신화
        sCharacter[s[i]] = i;
    }
    
    return answer;
}