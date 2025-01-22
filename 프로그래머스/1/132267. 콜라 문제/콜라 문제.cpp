#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a) {
        // 콜라 받기
        answer = answer + (n / a) * b;
        // 빈병 최신화
        n = n % a + (n / a) * b;
    }
    
    return answer;
}