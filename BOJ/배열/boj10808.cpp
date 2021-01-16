// BOJ 10808번 알파벳 개수
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    /*
    시간복잡도 O(N^2) 코드
    int cnt;
    for (char i = 'a'; i <= 'z'; i++)
    {
        cnt = 0;
        for (auto j : s)
            if (i == j)
                cnt++;
        cnt << cnt << " ";
    }
    */

    // O(N) 코드
    int freq[26];
    fill(freq, freq + 26, 0);
    for (auto c : s)
        freq[c - 'a']++; // 인덱스 0번부터 증가하게 할라고
    for (int i = 0; i < 26; i++)
        cout << freq[i] << ' ';
}