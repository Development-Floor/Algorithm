#include <string>

using namespace std;

string solution(string s) {
    int index = -1;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            index = -1;
            continue;
        }
        
        index++;
        
        s[i] = index % 2 ? tolower(s[i]) : toupper(s[i]);
    }
    
    return s;
}