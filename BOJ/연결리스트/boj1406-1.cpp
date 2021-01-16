// BOJ 1406번 에디터
// STL list

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char> L;
    string str;
    int n;
    cin >> str >> n;
    for (auto c : str)
        L.push_back(c);
    // L.end()를 하면 L의 마지막 원소가 아니고 그 다음 포인터임
    // 커서가 지울 원소의 뒤에 위치함(삽입할 원소의 뒤)
    list<char>::iterator cur = L.end(); // auto cur = L.end() 도 가능!(C++11 이상)
    while (n--)
    {
        char op;
        cin >> op;
        if (op == 'L')
        {
            if (cur != L.begin())
                cur--;
        }
        else if (op == 'D')
        {
            if (cur != L.end())
                cur++;
        }
        else if (op == 'B')
        {
            if (cur != L.begin())
            {
                cur--; // 커서가 지울거랑 삽입할거 뒤에!! 위치해서 먼저 커서를 앞으로 이동
                cur = L.erase(cur);
            }
        }
        else // P
        {
            char c;
            cin >> c;
            cur = L.insert(cur, c); // t의 앞!!에 삽입
            cur++;
        }
    }
    for (auto c : L)
        cout << c;
    cout << '\n';
}