#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    int wallpaperRow = wallpaper.size();
    int wallpaperCol = wallpaper[0].size();
    
    vector<int> answer = {
        wallpaperRow + 1,
        wallpaperCol + 1,
        -1,
        -1
        };
    
    for (int i = 0; i < wallpaperRow; i++)
    {
        for (int j = 0; j < wallpaperCol; j++)
        {
            if (wallpaper[i][j] == '#')
            {
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i + 1);
                answer[3] = max(answer[3], j + 1);
            }
        }
    }
    
    return answer;
}