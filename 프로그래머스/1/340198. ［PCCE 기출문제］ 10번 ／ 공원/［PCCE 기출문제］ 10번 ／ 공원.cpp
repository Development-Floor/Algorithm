#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//park에서 제일큰 정사각형의 길이 반환
void FindPark(vector<vector<string>>& park, int& distance, int distance2, int x, int y) {
    if (x < park[0].size() - 1 && park[y][x + 1].compare("-1") == 0) {
        distance++;
        FindPark(park, distance, distance2 + 1, x + 1, y);
    }
    
    for (int i = 1; i < distance; i++) {
        if (y + i >= park.size() || park[y + i][x].compare("-1") != 0) {
            distance = distance2 - 1;
            break;
        }
    }
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int max = 0;
    int temp = 0;
    
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j].compare("-1") == 0) {
                temp = 1;
                
                FindPark(park, temp, 1, j, i);
                
                max = temp > max ? temp : max;
            }
        }
    }
    
    sort(mats.begin(), mats.end(), greater<>());
    
    for (int mat : mats) {
        if (mat <= max) {
            return mat;
        }
    }
    
    return -1;
}