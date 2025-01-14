#include <vector>
#include <algorithm> // max, min

using namespace std;

int solution(vector<vector<int>> sizes) {
    int sizes_size = sizes.size();
    
    int maxWidth = 0;   //가로 최대 길이
    int maxHeight = 0;  //세로 최대 길이
    
    int width = 0;  //가로 - 긴 값이 들어감
    int height = 0; //세로 - 짧은 값이 들어감
    
    for (int i = 0; i < sizes_size; i++) {
        width = max(sizes[i][0], sizes[i][1]);
        height = min(sizes[i][0], sizes[i][1]);
        
        maxWidth = max(maxWidth, width);    
        maxHeight = max(maxHeight, height);
    }
    
    return maxWidth * maxHeight;
}