#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int cards1Index = 0;
    int cards2Index = 0;
    
    for (int i = 0; i < goal.size(); i++) {
        if (goal[i] == cards1[cards1Index]) {
            cards1Index++;
        }
        
        else if (goal[i] == cards2[cards2Index]) {
            cards2Index++;
        }
        
        else {
            return "No";
        }
    }
    
    return "Yes";
}