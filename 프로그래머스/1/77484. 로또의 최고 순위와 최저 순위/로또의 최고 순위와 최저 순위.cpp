#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    
    int sameCount = 0;
    int zeroCount = 0;
    
    for (int lottosNumber : lottos) {
        
        // 번호 0
        if (lottosNumber == 0) {
            zeroCount++;
            continue;
        }
        
        // 번호 일치
        for (int winNumber : win_nums) {
            if (lottosNumber == winNumber) {
                sameCount++;
                break;
            }
        }
    }
    
    // 최고 순위
    answer[0] = 7 - sameCount - zeroCount == 7 ? 6 : 7 - sameCount - zeroCount;
    
    // 최저 순위
    answer[1] = 7 - sameCount == 7 ? 6 : 7 - sameCount;
    
    return answer;
}