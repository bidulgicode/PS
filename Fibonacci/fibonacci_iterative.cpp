// BOJ_2748_피보나치 수 2
#include <iostream>
using namespace std;

// 피보나치 수 예시
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
// Bottom-up or iterative 반복적인 방법(for)문으로 풀어보자
// n이 90정도가 되면 수가 int 범위를 초과한다.

long long fibo[100] = {0, 1}; // 0~1번째 수는 미리 넣어둠
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout << fibo[n] << '\n';

    return 0;
}
