#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    
    stack<int> ingredientStack;
    
    ingredientStack.push(-1);
    
    for (const int& element : ingredient)
    {
        int& currentTop = ingredientStack.top();
        
        if (currentTop == 1 && element == 2)
        {
            currentTop = 12;
        }
        
        else if (currentTop == 12 && element == 3)
        {
            currentTop = 123;
        }
        
        else if (currentTop == 123 && element == 1)
        {
            ingredientStack.pop();
            answer++;
        }
        
        else
        {
            ingredientStack.push(element);
        }
    }
    
    return answer;
}