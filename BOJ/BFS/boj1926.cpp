// BOJ 1926번 그림
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int cnt = 0, max_size = 0;
    // 이중 for문으로 BFS의 시작점이 될 수 있는 곳들을 찾아냄
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 || vis[i][j])
                continue;
            queue<pair<int, int>> Q;
            int cur_size = 0;
            cnt++; // 그림의 개수를 셈
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                cur_size++; // pop하는 개수랑 push하는 개수랑 어차피 같으니까 pop이나 push중 아무데나 해도 됨
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (board[nx][ny] == 0 || vis[nx][ny])
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            max_size = max(max_size, cur_size);
        }
    }
    cout << cnt << '\n'
         << max_size;
    return 0;
}