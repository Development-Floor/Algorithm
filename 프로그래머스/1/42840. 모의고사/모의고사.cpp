#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> student1 = { 1, 2, 3, 4, 5 };
    vector<int> student2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> student3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    vector<int> score(3);
    
    for (int i = 0; i < answers.size(); i++)
    {
        // 1번 수포자 정답
        if (student1[i % student1.size()] == answers[i])
        {
             score[0]++;
        }
        
        // 2번 수포자 정답
        if (student2[i % student2.size()] == answers[i])
        {
            score[1]++;
        }
        
        // 3번 수포자 정답
        if (student3[i % student3.size()] == answers[i])
        {
            score[2]++;
        }
    }
    
    int maxScore = *max_element(score.begin(), score.end());
    
    for (int i= 0; i < 3; i++)
    {
        if (score[i] == maxScore)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}