#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // players[rank] = player
    vector<string> answer;
    
    // playerRank[player] = rank
    unordered_map<string, int> playerRank;
    
    for (int i = 0; i < players.size(); i++)
    {
        answer.push_back(players[i]);
        playerRank[players[i]] = i;
    }
    
    int currentRank = 0;
    string swapPlayer = "";
    
    for (string calling : callings)
    {
        // 바꾸기 전 등수
        currentRank = playerRank[calling];
        
        // answer 바꾸기
        swap(answer[currentRank - 1], answer[currentRank]);
        
        // playerRank 바꾸기
        swapPlayer = answer[currentRank];
        playerRank[calling]--;
        playerRank[swapPlayer]++;
    }
    
    return answer;
}