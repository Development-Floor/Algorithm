#include <string>
#include <vector>

using namespace std;

enum Days
{
    Sun = 0, // 조건에서 월요일 == 1
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat
};

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    const int memberCount = answer = schedules.size(); // 직원 수
    const int dayCount = timelogs[0].size();           // 이벤트 기간
    
    int week = 0; // 출근 요일
    int time = 0; // 출근 시간
    
    for (int i = 0; i < memberCount; i++)
    {
        for (int j = 0; j < dayCount; j++)
        {
            week = (startday + j) % 7;
            
            // 토, 일
            if (week == Sat || week == Sun)
            {
                continue;
            }
            
            // 10분
            time = timelogs[i][j] - 10;
            time = time % 100 >= 60 ? time - 40 : time;
            
            // 평일 지각
            if (time > schedules[i])
            {
                answer--;
                break;
            }
        }
    }
    
    return answer;
}