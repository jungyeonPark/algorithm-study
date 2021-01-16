// BOJ 2577번 숫자의 개수
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    string s = to_string(a * b * c);
    int arr[10];
    fill(arr, arr + 10, 0);
    for (auto c : s)
        arr[c - '0']++; // char을 int로 변환
    for (auto i : arr)
        cout << i << '\n';
    return 0;
}