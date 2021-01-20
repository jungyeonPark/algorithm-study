// BOJ 1874번 스택 수열
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    // 인덱스를 따로 안두고 push_back으로 하고 싶어서 deque랑 vector사용
    // 인덱스 변수를 두고 그냥 배열로 해도 된다!
    deque<int> D;
    vector<char> ans;
    for (int i = 0; i < n; i++) // 만들어야 하는 수열
    {
        int a;
        cin >> a;
        D.push_back(a);
    }
    for (int i = 1; i <= n; i++) // 1부터 n까지 하나씩 오름차순으로 스택에 삽입
    {
        ans.push_back('+');
        S.push(i);
        if (S.top() == D.front()) // 만들어야 하는 수열의 앞과 같으면 스택에서 제거
        {
            ans.push_back('-');
            S.pop();
            D.pop_front();
            if (S.empty())
                continue;
            // 빈 스택이 아니면 다른 값이 나올때까지 계속 제거
            while (!S.empty())
            {
                if (S.top() != D.front())
                    break;
                ans.push_back('-');
                S.pop();
                D.pop_front();
            }
        }
    }
    if (!S.empty()) // 스택이 전부 제거되지 않았으면 스택으로 수열을 만들 수 없는 것
        cout << "NO" << '\n';
    else
    {
        for (auto c : ans)
            cout << c << '\n';
    }
    return 0;
}