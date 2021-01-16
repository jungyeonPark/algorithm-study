// BOJ 13300번 방 배정
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[2][6];
    for (int i = 0; i < 2; i++)
        fill(arr[i], arr[i] + 6, 0);
    while (n--)
    {
        int s, y;
        cin >> s >> y;
        arr[s][y - 1]++;
    }
    int count = 0; // 방 개수
    for (int i = 0; i < 6; i++)
    {
        // 다 k로 나눈거를 올림으로 더하면 됨
        // 이중for문 해도 되는데 한개로 끝내려고 이렇게 한듯(바킹독님꺼 보고 바꿈)
        count += arr[0][i] / k + arr[1][i] / k;
        // 올림으로 계산해야하므로
        if (arr[0][i] % k > 0)
            count++;
        if (arr[1][i] % k > 0)
            count++;
    }
    cout << count << '\n';
}