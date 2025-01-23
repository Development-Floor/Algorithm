#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    // 우선순위 큐, 작은것부터
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int& num : score)
    {
        pq.push(num);
        
        if (pq.size() > k)
        {
            pq.pop();
        }
        
        answer.push_back(pq.top());
    }
    
    return answer;
}

// v.push_back() + sort()
vector<int> solution2(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> array;
    
    for (int i = 0; i < score.size(); i++) {
        array.push_back(score[i]);
        
        sort(array.begin(), array.end(), greater<int>());
        
        if (array.size() > k) {
            array.pop_back();
        }
        
        answer.push_back(array.back());
    }
    
    return answer;
}