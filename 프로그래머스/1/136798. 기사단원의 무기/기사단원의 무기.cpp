#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;
    int count = 0;
    
    for (int i = 1; i <= number; i++)
    {
        count = 0;
        
        // 약수의 개수 구하기
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                count++;
                
                if (j != i / j)
                {
                    count++;
                }
            }
        }
        
        // 개수가 limit 초과
        if (count > limit)
        {
            answer += power;
        }
        
        // 개수가 limit 초과x
        else
        {
            answer += count;
        }
    }
    
    return answer;
}