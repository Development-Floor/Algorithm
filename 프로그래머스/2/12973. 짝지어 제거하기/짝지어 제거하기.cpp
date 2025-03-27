#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for (char sChar : s)
    {
        if (!st.empty() && st.top() == sChar)
        {
            st.pop();
            continue;
        }
        
        st.push(sChar);
    }
    
    return st.empty();
}

int solution2(string s)
{
    int s_len = s.length();

    // s의 길이가 홀수면 리턴 0
    if (s_len % 2) {
        return 0;
    }

    stack<char> s_stack;

    for (int i = 0; i < s_len; i++) {
        // 스택이 비어잇으면 추가
        if (s_stack.empty()) {
            s_stack.push(s[i]);
        }

        // 스택top 값이 문자와 같으면 스택top 제거
        else if (s_stack.top() == s[i]) {
            s_stack.pop();
        }

        // 스택top 값이 문자와 다르면 스택에 추가
        else {
            s_stack.push(s[i]);
        }
    }

    // 스택이 비어잇으면 리턴 1
    return s_stack.empty() ? 1 : 0;
}