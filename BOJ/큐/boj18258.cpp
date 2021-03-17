// BOJ 18258번 큐2

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> Q;
    while (n--)
    {
        string com;
        cin >> com;
        if (com == "push")
        {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if (com == "pop")
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (com == "size")
            cout << Q.size() << '\n';
        else if (com == "empty")
            cout << Q.empty() << '\n';
        else if (com == "front")
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.front() << '\n';
        }
        else // com == "back"
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.back() << '\n';
        }
    }
    return 0;
}