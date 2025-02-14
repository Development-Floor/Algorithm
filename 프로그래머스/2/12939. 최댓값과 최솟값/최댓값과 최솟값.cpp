#include <string>
#include <sstream>

using namespace std;

string solution(string s)
{
    // 문자열을 입력 스트림으로 변환
    istringstream ss(s);
    
    // 파싱된 숫자
    int currentNumber;
    
    // 첫 번째 숫자로 최댓값, 최솟값 초기화
    ss >> currentNumber;
    int minNumber = currentNumber;
    int maxNumber = currentNumber;
    
    // 최댓값, 최솟값 구하기
    while (ss >> currentNumber)
    {
        minNumber = min(minNumber, currentNumber); // 최솟값 갱신
        maxNumber = max(maxNumber, currentNumber); // 최댓값 갱신
    }
    
    // 결과 문자열 만들기
    return to_string(minNumber) + " " + to_string(maxNumber);
}