// BOJ 7576번 토마토
// 행, 열 잘 확인하기!!
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1003][1003];
int vis[1003][1003];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int>> Q;
    // vis의 -1은 방문안한 토마토, 0은 시작점이거나 토마토가 없는 칸
    // 1이상은 익는데 걸리는 날짜 수
    // 전역변수로 선언해서 0으로 초기화되어있음
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({i, j}); // **시작점이 여러개인 경우 미리 큐에 넣어놓음!!**
            if (board[i][j] == 0)
                vis[i][j] = -1;
        }
    }
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
            if (vis[nx][ny] != -1)
                continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << vis[i][j] << ' ';
    //     cout << '\n';
    // }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 토마토가 모두 익지 못하는 상황 예외처리
            if (vis[i][j] == -1)
            {
                cout << -1 << '\n';
                return 0;
            }
            // 익는데 가장 많은 일수가 필요한 토마토 찾아냄
            // 전부 익은 토마토이면 0
            ans = max(ans, vis[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}