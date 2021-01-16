// BOJ 2445번 별 찍기-8
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < i || j > 2 * n - 1 - i)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < i || j > 2 * n - 1 - i)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}