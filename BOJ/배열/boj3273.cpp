// BOJ 3273번 두 수의 합
// 시간복잡도가 N^2이면 안됨
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[1000005];
    fill(arr, arr + 1000005, 0);
    // 입력이 들어온 index는 1증가
    while (n--)
    {
        int input;
        cin >> input;
        arr[input]++;
    }
    int x;
    cin >> x;
    int cnt = 0;
    for (int i = 1; i < x; i++)
    {
        // i번째 인덱스와 x-1번째 인덱스 둘다 입력되었던 값이면 카운트 증가
        if (arr[i] && arr[x - i] && i != x - i) // 같은 값을 가지는 쌍을 방지해야 함 ex)(5,5)
        {
            cnt++;
            // 카운트 세고 나면 1감소해서 0으로 만듬
            arr[i]--;
            arr[x - i]--;
        }
    }
    cout << cnt << '\n';
    return 0;
}