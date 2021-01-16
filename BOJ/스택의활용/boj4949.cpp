// BOJ 4949번 균형잡힌 세상
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        string str;
        int flag = 0; // 괄호 쌍이 안맞으면 1
        getline(cin, str);
        stack<char> S;
        if (str == ".")
            return 0;
        for (auto c : str)
        {
            if (c == '.')
                break;
            else if (c == '(' || c == '[') // 열린 괄호면 스택에 push
                S.push(c);
            else if (c == ')')
            {
                // 런타임 에러 방지를 위해 스택이 비었는지 확인
                // Short-circuit evaluation: 앞의 식을 확인하고 true일 경우 뒤의 식을 확인하지 않고 if문 명령 수행
                if (!S.empty() && S.top() == '(')
                    S.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!S.empty() && S.top() == '[')
                    S.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag && S.empty()) // 플래그가 1이 아니고 스택 쌍이 다 맞아서 비어있음
            cout << "yes" << '\n';
        else
        {
            cout << "no" << '\n';
            flag = 0;
        }
    }
    return 0;
}