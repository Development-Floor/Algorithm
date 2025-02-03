#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    // 각 번호의 default 개수 1
    vector<int> PE(n + 2, 1);
    
    // 0번과 n + 1번은 계산 편의를 위해 추가, 0 할당
    PE[0] = 0;
    PE[n + 1] = 0;
    
    // 체육복 도난
    for (int& lostNumber : lost)
    {
        PE[lostNumber]--;
    }
    
    // 여벌 체육복
    for (int& reserveNumber : reserve)
    {
        PE[reserveNumber]++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        // 체육복 있음
        if (PE[i] >= 1)
        {
            continue;
        }
        
        // 앞 번호에서 빌림
        if (PE[i - 1] >= 2)
        {
            PE[i - 1]--;
            PE[i]++;
        }
        
        // 앞 번호 없으면 뒷 번호에서 빌림
        else if (PE[i + 1] >= 2)
        {
            PE[i + 1]--;
            PE[i]++;
        }
        
        // 못 빌림
        else
        {
            answer--;
        }
    }
    
    return answer;
}