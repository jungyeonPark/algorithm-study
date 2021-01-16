#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos] = x;
    pos++;
    // dat[pos++] = x; 와 같이 한줄로 표현 가능!!!
}

void pop()
{
    pos--; // dat[pos]는 굳이 지우지 않아도 된다!!!  -> 어차피 다음 값이 들어오면 덮어씌워지기 때문!!
}

int top()
{
    /*
    왜 이렇게 복잡하게 했을까...
    int top;
    pos--;
    top = dat[pos];
    pos++;
    return top;
    */
    return dat[pos - 1];
}

void test()
{
    push(5);
    push(4);
    push(3);
    cout << top() << '\n'; // 3
    pop();
    pop();
    cout << top() << '\n'; // 5
    push(10);
    push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main(void)
{
    test();
}