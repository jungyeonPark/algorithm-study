// BOJ 10845번 큐
// 직접 구현

#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;

int empty()
{
    if (tail - head == 0)
        return 1;
    else
        return 0;
}

void push(int x)
{
    dat[tail++] = x;
}

int pop()
{
    if (empty())
        return -1;
    else
        return dat[head++];
}

int size()
{
    return tail - head;
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
        if (op == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        else if (op == "pop")
            cout << pop() << '\n';
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