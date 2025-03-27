#include <string>
#include <stack>

using namespace std;

// 답은 통과 못 하지만 "({)}" <- 이런거는 통과 가능
int solution2(string s) {
    int answer = 0;
    int sSize = s.size();
    
    if (sSize % 2)
    {
        return 0;
    }
    
    stack<char> stSmall;
    stack<char> stMiddle;
    stack<char> stBig;
    
    for (int i = 0; i < sSize; i++)
    {
        for (int j = 0; j < sSize; j++)
        {
            char k = s[(i + j) % sSize];
            
            if (k == '(')
            {
                stSmall.push('(');
            }
            
            else if (k == '{')
            {
                stMiddle.push('{');
            }
            
            else if (k == '[')
            {
                stBig.push('[');
            }
            
            else if (k == ')')
            {
                if (stSmall.empty())
                {
                    answer--;
                    break;
                }
                stSmall.pop();
            }
            
            else if (k == '}')
            {
                if (stMiddle.empty())
                {
                    answer--;
                    break;
                }
                stMiddle.pop();
            }
            
            else if (k == ']')
            {
                if (stBig.empty())
                {
                    answer--;
                    break;
                }
                stBig.pop();
            }
        }
        
        answer++;
        
        while (!stSmall.empty())
        {
            stSmall.pop();
        }
        
        while (!stMiddle.empty())
        {
            stMiddle.pop();
        }
        
        while (!stBig.empty())
        {
            stBig.pop();
        }
    }

    return answer;
}

int solution(string s) {
    int answer = 0;
    int s_len  = s.length();

    if (s_len % 2) {
        return 0;
    }

    stack<char> s_stack;

    for (int i = 0; i < s_len; i++) {
        for (int j = i; j < s_len; j++) {
            switch (s[j]) {
            case '(':
            case '{':
            case '[':
                s_stack.push(s[j]);
                break;

            case ')':
                if (!s_stack.empty() && s_stack.top() == '(') {
                    s_stack.pop();
                }
                else {
                    s_stack.push(s[j]);
                }
                break;

            case '}':
                if (!s_stack.empty() && s_stack.top() == '{') {
                    s_stack.pop();
                }
                else {
                    s_stack.push(s[j]);
                }
                break;

            case ']':
                if (!s_stack.empty() && s_stack.top() == '[') {
                    s_stack.pop();
                }
                else {
                    s_stack.push(s[j]);
                }
                break;
            }
        }

        for (int j = 0; j < i; j++) {
            switch (s[j]) {
            case '(':
            case '{':
            case '[':
                s_stack.push(s[j]);
                break;

            case ')':
                if (!s_stack.empty() && s_stack.top() == '(') {
                    s_stack.pop();
                }
                else {
                    s_stack.push(s[j]);
                }
                break;

            case '}':
                if (!s_stack.empty() && s_stack.top() == '{') {
                    s_stack.pop();
                }
                else {
                    s_stack.push(s[j]);
                }
                break;

            case ']':
                if (!s_stack.empty() && s_stack.top() == '[') {
                    s_stack.pop();
                }
                else {
                    s_stack.push(s[j]);
                }
                break;
            }
        }

        if (s_stack.empty()) {
            answer++;
        }

        while (!s_stack.empty()) {
            s_stack.pop();
        }
    }

    return answer;
}