#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 날짜를 파싱하는 함수
void parseDate(const string& dateStr, int& year, int& month, int& day)
{
    year = stoi(dateStr.substr(0, 4));
    month = stoi(dateStr.substr(5, 2));
    day = stoi(dateStr.substr(8, 2));
}

// 날짜를 비교하는 함수
bool isExpired(int todayYear, int todayMonth, int todayDay, 
               int privacyYear, int privacyMonth, int privacyDay)
{
    // 년 비교
    if (todayYear > privacyYear) return true;
    if (todayYear < privacyYear) return false;
    
    // 달 비교
    if (todayMonth > privacyMonth) return true;
    if (todayMonth < privacyMonth) return false;
    
    // 일 비교
    return todayDay >= privacyDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    unordered_map<char, int> termMap;
    
    // today 날짜 파싱하기
    int todayYear, todayMonth, todayDay;
    parseDate(today, todayYear, todayMonth, todayDay);
    
    // 유효기간 저장하기
    for (const string& term : terms)
    {
        int spaceIdx = term.find(" ");
        termMap[term[0]] = stoi(term.substr(spaceIdx + 1));
    }
    
    int privacyYear, privacyMonth, privacyDay;
    
    for (int i = 0; i < privacies.size(); i++)
    {
        // 개인정보 수집 날짜 파싱하기
        parseDate(privacies[i], privacyYear, privacyMonth, privacyDay);
        
        // 유효기간 더하기
        privacyMonth += termMap[privacies[i].back()];
        
        // 년도 환산하기
        privacyYear = privacyYear + (privacyMonth - 1) / 12;
        privacyMonth = (privacyMonth - 1) % 12 + 1;
        
        // 오늘 날짜와 비교하기
        if (isExpired(todayYear, todayMonth, todayDay, privacyYear, privacyMonth, privacyDay))
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}