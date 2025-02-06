#include <string>

using namespace std;

string solution(string s, string skip, int index)
{
    // 소문자만 있기 때문에
    bool skipArray[26] = { false, };
    
    for (char skipChar : skip)
    {
        skipArray[skipChar - 'a'] = true;
    }
    
    for (char& sChar : s)
    {
        for (int i = 0; i < index; ++i)
        {
            sChar++;
            
            if (sChar > 'z')
            {
                sChar = 'a';
            }
            
            // 스킵 문자일 때
            if (skipArray[sChar - 'a'])
            {
                i--;
            }
        }
    }
    
    return s;
}