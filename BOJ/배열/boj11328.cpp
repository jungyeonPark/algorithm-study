// BOJ 11328번 Strfry
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        bool isValid = true;
        cin >> s1 >> s2;
        int arr[26];
        fill(arr, arr + 26, 0);
        if (s1.length() != s2.length())
        {
            cout << "Impossible" << '\n';
            continue;
        }
        for (auto c : s1)
            arr[c - 'a']++;
        for (auto c : s2)
            arr[c - 'a']--;
        for (auto n : arr)
        {
            if (n)
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
    }
    return 0;
}