int solution(int num) {
    int count = 0;
    
    long long number = num;
    
    while (number != 1) {
        if (number % 2) {
            number = number * 3 + 1;
        }
        else {
            number /= 2;
        }
        
        count++;
        
        if (count >= 500) {
            return -1;
        }
    }
    
    return count;
}