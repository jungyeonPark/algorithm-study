// BOJ 5397번 키로거
#include <bits/stdc++.h>
using namespace std;
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
        list<char> L;
        list<char>::iterator t = L.begin(); // auto t = L.begin()
        // 이터레이터가 삽입/삭제할 것의 뒤에 존재한다고 생각!!
        for (auto c : s)
        {
            if (c == '<')
            {
                if (t != L.begin())
                    t--;
            }
            else if (c == '>')
            {
                if (t != L.end())
                    t++;
            }
            else if (c == '-')
            {
                if (t != L.begin())   // 예외처리 주의
                    t = L.erase(--t); // erase는 현재 t위치를 삭제하므로 t를 한칸 앞으로 보내고 삭제
                                      // t를 업데이트 해줘야 함!!
                                      // 링크드리스트에서 가리키던 원소를 삭제하면 이터레이터는 가르키던 위치를 잃어버리게 된다!
            }
            else
                L.insert(t, c); // insert는 t의 앞에 삽입하는 함수
        }
        for (auto i : L)
            cout << i;
        cout << '\n';
    }
    return 0;
}