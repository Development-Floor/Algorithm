#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int dfs(int N, unordered_map<int, int>& map) {
	int num = 0;
	int start = 0;
	int count = 0;
	int temp = 0;

	stack<int> dfs_stack;
	vector<bool> visit(N + 1);

	for (int i = 1; i <= N; i++) {
		if (visit[i]) {
			continue;
		}

		count++;

		start = num = i;
		dfs_stack.push(num);

		while (!dfs_stack.empty()) {
			temp = map[dfs_stack.top()];
			visit[dfs_stack.top()] = true;
			dfs_stack.pop();

			if (!visit[temp]) {
				dfs_stack.push(temp);
			}
		}
	}

	return count;
}

int main() {
	int T = 0;

	int N = 0;
	int num = 0;
	unordered_map<int, int> map;

	cin >> T;

	for (int i = 0; i < T; i++) {
		map.clear();

		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> num;
			map[j + 1] = num;
		}

		cout << dfs(N, map) << endl;;
	}

	return 0;
}