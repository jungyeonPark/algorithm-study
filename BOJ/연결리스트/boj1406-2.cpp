// BOJ 1406번 에디터
// 시간 제한: 0.3초   -> N이 5000이 넘어서 O(N^2) 불가능
// 연결리스트로 해결(배열은 불가능)

// 야매 연결리스트
// 어렵다... 나중에 다시 풀어봐야될듯!!!!
#include <bits/stdc++.h>
using namespace std;

const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int &cur, char data)
{
    dat[unused] = data;
    pre[unused] = cur;
    nxt[unused] = nxt[cur];
    if (nxt[cur] != -1)
        pre[nxt[cur]] = unused;
    nxt[cur] = unused;
    unused++;
}

void erase(int &cur)
{
    nxt[pre[cur]] = nxt[cur];
    if (nxt[cur] != -1)
        pre[nxt[cur]] = pre[cur];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    string str;
    int n;
    // 커서가 지울 원소에 위치함(삽입할 원소의 앞)
    int cur = 0;
    cin >> str >> n;
    for (auto c : str)
    {
        insert(cur, c);
        cur++; // 커서 증가
    }
    while (n--)
    {
        char op;
        cin >> op;
        if (op == 'L')
        {
            if (pre[cur] != -1)
                cur = pre[cur];
        }
        else if (op == 'D')
        {
            if (nxt[cur] != -1)
                cur = nxt[cur];
        }
        else if (op == 'B')
        {
            if (cur != 0)
            {
                erase(cur);
                cur = pre[cur]; // 하나 지웠으니까 왼쪽으로 옮겨줘야 함
            }
        }
        else // P
        {
            char c;
            cin >> c;
            insert(cur, c);
            cur = nxt[cur]; // 하나 추가했으니까 오른쪽으로 옮겨줘야 함
        }
    }
    traverse();
    return 0;
}