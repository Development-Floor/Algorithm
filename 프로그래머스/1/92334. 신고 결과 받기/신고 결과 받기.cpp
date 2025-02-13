#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    
    // 메일 개수
    unordered_map<string, int> mailCount;
    // 신고된 사람 - 신고한 사람들
    unordered_map<string, unordered_set<string>> toReport;
    
    for (const string& id : id_list)
    {
        mailCount[id] = 0;
        toReport[id] = unordered_set<string>();
    }
    
    string reportingPerson; // 신고한 사람
    string reportedPerson;  // 신고된 사람
    
    // 신고 처리
    for (const string& reporting : report)
    {
        // 신고한 사람, 신고된 사람 파싱
        int spaceIdx = reporting.find(" ");
        reportingPerson = reporting.substr(0, spaceIdx);
        reportedPerson = reporting.substr(spaceIdx + 1);
        
        toReport[reportedPerson].insert(reportingPerson);
    }
    
    // 메일 보내기
    for (const pair<string, unordered_set<string>>& iter : toReport)
    {
        if (iter.second.size() >= k)
        {
            for (const string& toMail : iter.second)
            {
                mailCount[toMail]++;
            }
        }
    }
    
    // id_list 순서로 메일 세기
    for (const string& id : id_list)
    {
        answer.push_back(mailCount[id]);
        
    }
    
    return answer;
}