int solution(int n, int w, int num)
{
    int answer = 1;
    int location = 0;
    int rowIndex = 0;
    int direction = 1;
    
    for (int index = 1; index <= n; ++index)
    {
        // num 택배의 위치 찾기
        if (index == num)
        {
            location = rowIndex;
        }
        
        // num 위의 택배 개수
        else if (index > num && location == rowIndex)
        {
            ++answer;
        }
        
        // 위치 변경
        rowIndex += direction;
        
        // 방향 변경
        if (rowIndex < 0 || rowIndex > w - 1)
        {
            direction *= -1;
            rowIndex += direction;
        }
    }
    
    return answer;
}