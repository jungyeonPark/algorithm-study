// BOJ 10828번 스택
// STL stack

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push") // c에서는 문자열 비교할때 ==쓰면 안되는데 c++은 연산자 오버로딩때매 된다
        {
            int num;
            cin >> num;
            S.push(num);
        }
        else if (s == "pop")
        {
            if (S.empty()) // 원래 size()로 비교했는데 empty()가 훨씬 나은듯
                cout << -1 << '\n';
            else
            {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if (s == "size")
        {
            cout << S.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << (int)S.empty() << '\n'; // int로 형변환 해도 되고 안해도 되는듯?
        }
        else // top
        {
            if (S.empty())
                cout << -1 << '\n';
            else
                cout << S.top() << '\n';
        }
    }
}
