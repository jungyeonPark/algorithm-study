/*
    코드의 시간복잡도를 예제를 통해 익혀보자!!
*/

#include <iostream>
using namespace std;

// 1. N이하의 자연수 중 3의 배수이거나 5의 배수인 수를 모두 합한 값을 반환
// O(N)
int func1(int N)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 5 == 0 || i % 3 == 0)
            sum += i;
    }
    return sum;
}

// 2. 길이 N의 int배열에서 서로 다른 위치의 두 원소가 존재하면 1, 아니면 0리턴
// O(N^2)
int func2(int arr[], int N)
{
    for (int i = 0; i < N; i++) // O(N)
    {
        for (int j = i + 1; j < N; j++) // O(N-1)
        {
            if (arr[i] + arr[j] == 100)
                return 1;
        }
    }
    return 0;
}

// 3. N이 제곱수이면 1, 아니면 0리턴
// O(√N)
int func3(int N)
{
    for (int i = 0; i * i <= N; i++) // i * i <= N 이거 틀림
    {
        if (N == i * i)
            return 1;
    }
    return 0;
}

// 4. N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환
// O(lgN)
int func4(int N)
{
    int val = 1;
    while (2 * val <= N) // 2 * val 이거도 틀림
        val *= 2;
    return val;
}

int main()
{
    int n;
    cin >> n;
    cout << func4(n) << '\n';
}