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

int cnt = 0;
int ans = INT_MAX;
bool flag = false;

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;

    for(int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '-')
        {
            dfs(ci,cj);
        }
    }
}

int main()
{   cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];


    memset(vis, false, sizeof(vis));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] != '-')
            {
                dfs(i, j);
                ans = min(ans,cnt);
                cnt = 0;
                flag = true;
            }
        }
    
    if(flag)
        cout << ans << endl;
    else
    cout << -1 << endl;

    return 0;
}
