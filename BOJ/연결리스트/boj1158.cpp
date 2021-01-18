// BOJ 1158번 요세푸스 문제
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    list<int> L;
    for (int i = 1; i <= n; i++)
        L.push_back(i);
    list<int>::iterator t = L.begin();
    cout << '<';
    while (L.size() > 1)
    {
        // vector을 이용하면 for문을 쓰지 않고 인덱스로 나머지 연산
        // 지울 인덱스 = (현재 인덱스 + k-1) % 현재 벡터 크기
        for (int i = 0; i < k - 1; i++) // k만큼 옆으로 한 칸씩 감
        {
            if (t == L.end())  // 마지막 원소 다음을 가리키면
                t = L.begin(); // 맨 앞으로 감
            t++;
        }
        if (t == L.end()) // for문이 끝나고 한번 더 확인해야 함
            t = L.begin();
        cout << *t << ", ";
        t = L.erase(t);
    }
    cout << L.front() << '>' << '\n';
    return 0;
}
