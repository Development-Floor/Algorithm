#include <string>
#include <utility>
#include <unordered_set>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    // 맵 크기
    const int mapSize = 5;
    
    // 현재 좌표
    pair<int, int> currentLocation(0, 0);
    
    // 다음 좌표
    pair<int, int> nextLocation(0, 0);
    
    // 지나온 경로
    unordered_set<string> route;
    
    for (char dir : dirs)
    {
        nextLocation = currentLocation;
        
        switch(dir)
        {
            case 'U':
                nextLocation.first++;
                break;
                
            case 'D':
                nextLocation.first--;
                break;
                
            case 'R':
                nextLocation.second++;
                break;
                
            case 'L':
                nextLocation.second--;
                break;
                
            default:
                break;
        }
        
        // 다음 좌표가 맵 밖이면 실행 넘어가기
        if (nextLocation.first > mapSize || nextLocation.first < -mapSize || nextLocation.second > mapSize || nextLocation.second < -mapSize)
        {
            continue;
        }
        
        // 지나간 경로인지
        string direction = to_string(currentLocation.first) + " " + to_string(currentLocation.second) + " " + to_string(nextLocation.first) + " " + to_string(nextLocation.second);
        
        if (route.find(direction) == route.end())
        {
            answer++;
            route.insert(direction);
            
            direction = to_string(nextLocation.first) + " " + to_string(nextLocation.second) + " " + to_string(currentLocation.first) + " " + to_string(currentLocation.second);
            route.insert(direction);
        }
        
        currentLocation = nextLocation;
    }
    
    return answer;
}