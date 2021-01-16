// BOJ 2480번 주사위 세개
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    if (arr[0] == arr[1] && arr[1] == arr[2])
        cout << 10000 + 1000 * arr[0];
    else if (arr[0] == arr[1])
        cout << 1000 + arr[0] * 100;
    else if (arr[1] == arr[2])
        cout << 1000 + arr[1] * 100;
    else if (arr[0] == arr[2])
        cout << 1000 + arr[0] * 100;
    else
    {
        auto i = max_element(arr, arr + 3);
        cout << *i * 100;
    }
    return 0;
}