#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    
    // 각 유형의 점수
    unordered_map<char, int> surveyCount = {
        { 'R', 0 },
        { 'T', 0 },
        { 'C', 0 },
        { 'F', 0 },
        { 'J', 0 },
        { 'M', 0 },
        { 'A', 0 },
        { 'N', 0 }
    };
    
    for (int i = 0; i < survey.size(); i++)
    {
        char first = survey[i][0];
        char second = survey[i][1];
        
        // score: -3 ~ 3
        int score = choices[i] - 4;
        
        // 첫 번째 문자에 점수 추가
        if (score < 0)
        {
            surveyCount[first] -= score;
        }
        
        // 두 번째 문자에 점수 추가
        else if (score > 0)
        {
            surveyCount[second] += score;
        }
    }
    
    // 결과 문자열 생성
    answer += surveyCount['R'] >= surveyCount['T'] ? "R" : "T";
    answer += surveyCount['C'] >= surveyCount['F'] ? "C" : "F";
    answer += surveyCount['J'] >= surveyCount['M'] ? "J" : "M";
    answer += surveyCount['A'] >= surveyCount['N'] ? "A" : "N";
    
    return answer;
}