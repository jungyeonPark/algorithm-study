// BOJ 10871번 X보다 작은 수
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, t;
    cin >> n >> x;
    while (n--) // for문을 안쓰고 이렇게도 할 수 있다!!
    {
        cin >> t;
        if (t < x)
            cout << t << ' '; // 굳이 배열에 저장해서 출력할 필요 없다
    }
    cout << "\n";
}