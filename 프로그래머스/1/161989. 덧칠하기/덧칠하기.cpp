#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int count = 1;
    
    int painted = section[0] + m - 1;
    
    for (int sec : section)
    {
        // 현재 구역이 안 칠해져있다면, 새로 칠하기
        if (sec > painted)
        {
            count++;
            painted = sec + m - 1;
        }
    }
    
    return count;
}