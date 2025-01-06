#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int row = 0;
	int col = 0;

	cin >> col >> row;

	vector<vector<int>> field(col, vector<int> (row));

	string inputString = "";

	for (int i = 0; i < col; i++) {
		cin >> inputString;

		for (int j = 0; j < row; j++) {
			field[i][j] = inputString[j] - '0';
		}
	}

	int x = 0;
	int y = 0;

	int xMove[4] = { 1, -1, 0, 0 };
	int yMove[4] = { 0, 0, 1, -1 };

	queue<vector<int>> bfs;

	bfs.push({ 0, 0 });

	int tempX = 0;
	int tempY = 0;

	int prevX = 1;
	int prevY = 1;

	while (!bfs.empty()) {
		prevX = x;
		prevY = y;
		x = bfs.front()[1];
		y = bfs.front()[0];
		bfs.pop();

		for (int i = 0; i < 4; i++) {
			tempX = x + xMove[i];
			tempY = y + yMove[i];

			if (tempX == prevX && tempY == prevY) {
				continue;
			}

			if (tempX >= 0 && tempX < row && tempY >= 0 && tempY < col && field[tempY][tempX] != 0) {
				if (field[tempY][tempX] == 1 || field[tempY][tempX] > field[y][x] + 1) {
					field[tempY][tempX] = field[y][x] + 1;
					bfs.push({ tempY, tempX });
				}
			}
		}
	}

	cout << field[col - 1][row - 1];

	return 0;
}