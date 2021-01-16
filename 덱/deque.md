# 정의와 성질

## 덱의 정의

- 양쪽 끝에서 삽입과 삭제가 전부 가능
- deque는 Double Ended Queue라는 뜻
- Restricted Structure의 끝판왕

## 덱의 성질

1. 원소의 추가/제거가 O(1)
2. 제일 앞/뒤의 원소 확인이 O(1)
3. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
   - STL deque에서는 인덱스로 원소에 접근이 가능!!
     - vector과 비슷한 느낌

# 기능과 구현

- 연결리스트보다 배열로 구현하는 것이 더 쉬움
- 필요한 변수는 큐와 똑같이 배열 한개, 앞/뒤쪽을 가리킬 변수 두 개

```cpp
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;
```

- head는 가장 앞에 있는 원소의 인덱스, tail은 가장 뒤에 있는 원소의 인덱스 + 1
- head와 tail의 초깃값이 0이 아니라 배열의 중간

  - 덱에서는 앞, 뒤 양쪽에서 삽입과 삭제가 일어남
  - 여의봉처럼 양쪽으로 확장됨
  - 시작 지점을 0으로 두면 앞쪽으로는 확장 불가능

- 함수

  - push_front, push_back
  - pop_front, pop_back
  - front, back

- ex.cpp 참고

# STL deque

- 원소를 인덱스로 접근이 가능
- vector와 비슷한데 front에서도 O(1)에 추가/제거가 가능한 느낌이 강함
- vector과 상위호환?
  - deque는 vector와 달리 모든 원소들이 메모리 상에 연속하게 배치되어 있지 않음
  - deque의 생성시간이 vector보다 김
  - deque의 중간에서 삽입/삭제가 오래걸림
- 앞/뒤쪽에서의 추가와 제거가 모두 필요하면 deque사용, 배열과 같은 느낌으로 사용하고 싶으면 vector사용
- deque의 생성, 함수들
  - deque생성: deque\<int> DQ
  - x를 앞쪽에서 삽입: DQ.push_front(x)
  - x를 뒤쪽에서 삽입: DQ.push_back(x)
  - 크기 리턴: DQ.size()
  - 비어있으면 1, 아니면 0 리턴: DQ.empty()
  - 앞쪽에서 삭제: DQ.pop_front()
  - 뒤쪽에서 삭제: DQ.pop_back()
  - 맨 앞의 원소 리턴: DQ.front()
  - 맨 뒤의 원소 리턴: DQ.back()
  - k번째 원소: DQ[k]
  - 맨 앞에서 k번째 인덱스에 x삽입: DQ.insert(DQ.begin()+k, x)
  - 맨 앞에서 k번째 인덱스의 원소 제거: DQ.erase(DQ.begin()+k)
  - 모든 원소 제거: DQ.clear()

# 연습문제

## BOJ 10866번: 덱

- STL deque: BOJ/boj10866-1.cpp
- 직접 구현: BOJ/boj10866-2.cpp
