// BOJ_2747_피보나치 수
#include <iostream>
using namespace std;

// 피보나치 수 예시
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
// 이전 방법이 너무 느리기 때문에 메모이제이션을 추가한 방법

int memo[50];
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else if (memo[n] != 0)
    {
        return memo[n]; // n에대한 피보나치수를 구해놨다면 이것을 리턴
    }
    else
    {
        // 구해놓은 n에대한 피보나치수를 memo 배열에 저장
        // 모든 n에 대해서 한번만 계산하니깐 복잡도는 O(N)
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';

    return 0;
}
