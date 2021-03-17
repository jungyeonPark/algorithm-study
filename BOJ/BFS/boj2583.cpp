// BOJ 2583번 영역 구하기
// define부분에 ;붙이지 않게 주의..(컴파일은 잘돼서 엄청 헤멨다..ㅠㅠㅠ)

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[103][103];
int vis[103][103];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k;
    cin >> n >> m >> k;
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                board[i][j] = 1;
            }
        }
    }
    int cnt = 0;   // 영역의 개수
    int area[103]; // 각 영역의 넓이를 넣을 배열
    fill(area, area + 103, 0);
    queue<pair<int, int>> Q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 0)
            {
                cnt++;
                area[cnt - 1]++;
                Q.push({i, j});
                vis[i][j] = 1;
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
                        if (vis[nx][ny] || board[nx][ny])
                            continue;
                        Q.push({nx, ny});
                        area[cnt - 1]++;
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    sort(area, area + cnt);
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << area[i] << ' ';
}