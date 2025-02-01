#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int arr[5][5];
bool visited[5][5];

bool validpos(int i, int j)
{
    return (i >= 0 && i < 5 && j >= 0 && j < 5 && arr[i][j] == 0);
}

bool bfs()
{
    queue<pii> q;
    q.push(pii(0,0));

    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();

        visited[i][j] = true;
        
        if (i == 4 && j == 4) return true;

        if (validpos(i+1, j) && !visited[i+1][j]) q.push(pii(i+1,j));
        if (validpos(i, j+1) && !visited[i][j+1]) q.push(pii(i,j+1));
        if (validpos(i, j-1) && !visited[i][j-1]) q.push(pii(i,j-1));
        if (validpos(i-1, j) && !visited[i-1][j]) q.push(pii(i-1,j));
    }

    return false;
}

int main()
{
    int t; cin >> t;

    while (t--)
    {
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }

        bfs() ? cout << "COPS" << endl : cout << "ROBBERS" << endl;
    }
    
    return 0;
}