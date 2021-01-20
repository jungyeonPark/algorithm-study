// BOJ 1012번 유기농 배추
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[51][51];
int vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        queue<pair<int, int>> Q;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1 && vis[i][j] != 1)
                {
                    Q.push({i, j});
                    vis[i][j] = 1;
                    cnt++;
                    while (!Q.empty())
                    {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                                continue;
                            if (vis[nx][ny] == 1 || board[nx][ny] == 0)
                                continue;
                            Q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
        // 테스트 케이스가 여러개일 수 있으므로 초기화 해야 함!!
        for (int i = 0; i < 51; i++)
        {
            fill(board[i], board[i] + 51, 0);
            fill(vis[i], vis[i] + 51, 0);
        }
    }
}