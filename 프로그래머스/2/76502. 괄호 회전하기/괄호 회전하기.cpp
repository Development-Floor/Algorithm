#include <string>
#include <stack>

using namespace std;

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