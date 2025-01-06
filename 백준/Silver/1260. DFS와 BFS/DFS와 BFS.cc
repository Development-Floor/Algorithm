#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int N = 0;
    int M = 0;
    int V = 0;

    cin >> N >> M >> V;

    unordered_map<int, vector<int>> point;

    for (int i = 0; i < N; i++) {
        point[i + 1] = vector<int>();
    }

    int point1 = 0;
    int point2 = 0;

    // 각 정점에 연결된 다른 정점을 벡터에
    for (int i = 0; i < M; i++) {
        cin >> point1 >> point2;

        point[point1].push_back(point2);
        point[point2].push_back(point1);
    }

    // 정렬
    for (int i = 0; i < N; i++) {
        sort(point[i + 1].begin(), point[i + 1].end());
    }

    /*
    * dfs 실행
    */
    vector<int> answer;
    stack<int> dfs_stack;
    vector<bool> dfs_visit(N + 1);

    dfs_stack.push(V);

    int currentPoint = 0;

    while (!dfs_stack.empty()) {
        currentPoint = dfs_stack.top();
        dfs_stack.pop();

        if (dfs_visit[currentPoint]) {
            continue;
        }

        dfs_visit[currentPoint] = true;
        answer.push_back(currentPoint);

        for (auto iter = point[currentPoint].rbegin(); iter != point[currentPoint].rend(); ++iter) {
            if (!dfs_visit[*iter]) {
                dfs_stack.push(*iter);
            }
        }
    }

    for (int num : answer) {
        cout << num << " ";
    }

    cout << endl;
    /*
    * bfs 실행
    */

    answer.clear();
    queue<int> bfs_queue;
    vector<bool> bfs_visit(N + 1);
    
    bfs_queue.push(V);
    bfs_visit[V] = true;
    answer.push_back(V);

    while (!bfs_queue.empty()) {
        currentPoint = bfs_queue.front();
        bfs_queue.pop();

        for (int num : point[currentPoint]) {
            if (!bfs_visit[num]) {
                bfs_queue.push(num);
                bfs_visit[num] = true;
                answer.push_back(num);
            }
        }
    }

    for (int num : answer) {
        cout << num << " ";
    }

    return 0;
}