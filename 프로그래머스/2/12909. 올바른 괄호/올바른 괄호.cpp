#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    // 문자열의 시작이 닫힌 괄호 or 문자열의 끝이 열린 괄호
    if (s[0] == ')' || s[s.size() - 1] == '(')
    {
        return false;
    }

    // 길이가 홀수 일 때
    if (s.size() % 2)
    {
        return false;
    }
    
    stack<char> stParenthesis;
    
    for (char sChar : s)
    {
        // 짝이 맞을때
        if (sChar == ')' && stParenthesis.top() == '(')
        {
            stParenthesis.pop();
            continue;
        }
        
        stParenthesis.push(sChar);
    }

    return stParenthesis.empty();
}