#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//연결된 블록을 들어가는 재귀함수
void SumArea(vector<string>& maps, int x, int y, int& sum) {
    sum = sum + maps[y][x] - '0';
    
    maps[y][x] = ' ';
    
    //왼쪽으로
    if (x > 0 && maps[y][x - 1] != 'X' && maps[y][x - 1] != ' ') {
        SumArea(maps, x - 1, y, sum);
    }
    
    //위로
    if (y > 0 && maps[y - 1][x] != 'X' && maps[y - 1][x] != ' ') {
        SumArea(maps, x, y - 1, sum);
    }
    
    //오른쪽으로
    if (x < maps[0].size() - 1 && maps[y][x + 1] != 'X' && maps[y][x + 1] != ' ') {
        SumArea(maps, x + 1, y, sum);
    }
    
    //아래로
    if (y < maps.size() - 1 && maps[y + 1][x] != 'X' && maps[y + 1][x] != ' ') {
        SumArea(maps, x, y + 1, sum);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int sum = 0;
    
    // 왼쪽 위에서 오른쪽 아래로 가면서 섬 탐색
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] != 'X' && maps[i][j] != ' ') {
                sum = 0;
                
                SumArea(maps, j, i, sum);
                
                answer.push_back(sum);
            }
        }
    }
    
    //섬이 없다면 -1 넣기
    if (answer.size() == 0) {
        answer.push_back(-1);
    }
    
    //오름차순 정렬차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}