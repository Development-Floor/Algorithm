#include <string>

using namespace std;

bool solution(string s) {
    int size = s.size();
    
    if (size != 4 && size != 6) {
        return false;
    }
    
    for (int i = 0; i < size; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    
    return true;
}