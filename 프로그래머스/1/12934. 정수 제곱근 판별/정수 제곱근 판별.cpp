#include <cmath>

using namespace std;

long long solution(long long n) {
    int sqrt_n = sqrt(n);
    
    if (pow((sqrt_n), 2) == n) {
        return pow(sqrt_n + 1, 2);
    }
    
    return -1;
}
