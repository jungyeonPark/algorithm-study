// BOJ 7569번 토마토
// 3차원에서는 pair이 아닌 tuple 사용!!

#include <bits/stdc++.h>
using namespace std;

int board[103][103][103];
int vis[103][103][103];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dz[2] = {-1, 1}; // 현재 위치에서 위아래로만 움직이면 됨

int main(void)
{
    int m, n, h;
    int zeroCount = 0;
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> Q;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                {
                    Q.push({i, j, k});
                    vis[i][j][k] = 1;
                }
                else if (board[i][j][k] == 0)
                {
                    zeroCount++; // 모든 토마토가 익어있는 경우와 토마토가 모두 익지 못하는 상황을 계산하기 위함
                }
            }
        }
    }
    if (!zeroCount) // 모든 토마토가 익어있는 경우
    {
        cout << 0;
        return 0;
    }
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = get<2>(cur) + dx[j];
            int ny = get<1>(cur) + dy[j];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (abs(board[get<0>(cur)][ny][nx]) == 1 || vis[get<0>(cur)][ny][nx] >= 1)
                continue;

            Q.push({get<0>(cur), ny, nx});
            vis[get<0>(cur)][ny][nx] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            zeroCount--; // 토마토가 익을 때마다 -1해서 마지막에 0이 아니면 토마토가 모두 익지 못한 것
        }
        for (int i = 0; i < 2; i++)
        {
            int nz = get<0>(cur) + dz[i];

            if (nz < 0 || nz >= h)
                continue;
            if (abs(board[nz][get<1>(cur)][get<2>(cur)]) == 1 || vis[nz][get<1>(cur)][get<2>(cur)] >= 1)
                continue;
            Q.push({nz, get<1>(cur), get<2>(cur)});
            vis[nz][get<1>(cur)][get<2>(cur)] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            zeroCount--; // 토마토가 익을 때마다 -1
        }
    }
    if (zeroCount) // 토마토가 모두 익지 못하는 상황
    {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                ans = max(ans, vis[i][j][k]);
            }
        }
    }
    cout << ans - 1; // 처음부터 익어있던 토마토를 1일로 쳐서 -1해야 함
    return 0;
}
