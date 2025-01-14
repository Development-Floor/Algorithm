#include <vector>
#include <algorithm> // max, min

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;   //가로 최대 길이
    int maxHeight = 0;  //세로 최대 길이
    
    int width = 0;  //가로 - 긴 값이 들어감
    int height = 0; //세로 - 짧은 값이 들어감
    
    for (vector<int> size : sizes) {
        width = max(size[0], size[1]);
        height = min(size[0], size[1]);
        
        maxWidth = max(maxWidth, width);    
        maxHeight = max(maxHeight, height);
    }
    
    return maxWidth * maxHeight;
}