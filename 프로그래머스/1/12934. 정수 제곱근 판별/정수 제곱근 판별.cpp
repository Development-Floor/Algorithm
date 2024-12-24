#include <cmath>

using namespace std;

long long solution(long long n) {
    long long sqrt_n = (long long)sqrt(n);
    
    if (pow((sqrt_n), 2) == n) {
        return pow(sqrt_n + 1, 2);
    }
    
    return -1;
}