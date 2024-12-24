int solution(int n) {
    int x = 2;
    
    if (n % x) {
        return x;
    }
    
    for (x = 3; x < n; x += 2) {
        if (n % x == 1) {
            break;
        }
    }
    
    return x;
}