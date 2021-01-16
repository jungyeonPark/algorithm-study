// BOJ 1475번 방 번호
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int arr[10];
    fill(arr, arr + 10, 0);
    for (auto c : s)
        arr[c - '0']++;
    int idx = 0, max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] >= max)
        {
            // max값과 arr[6]이나 arr[9]값이 같으면 인덱스를 업데이트하지 않음
            // 6이나 9말고 다른 인덱스값이 더 우선
            if (arr[i] == max && (i == 6 || i == 9))
                continue;
            max = arr[i];
            idx = i;
        }
    }
    if (idx == 6 || idx == 9)
        max = (arr[6] + arr[9] + 1) / 2; // 올림으로 계산해야되서 +1함(2로 나누는 것이므로)
    cout << max << '\n';
}