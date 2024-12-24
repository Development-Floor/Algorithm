long long solution(int a, int b) {
    long long sum = 0;
    
    if (a > b) {
        int change = a;
        a = b;
        b = change;
    }
    
    sum = ((long long)a + b) * (b - a + 1) / 2;
    
    return sum;
}