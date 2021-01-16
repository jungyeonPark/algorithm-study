// BOJ 2178번 미로 탐색
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[103][103];
int vis[103][103];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }
    // 0으로 초기화
    for (int i = 0; i < 103; i++)
        fill(vis[i], vis[i] + 103, 0);
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 0 || vis[nx][ny])
                continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1; // **중심에서 그 주변의 칸들은 중심에서 거리 + 1
            Q.push({nx, ny});
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << vis[i][j];
    //     cout << '\n';
    // }
    cout << vis[n - 1][m - 1] << '\n';
    return 0;
}