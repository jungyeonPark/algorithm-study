// BOJ 10866번 덱
// STL deque

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> DQ;
    int n;
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        if (op == "push_front")
        {
            int x;
            cin >> x;
            DQ.push_front(x);
        }
        else if (op == "push_back")
        {
            int x;
            cin >> x;
            DQ.push_back(x);
        }
        else if (op == "pop_front")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
            {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if (op == "pop_back")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
            {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if (op == "size")
            cout << DQ.size() << '\n';
        else if (op == "empty")
            cout << (int)DQ.empty() << '\n';
        else if (op == "front")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.front() << '\n';
        }
        else // back
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.back() << '\n';
        }
    }
}