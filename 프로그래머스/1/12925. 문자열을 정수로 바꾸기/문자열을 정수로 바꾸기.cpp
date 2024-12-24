#include <string>

using namespace std;

int solution(string s) {
    /*
    int answer = 0;
    
    int s_len = s.length();
    
    for (int i = 0; i < s_len; i++) {
        if (s[i] == '-' || s[i] == '+') {
            continue;
        }
        
        answer = answer * 10 + s[i] - '0';
    }
    
    if (s[0] == '-') {
            answer = -answer;
    }
    */
    
    
    
    return stoi(s);
}