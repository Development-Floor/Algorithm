long long solution(long long n) {
    long long answer = 0;
    
    int array[10] = { 0, };
    
    while (n > 0) {
        array[n % 10]++;
        n /= 10;
    }
    
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < array[i]; j++) {
            answer = answer * 10 + i;
        }
    }
    
    return answer;
}