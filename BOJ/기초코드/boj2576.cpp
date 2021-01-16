// BOJ 2576번 홀수
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 0, min = 100;
    for (int i = 0; i < 7; i++)
    {
        cin >> n;
        if (n % 2 == 1)
        {
            if (n < min)
                min = n;
            sum += n;
        }
    }
    if (sum)
    {
        cout << sum << '\n'
             << min << '\n';
    }
    else
        cout << -1 << '\n';
}