#include <string>

using namespace std;

string solution(int a, int b) {
    string answer;
    
    // 1월 1일이 금요일이므로 + 4
    int month[12] = { 4, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    
    string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    
    for (int i = 0; i < a; i++)
    {
        b += month[i];
    }
    
    answer = week[b % 7];
    
    return answer;
}