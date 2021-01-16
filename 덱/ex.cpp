#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
// 덱이 양쪽으로 늘어나서 초깃값이 배열의 가운데
int head = MX, tail = MX; // head는 맨 앞 원소, tail은 맨 끝 원소 + 1

void push_front(int x)
{
    dat[--head] = x;
}

void push_back(int x)
{
    dat[tail++] = x;
}

void pop_front()
{
    head++;
}

void pop_back()
{
    tail--;
}

int front()
{
    return dat[head];
}

int back()
{
    return dat[tail - 1];
}

void test()
{
    push_back(30);           // 30
    cout << front() << '\n'; // 30
    cout << back() << '\n';  // 30
    push_front(25);          // 25 30
    push_back(12);           // 25 30 12
    cout << back() << '\n';  // 12
    push_back(62);           // 25 30 12 62
    pop_front();             // 30 12 62
    cout << front() << '\n'; // 30
    pop_front();             // 12 62
    cout << back() << '\n';  // 62
}

int main(void)
{
    test();
}