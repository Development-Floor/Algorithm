#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void bfs(unordered_map<int, vector<int>>& field, unordered_map<int, bool>& visit, int index)
{
    queue<int> bfs_queue;
    bfs_queue.push(index);
    visit[index] = true;
    
    while (!bfs_queue.empty())
    {
        for (int nextIndex : field[bfs_queue.front()])
        {
            if(!visit[nextIndex])
            {
                bfs_queue.push(nextIndex);
                visit[nextIndex] = true;
            }
        }
        bfs_queue.pop();
    }
}

int main()
{
	int N = 0;
	int M = 0;
	int count = 0;
	
	cin >> N >> M;
	
	int num1 = 0;
	int num2 = 0;
	
	unordered_map<int, vector<int>> field;
	unordered_map<int, bool> visit;
	
	for (int i = 0; i < M; i++)
	{
	    cin >> num1 >> num2;
	    
	    if (field.find(num1) != field.end())
	    {
	        field[num1].push_back(num2);
	    }
	    else
	    {
	        field[num1] = { num2 };
	        visit[num1] = false;
	    }
	    
	    if (field.find(num2) != field.end())
	    {
	        field[num2].push_back(num1);
	    }
	    else
	    {
	        field[num2] = { num1 }; 
	        visit[num2] = false;
	    }
	}
	
	for (pair<int, bool> vis : visit)
	{
	    if (!vis.second)
	    {
	        bfs(field, visit, vis.first);
	        ++count;
	    }
	}
	
	count = count + N - visit.size();
	
	cout << count;
    
    return 0;
}