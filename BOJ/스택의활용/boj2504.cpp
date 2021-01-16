// BOJ 2504번 괄호의 값
// 괄호 안에있는거를 먼저 계산한 다음에 나중에 곱한다고 생각하지 말고 곱하기를 분배해서 생각
// 곱하기를 분배해서 식을 생각 했을 때 여는 괄호와 닫는 괄호가 연속해서 나오면 한 항이 끝난 것
// 이전에 나온 닫히지 않은 여는 괄호들이 항마다 곱해짐
// 어려워서 다른 분 코드 봤다..

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    bool isValid = true;
    int result = 0; // 총 계산 값
    int temp = 1;   // 곱하고 나누기로만 나타낼 것임
    stack<char> S;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            S.push('(');
            temp *= 2;
        }
        else if (str[i] == '[')
        {
            S.push('[');
            temp *= 3;
        }
        else if (str[i] == ')')
        {
            if (S.empty() || S.top() != '(') // 틀린 괄호 쌍일 때
            {
                isValid = false;
                break;
            }
            S.pop();
            if (str[i - 1] == '(') // 이전에 나온 괄호가 여는 괄호였으면
                result += temp;    // result에 더함
            temp /= 2;             // 이전 괄호와 상관없이 닫는 괄호가 나왔을 때는 무조건 temp값을 나눔
        }
        else // str[i] == ']'
        {
            if (S.empty() || S.top() != '[') // 틀린 괄호 쌍일 때
            {
                isValid = false;
                break;
            }
            S.pop();
            if (str[i - 1] == '[')
                result += temp;
            temp /= 3;
        }
    }
    if (!S.empty()) // 틀린 괄호 쌍일 때
        isValid = false;
    if (isValid)
        cout << result << '\n';
    else
        cout << 0 << '\n';
    return 0;
}