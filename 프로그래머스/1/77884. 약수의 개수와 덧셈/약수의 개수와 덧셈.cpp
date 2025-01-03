#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0; // 리턴값 변수
    int count = 0;  // 약수의 갯수를 담을 변수
    
    for (; left <= right; left++) {
        count = 0;
        
        // 약수의 갯수 구하기
        for (int i = 1; i <= sqrt(left); i++) {
            if (left % i == 0) {
                count += 2;
                
                if (left / i == i) {
                    --count;
                }
            }
        }
        
        // 갯수가 홀수면 빼고, 짝수면 더하기
        answer = count % 2 ? answer - left : answer + left;
    }
    
    return answer;
}