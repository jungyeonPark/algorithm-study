// BOJ 10799번 쇠막대기
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    stack<char> S;
    int count = 0; // 총 막대기 조각 개수
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            S.push('(');
        else if (str[i] == ')')
        {
            S.pop();
            if (str[i - 1] == '(')
                count += S.size(); // 스택의 크기가 현재 잘려나간 쇠막대기 개수
            else
                count++; // 레이저가 아니고 막대기 하나 길이가 끝났을 때
        }
    }
    cout << count << '\n';
    return 0;
}