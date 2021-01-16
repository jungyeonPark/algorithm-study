#include <bits/stdc++.h>
using namespace std;

// arr에 idx번째 인덱스에 num을 삽입하고 원래 idx번째부터 있던 원소들을 한 칸씩 뒤로 미는 함수
void insert(int idx, int num, int arr[], int &len)
{
    len++;
    // 오른쪽부터 i를 감소하면서 처리
    for (int i = len - 1; i > idx; i--) // i>=idx는 런타임 에러 발생 가능(idx=0일 때)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = num;
}

// arr에 idx번째 인덱스의 원소를 삭제하고 원래 idx번째부터 있던 원소들을 한 칸씩 앞으로 당기는 함수
void erase(int idx, int arr[], int &len)
{
    len--;
    // 왼쪽부터 i를 증가하면서 처리
    for (int i = idx; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void printArr(int arr[], int &len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << "\n\n";
}

void insert_test()
{
    cout << "***** insert_test *****\n";
    int arr[10] = {10, 20, 30};
    int len = 3;
    insert(3, 40, arr, len); // 10 20 30 40
    printArr(arr, len);
    insert(1, 50, arr, len); // 10 50 20 30 40
    printArr(arr, len);
    insert(0, 15, arr, len); // 15 10 50 20 30 40
    printArr(arr, len);
}

void erase_test()
{
    cout << "***** erase_test *****\n";
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    erase(4, arr, len); // 10 50 40 30 20
    printArr(arr, len);
    erase(1, arr, len); // 10 40 30 20
    printArr(arr, len);
    erase(3, arr, len); // 10 40 30
    printArr(arr, len);
}

int main(void)
{
    insert_test();
    erase_test();
}