#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    const int mapHeight = board.size();
    
    stack<int> st;
    
    for (int move : moves)
    {
        move--;
        
        for (int i = 0; i < mapHeight; i++)
        {
            if (board[i][move])
            {
                int& doll = board[i][move];
                
                if (st.empty() || st.top() != doll)
                {
                    st.push(doll);
                }
                
                else
                {
                    st.pop();
                    answer += 2;
                }
                
                doll = 0;
                break;
            }
        }
    }
    
    return answer;
}

int solution2(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> array;
    
    int temp = 0;
    
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                temp = moves[i] - 1;
                
                if (array.size() > 0 && array.back() == board[j][temp]) {
                    array.pop_back();
                    
                    answer += 2;
                }
                
                else {
                    array.push_back(board[j][temp]);
                }
                
                board[j][temp] = 0;
                
                break;
            }
        }
    }
    
    return answer;
}