#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int num1 = 0;
    int num2 = 0;
    int newScoville = 0;
    
    while (pq.top() < K && pq.size() >= 2)
    {
        ++answer;
        
        num1 = pq.top();
        pq.pop();
        
        num2 = pq.top();
        pq.pop();
        
        newScoville = num1 + num2 * 2;
        
        pq.push(newScoville);
    }
    
    if (pq.top() < K)
    {
        answer = -1;
    }
    
    return answer;
}