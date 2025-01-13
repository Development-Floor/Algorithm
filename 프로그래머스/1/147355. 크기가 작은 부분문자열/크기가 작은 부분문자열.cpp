#include <string>

using namespace std;

int solution(string t, string p) {
    int loopCount = t.size() - p.size();
    int pSize = p.size();
    
    int answer = 0;
    
    long long number = 0;
    long long pNumber = stol(p);
    
    string stringNumber = "";
    
    for (int i = 0; i <= loopCount; i++)
    {
        stringNumber = t.substr(i, pSize);
        number = stol(stringNumber);
        
        if (number <= pNumber)
        {
            answer++;
        }
    }
    
    return answer;
}