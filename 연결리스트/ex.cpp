#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

// addr은 연결리스트에서 몇번째인지가 아니고 배열에서 몇번째 인덱스인지
void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) // addr이 맨 마지막 원소일 때를 제외해야함!!!
    {
        pre[nxt[addr]] = unused;
    }
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    // pre[addr]은 예외처리를 안해도 되는 이유?
    // -> 0번지 dummy node의 존재로 인해 pre[addr]은 무조건 -1이 아님이 보장됨!!
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) // 마찬가지로 addr이 맨 마지막 원소일 때 제외
        pre[nxt[addr]] = pre[addr];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test()
{
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test()
{
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void)
{
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}