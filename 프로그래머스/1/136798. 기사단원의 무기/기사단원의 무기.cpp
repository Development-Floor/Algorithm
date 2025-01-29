#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int> numbers(number + 1);
    
    for (int i = 1; i <= number; i++) {
        for (int j = i; j <= number; j += i) {
            numbers[j]++;
        }
    }
    
    for (int i = 1; i <= number; i++) {
        if (numbers[i] > limit) {
            answer += power;
        }
        
        else {
            answer += numbers[i];
        }
    }
    
    return answer;
}