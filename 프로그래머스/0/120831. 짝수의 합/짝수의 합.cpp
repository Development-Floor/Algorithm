int solution(int n) {
    int sum = 0;
    
    n = n % 2 ? n - 1 : n;
    
    sum = (n + 2) * n / 4;
    
    return sum;
}