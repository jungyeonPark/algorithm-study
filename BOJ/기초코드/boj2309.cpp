
// BOJ 2309번 일곱 난쟁이
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[9];
    int sum = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i]; // 9개를 먼저 다 더하고
    }
    int i = 0, j = 0, endFlag = 0;
    for (i; i < 9; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            if (sum - arr[i] - arr[j] == 100) // 2개를 뺀 값이 100이면 0으로 만들고 루프 빠져나감
            {
                arr[i] = 0;
                arr[j] = 0;
                endFlag = 1;
                break;
            }
        }
        if (endFlag)
            break;
    }
    sort(arr, arr + 9);
    for (int i = 0; i < 9; i++)
    {
        if (arr[i])
            cout << arr[i] << '\n';
    }
}