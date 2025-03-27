#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    stack<int> st;
    
    int pricesSize = prices.size();
    
    for (int i = 0; i < pricesSize; i++)
    {
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        
        st.push(i);
    }
    
    while (!st.empty())
    {
        answer[st.top()] = pricesSize - st.top() - 1;
        st.pop();
    }
    
    return answer;
}

vector<int> solution2(vector<int> prices) {
    vector<int> answer;
    
    int prices_size = prices.size();
    int j = 0;
    
    for (int i = 0; i < prices_size; i++) {
        
        for (j = i + 1; j < prices_size; j++) {
            if (prices[j] < prices[i]) {
                break;
            }
        }
        
        j = j >= prices_size ? prices_size - 1 : j;
        
        answer.push_back(j - i);
    }
    
    return answer;
}