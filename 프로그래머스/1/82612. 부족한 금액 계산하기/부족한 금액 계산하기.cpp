using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (2 * price + (count - 1) * (long long)price) * count / 2 - money;
    
    return answer < 0 ? 0 : answer;
}