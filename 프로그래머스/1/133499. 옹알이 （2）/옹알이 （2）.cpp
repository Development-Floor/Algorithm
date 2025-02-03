#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    string pre = "";
    string cur = "";
    
    for (string& bab : babbling)
    {
        pre = ""; // 이전 발음
        cur = ""; // 현재 발음
        
        for (char& babChar : bab)
        {
            cur += babChar;
            
            // 연속된 발음
            if (cur == pre)
            {
                break;
            }
            
            // 가능한 발음
            else if (cur == "aya" || cur == "ye" || cur == "woo" || cur == "ma")
            {
                pre = cur;
                cur = "";
                
            }
            
            // 불가능한 발음
            else if (cur.size() > 3)
            {
                break;
            }
        }
        
        if (cur.empty())
        {
            answer++;
        }
    }
    
    return answer;
}