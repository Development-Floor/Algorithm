#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& field, vector<vector<int>>& visit, int N, int hei, int i, int j) {
    queue<vector<int>> bfs_queue;
    
    bfs_queue.push({ i, j });
    
    visit[i][j] = hei;
    
    int moveX[4] = { 1, -1, 0, 0 };
    int moveY[4] = { 0, 0, 1, -1 };
    
    vector<int> point;
    
    int X = 0;
    int Y = 0;
    
    while (!bfs_queue.empty()) {
        point = bfs_queue.front();
        bfs_queue.pop();
        
        for (int i = 0; i < 4; i++) {
            X = point[1] + moveX[i];
            Y = point[0] + moveY[i];
            
            if (X >= 0 && Y >=0 && X < N && Y < N && field[Y][X] > hei && visit[Y][X] < hei) {
                bfs_queue.push({ Y, X });
                visit[Y][X] = hei;
            }
        }
    }
}

int main() {
	int N = 0;
	int count = 0;
	int maxCount = 0;
	
	cin >> N;
	
	vector<vector<int>> field(N);
	set<int> heights;
	
	int height;
	
	for (int i = 0; i < N; i++) {
	    for (int j = 0; j < N; j++) {
	        cin >> height;
	        field[i].push_back(height);
	        heights.insert(height);
	    }
	}
	
	vector<vector<int>> visit;
	
	for (int i = 0; i < N; i++) {
	    visit.push_back(vector<int>(N));
	}
	
	for (int hei : heights) {
	    count = 0;
	    for (int i = 0; i < N; i++) {
    	    for (int j = 0; j < N; j++) {
    	        if (field[i][j] <= hei || visit[i][j] >= hei) {
    	            continue;
    	        }
    	        
    	        bfs(field, visit, N, hei, i, j);
    	        count++;
    	    }
	    }
	    
	    maxCount = count > maxCount ? count : maxCount;
	}
	
	maxCount = maxCount == 0 ? 1 : maxCount;
	
	cout << maxCount;
}	