#include <string>

using namespace std;

string solution(string s, int n) {
    int length = s.size();
    
    for (int i = 0; i < length; i++) {
        
        // 공백일때
        if (s[i] == ' ') {
            continue;
        }
        
        // 대문자일때
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i]= (s[i] + n - 'A') % 26 + 'A';
        }
        
        // 소문자일때
        else {
            s[i] = (s[i] + n - 'a') % 26 + 'a';
        }
    }
    
    return s;
}