// BOJ 10828번 스택
// 직접 구현

#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX]; // 배열 이름을 stack으로 하면 안된다..
int pos = 0;

int empty() // empty함수를 호출하는 함수보다 위에 정의되어있어야 함
{
    if (pos > 0)
        return 0;
    else
        return 1;
}

void push(int n)
{
    dat[pos++] = n;
}

int pop()
{
    if (empty())
        return -1;
    else
        return dat[--pos];
}

int size()
{
    return pos;
}

int top()
{
    if (empty())
        return -1;
    else
        return dat[pos - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        else if (s == "pop")
            cout << pop() << '\n';
        else if (s == "size")
            cout << size() << '\n';
        else if (s == "empty")
            cout << empty() << '\n';
        else
            cout << top() << '\n';
    }
}
