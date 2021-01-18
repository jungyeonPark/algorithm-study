// BOJ 10773번 제로
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    stack<int> S;
    while (k--)
    {
        int n;
        cin >> n;
        if (n == 0) // 0이면 pop
            S.pop();
        else // 0이 아니면 push
            S.push(n);
    }
    int ans = 0;
    // STL 스택은 vector, list처럼 이터레이터로 출력할 수 없음
    // 스택의 정의에 의해 이터레이터를 가지지 않는다!
    while (!S.empty())
    {
        ans += S.top();
        S.pop();
    }
    cout << ans << '\n';
    return 0;
}