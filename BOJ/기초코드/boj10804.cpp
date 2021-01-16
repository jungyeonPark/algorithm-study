// BOJ 10804번 카드 역배치
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[21];
    for (int i = 0; i < 21; i++)
        arr[i] = i;
    for (int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        reverse(arr + a, arr + b + 1); // arr[b]까지 포함될라면 +1해야됨
        /*
        reverse함수 없을 때
        for (a; a < b; a++){
            swap(arr[a], arr[b]);
            b--;
        }
        */
    }
    for (int i = 1; i < 21; i++)
        cout << arr[i] << ' ';
    return 0;
}