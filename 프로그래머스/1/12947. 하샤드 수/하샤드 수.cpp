bool solution(int x) {
    int sum = 0;
    int origin = x;
    
    while (x > 0) {
        sum = sum + x % 10;
        x /= 10;
    }
    
    return origin % sum == 0;
}