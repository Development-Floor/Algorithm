#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    // 짝꿍 비교를 위해 and 내림차순으로 큰 값 만들기
    sort(X.begin(), X.end(), greater<>());
    sort(Y.begin(), Y.end(), greater<>());
    
    int XIndex = 0;         // 반복문에서 X의 Iter
    int YIndex = 0;         // 반복문에서 Y의 Iter
    int XSize = X.size();   // X의 길이
    int YSize = Y.size();   // Y의 길이
    
    while (true)
    {
        // X or Y의 Iter가 끝에 도달했다면 break
        if(XIndex >= XSize || YIndex >= YSize)
        {
            break;
        }
        
        // X == Y 일 때, answer에 추가
        if (X[XIndex] == Y[YIndex])
        {
            answer += X[XIndex];
            XIndex++;
            YIndex++;
        }
        
        // X의 값이 변했을 때
        else if (X[XIndex] < Y[YIndex])
        {
            YIndex++;
        }
        
        // Y의 값이 변했을 때
        else if (X[XIndex] > Y[YIndex])
        {
            XIndex++;
        }
    }
    
    // 짝꿍이 존재하지 않을 때
    if (answer.empty())
    {
        answer = "-1";
    }
    
    // "00" -> "0"
    if (answer[0] == '0')
    {
        answer = "0";
    }
    
    return answer;
}