#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if (s.length() % 2) {
        answer = answer + s[s.length() / 2];
    }
    else {
        answer = answer + s[s.length() / 2 - 1] + s[s.length() / 2];
    }
    
    return answer;
}