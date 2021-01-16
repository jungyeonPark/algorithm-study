// BOJ 1697번 숨바꼭질
#include <bits/stdc++.h>
using namespace std;

int n, k;
// 수빈이와 동생의 위치가 0에서 100,000사이라고 했지
// 수빈이가 이동 중에 반드시 0에서 100,000사이에만 있어야 한다는 조건은 없음!!!
// -> 멋대로 0부터 100,000사이라고 가정하고 문제를 풀지 말 것!!
// -> 하지만 이 문제에서는 100,000을 넘어가는 것이 손해이기 때문에 0에서 100,000사이로 풀면 답이 나옴
int vis[100002];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    queue<int> Q;
    fill(vis, vis + 100002, -1);
    vis[n] = 0;
    Q.push(n);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        /*
        원래 작성한 코드
        int n1 = cur - 1;
        int n2 = cur + 1;
        int n3 = 2 * cur;
        if (n1 >= 0 && vis[n1] == -1)
        {
            vis[n1] = vis[cur] + 1;
            Q.push(n1);
        }
        if (n2 <= 100000 && vis[n2] == -1)
        {
            vis[n2] = vis[cur] + 1;
            Q.push(n2);
        }
        if (n3 <= 100000 && vis[n3] == -1)
        {
            vis[n3] = vis[cur] + 1;
            Q.push(n3);
        }
        */
        for (int dir : {cur - 1, cur + 1, 2 * cur}) // range-based for 이용
        {
            if (dir < 0 || dir > 100000)
                continue;
            if (vis[dir] != -1)
                continue;
            // 현재 위치에서 -1, +1, *2해서 갈 수 있는 위치를 현재 시간+1로 계산
            vis[dir] = vis[cur] + 1;
            Q.push(dir);
        }
    }
    cout << vis[k] << '\n';
}