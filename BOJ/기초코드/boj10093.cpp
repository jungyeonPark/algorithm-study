// 백준 10093번 숫자
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b; // 범위가 1~10^15 까지!! 자료형에 주의
    cin >> a >> b;
    if (a > b) // a>b일때 두개를 swap
        swap(a, b);
    if (a == b) // a == b일 때 따로 처리
        cout << 0 << '\n';
    else
    {
        cout << b - a - 1 << '\n';
        for (long long i = a + 1; i < b; i++)
            cout << i << ' ';
    }
    return 0;
}