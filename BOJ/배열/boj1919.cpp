// BOJ 1919번 애너그램 만들기
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int arr[26];
    fill(arr, arr + 26, 0);
    for (auto c : s1)
        arr[c - 'a']++; // 첫번째 문자열에 들어있는 각 알파벳 개수를 셈
    int cnt = 0;        // 제거해야할 알파벳 개수
    for (auto c : s2)
    {
        if (arr[c - 'a'] == 0) // 두번째 문자열에 들어있는 알파벳이 첫번째에는 없을 때 제거해야 할 개수 증가
            cnt++;             // 바킹독님 코드 보니까 그냥 0일때도 마이너스하고 아래 for문에서 절댓값으로 한꺼번에 계산하더라..!
        else                   // 첫번째랑 두번째에 같은 문자열이 있을 때
            arr[c - 'a']--;
    }
    for (auto i : arr) // 첫번째 문자열에 들어있는 알파벳이 두번째 문자열에는 없을 때
        cnt += i;
    cout << cnt << '\n';
}