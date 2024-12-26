#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    int seoul_size = seoul.size();
    
    for (int i = 0; i < seoul_size; i++) {
        if (seoul[i].compare("Kim") == 0) {
            answer = answer + to_string(i);
            
            break;
        }
    }
    
    answer = answer + "에 있다";
    
    return answer;
}