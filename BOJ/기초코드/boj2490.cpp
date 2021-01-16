// BOJ 2490번 윷놀이
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        for (int j = 0; j < 4; j++)
        {
            int n;
            cin >> n;
            if (n == 1)
                count++;
        }
        if (count == 4)
            cout << 'E' << '\n';
        else if (count == 3)
            cout << 'A' << '\n';
        else if (count == 2)
            cout << 'B' << '\n';
        else if (count == 1)
            cout << 'C' << '\n';
        else
            cout << 'D' << '\n';
    }
}