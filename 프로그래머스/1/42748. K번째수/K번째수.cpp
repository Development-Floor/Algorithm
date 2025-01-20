#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int>& command : commands)
    {
        // 벡터 부분 복사
        vector<int> numbers(array.begin() + command[0] - 1, array.begin() + command[1]);
        // 정렬
        sort(numbers.begin(), numbers.end());
        // 추출
        answer.push_back(numbers[command[2] - 1]);
    }
    
    return answer;
}