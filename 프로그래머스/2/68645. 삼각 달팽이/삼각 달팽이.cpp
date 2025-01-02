#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> triangle;
    
    vector<vector<int>> arr;
    
    // 삼각형 만들기 - 0으로 초기화
    for (int i = 1; i <= n; i++) {
        arr.push_back(vector<int> (i));
    }
    
    // 방향
    int direction = 0;
    // 방향의 길이
    int distance = n--;
    
    int x = 0;
    int y = -1;
    
    int number = 1;
    
    while (n >= 0) {
        // 밑으로
        if (direction == 0) {
            ++y;
        }
        // 오른쪽
        else if (direction == 1) {
            ++x;
        }
        // 왼쪽위 대각선
        else if (direction == 2) {
            --x;
            --y;
        }
        
        arr[y][x] = number++; // 각 위치에 숫자 넣기
        
        distance--;
        
        if (distance != 0) {
            continue;
        }
        
        // 거리만큼 이동했다면 다음 거리 넣기
        distance = n--;
        // 방향 바꾸기
        direction = direction == 2 ? 0 : direction + 1;
    }
    
    // 2차원 배열을 1차원으로 바꿔주기
    for (vector<int> brr : arr) {
        for (int num : brr) {
            triangle.push_back(num);
        }
    }
    
    return triangle;
}