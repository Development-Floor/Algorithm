#include <cmath>

int solution(int n) {
    int sum = 0;
    
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            
            int div = n / i;
            
            if (div != i) {
                sum += div;
            }
        }
    }
    
    return sum;
}