// BOJ 10807번 개수 세기
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, temp;
    int arr[201];
    fill(arr, arr + 201, 0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp + 100]++;
    }
    cin >> v;
    cout << arr[v + 100] << '\n';
}