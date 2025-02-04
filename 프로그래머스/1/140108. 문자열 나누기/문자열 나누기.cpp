#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    char xChar = ' ';
    int count = 0;
    
    for (char sChar : s)
    {
        // (분리 후) 첫 글자
        if (xChar == ' ')
        {
            xChar = sChar;
            count = 1;
        }
        
        // x와 같을 때
        else if (xChar == sChar)
        {
            count++;
        }
        
        // x와 다를 때
        else
        {
            count--;
        }
        
        // 나온 횟수가 같을 때
        if (count == 0)
        {
            answer++;
            xChar = ' ';
        }
    }
    
    if (xChar != ' ')
    {
        answer++;
    }
    
    return answer;
}