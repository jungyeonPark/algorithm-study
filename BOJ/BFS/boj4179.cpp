// BOJ 4179번 불!
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int vis1[1003][1003]; // 불
int vis2[1003][1003]; // 지훈
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // -1로 초기화
            vis1[i][j] = -1;
            vis2[i][j] = -1;
            // 불 시작점
            if (board[i][j] == 'F')
            {
                Q1.push({i, j});
                vis1[i][j] = 0;
            }
            // 지훈 시작점
            if (board[i][j] == 'J')
            {
                Q2.push({i, j});
                vis2[i][j] = 0;
            }
        }
    }
    // 불에 대한 BFS
    while (!Q1.empty())
    {
        pair<int, int> cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis1[nx][ny] != -1 || board[nx][ny] == '#')
                continue;
            vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    // 지훈에 대한 BFS
    while (!Q2.empty())
    {
        pair<int, int> cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 범위를 벗어나서 탈출에 성공
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << vis2[cur.X][cur.Y] + 1 << '\n';
                return 0;
            }
            if (vis2[nx][ny] != -1 || board[nx][ny] == '#')
                continue;
            // ** 지훈이 칸에 도달한 시간이 불이 전파된 시간보다 적거나 같으면 안됨
            // ** 불이 다 전파되지 못하는 경우도 있을 수 있으니까 -1이 아닐때도 확인해야 함!!
            if (vis1[cur.X][cur.Y] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1)
                continue;
            vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}