#include <string>

using namespace std;

int solution(string s) {
    
    string numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    for (int i = 0; i < 10; i++) {
        
        // 찾는 문자열이 있다면 바꾸기
        while (s.find(numbers[i]) != string::npos) {
            s.replace(s.find(numbers[i]), numbers[i].size(), to_string(i));
        }
    }
    
    return stoi(s);
}

int solution2(string s) {
    int answer = 0;

    int length = s.length();
    
    for (int i = 0; i < length; i++) {
        if (s[i] <= '9') {
            answer = answer * 10 + s[i] - 48;
            continue;
        }
        
        if (s[i] == 'z') {
            answer = answer * 10;
            i += 3;
            continue;
        }
        
        if (s[i] == 'o') {
            answer = answer * 10 + 1;
            i += 2;
            continue;
        }
        
        if (s[i] == 't' && s[i + 1] == 'w') {
            answer = answer * 10 + 2;
            i += 2;
            continue;
        }
        
        if (s[i] == 't') {
            answer = answer * 10 + 3;
            i += 4;
            continue;
        }
        
        if (s[i] == 'f' && s[i + 1] == 'o') {
            answer = answer * 10 + 4;
            i += 3;
            continue;
        }
        
        if (s[i] == 'f') {
            answer = answer * 10 + 5;
            i += 3;
            continue;
        }
        
        if (s[i] == 's' && s[i + 1] == 'i') {
            answer = answer * 10 + 6;
            i += 2;
            continue;
        }
        
        if (s[i] == 's') {
            answer = answer * 10 + 7;
            i += 4;
            continue;
        }
        
        if (s[i] == 'e') {
            answer = answer * 10 + 8;
            i += 4;
            continue;
        }
        
        answer = answer * 10 + 9;
        i += 3;
    }
    
    return answer;
}