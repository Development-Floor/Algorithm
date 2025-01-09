#include <vector>

using namespace std;

int gcd(int num1, int num2) {
    int Max = max(num1, num2);
    int Min = min(num1, num2);
    
    if (Max % Min == 0) {
        return Min;
    }
    
    return gcd(Max - Min, Min);
}

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    
    answer[0] = gcd(n, m);
    answer[1] = n * m / answer[0];
    
    return answer;
}