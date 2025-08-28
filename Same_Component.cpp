#include<bits/stdc++.h>
using namespace std;

int n, m; 
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    
    for(int i = 0; i < 4; i++)
    {
        
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '-')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }

    int si, sj, ci, cj;
    cin >> si >> sj >> ci >> cj;

    memset(vis, false, sizeof(vis));

    if(!vis[si][sj] && grid[si][sj] == '.')
    {
        dfs(si, sj);
    }

    if(vis[ci][cj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    


    return 0;
}
