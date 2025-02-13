#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    
    // 현재 위치
    vector<int> currentLocation;
    
    int height = park.size();
    int width  = park[0].size();
    
    // 이동 방향
    unordered_map<char, vector<int>> move = {
        { 'E', { 0, 1 } },
        { 'W', { 0, -1 } },
        { 'S', { 1, 0 } },
        { 'N', { -1, 0 } }
    };
    
    // 시작 위치 찾기
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (park[i][j] == 'S')
            {
                currentLocation.push_back(i);
                currentLocation.push_back(j);
                break;
            }
        }
        
        if (!currentLocation.empty())
        {
            break;
        }
    }
    
    // 방향
    char moveTo = ' ';
    
    // 거리
    int distance = 0;
    vector<int> nextLocation;
    
    // 진행 방향에 장애물이 있는지 판별할 변수
    bool isGo = false;
    
    for (string route : routes)
    {
        // 파싱해서 방향과 거리 구하기
        moveTo = route.front();
        distance = route.back() - '0';
        
        nextLocation = currentLocation;
        
        isGo = true;
        
        // 다음 위치 좌표 구하기
        for (int i = 0; i < distance; i++)
        {
            for (int j = 0; j < nextLocation.size(); j++)
            {
                nextLocation[j] += move[moveTo][j];
            }
            
            // 장애물 or 공원 범위 밖
            if (nextLocation[0] < 0 || nextLocation[0] >= height || 
                nextLocation[1] < 0 || nextLocation[1] >= width || 
                park[nextLocation[0]][nextLocation[1]] == 'X')
            {
                isGo = false;;
                break;
            }
        }
        
        if (isGo)
        {
            currentLocation = nextLocation;
        }
    }
    
    return currentLocation;
}