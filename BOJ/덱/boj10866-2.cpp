// BOJ 10866번 덱
// 직접 구현

#include <bits/stdc++.h>
using namespace std;

const int MX = 10003;
int dat[2 * MX + 1];
int head = MX, tail = MX;

int empty()
{
    if (head == tail)
        return 1;
    else
        return 0;
}

void push_front(int x)
{
    dat[--head] = x;
}

void push_back(int x)
{
    dat[tail++] = x;
}

int front()
{
    if (empty())
        return -1;
    else
        return dat[head];
}

int back()
{
    if (empty())
        return -1;
    else
        return dat[tail - 1];
}

int pop_front()
{
    if (empty())
        return -1;
    else
        return dat[head++];
}

int pop_back()
{
    if (empty())
        return -1;
    else
        return dat[--tail];
}

int size()
{
    return tail - head;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
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
            push_front(x);
        }
        else if (op == "push_back")
        {
            int x;
            cin >> x;
            push_back(x);
        }
        else if (op == "pop_front")
            cout << pop_front() << '\n';
        else if (op == "pop_back")
            cout << pop_back() << '\n';
        else if (op == "size")
            cout << size() << '\n';
        else if (op == "empty")
            cout << empty() << '\n';
        else if (op == "front")
            cout << front() << '\n';
        else // back
            cout << back() << '\n';
    }
}