#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // sort
#include <string>

using namespace std;

int dfs(const vector<vector<int>> &field, vector<vector<bool>>& visit, int N, int i, int j) {
    // 연결된 단지의 수를 저장할 변수
    int count = 0;
    
    vector<int> moveX = { 1, -1, 0, 0 };
    vector<int> moveY = { 0, 0, 1, -1 };
    
    // 다음으로 가는 좌표를 담을 변수
    int nextX = 0;
    int nextY = 0;
    
    // 스택에서 꺼내온 좌표 저장할 변수
    vector<int> point(2);
            
    stack<vector<int>> dfs_stack;
    
    dfs_stack.push({ i, j });
            
    while (!dfs_stack.empty()) {
        point = dfs_stack.top();
        dfs_stack.pop();
        
        if (visit[point[0]][point[1]]) {
            continue;
        }
        
        visit[point[0]][point[1]] = true;
        count++;
        
        for (int k = 0; k < 4; k++) {
            nextX = point[1] + moveX[k];
            nextY = point[0] + moveY[k];
            
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && field[nextY][nextX] == 1 && !visit[nextY][nextX]) {
                dfs_stack.push({ nextY, nextX });
            }
        }
    }
    
    return count;
}

int main() {
	int N = 0;
	
	cin >> N;
	
	vector<vector<int>> field;
	
	// 입력 숫자가 공백이 없이 들어오므로 string으로 받기
	string numbers;

    for (int i = 0; i < N; i++) {
        field.push_back(vector<int> (N));
        
        cin >> numbers;
        
        for (int j = 0; j < N; j++) {
            field[i][j] = numbers[j] - '0';
        }
    }
    
    vector<vector<bool>> visit;
    
    for (int i = 0; i < N; i++) {
        visit.push_back(vector<bool> (N));
    }
    
    vector<int> answer;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(field[i][j] == 0 || visit[i][j]) {
                continue;
            }
            
            answer.push_back(dfs(field, visit, N, i, j));
            
            /*//중간 결과 출력
            for (int l = 0; l < N; l++) {
                for (int m = 0; m < N; m++) {
                    if (visit[l][m]) {
                        cout << "T";
                    }
                    else {
                        cout <<"F";
                    }
                }
                cout << endl;
            }
            cout << endl;
            */
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << endl;
    
    for (int ans : answer) {
        cout << ans << endl;
    }
}