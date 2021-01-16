// 기초코드1 강의 연습문제2번
// 길이 N의 int배열에서 서로 다른 위치의 두 원소가 존재하면 1, 아니면 0리턴
// O(N^2)이였던 시간복잡도를 O(N)으로 바꿔보자!!

#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N)
{
    int tmp[101];
    fill(tmp, tmp + 101, 0);
    for (int i = 0; i < N; i++)
    {
        if (tmp[100 - arr[i]])
            return 1;
        tmp[arr[i]]++; // arr배열의 원소를 인덱스로 해서 나오면 1증가
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr1[3] = {1, 52, 48};
    int arr2[2] = {50, 42};
    int arr3[4] = {4, 13, 63, 87};
    cout << func2(arr1, 3) << '\n';
    cout << func2(arr2, 2) << '\n';
    cout << func2(arr3, 4) << '\n';
}
