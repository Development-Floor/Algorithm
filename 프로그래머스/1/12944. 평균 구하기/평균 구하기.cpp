#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double sum = 0;
    
    for (int num : arr) {
        sum += num;
    }
    
    return sum / arr.size();
}