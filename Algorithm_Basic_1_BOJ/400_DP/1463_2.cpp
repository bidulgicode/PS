/**
 * BOJ_1463_1로 만들기 (Bottom-up(반복)방식)
 * https://www.acmicpc.net/problem/1463
 * 점화식 D[n] = n을 1로 만드는데 필요한 최소 연산 횟수
 * D[1]은 자명하게 0이다.
 * n에게 가능한 경우를 생각해보면
 * 1. n이 3으로 나누어 떨어지는 경우 -> D[n/3] + 1
 * 2. n이 2으로 나누어 떨어지는 경우 -> D[n/2] + 1
 * 3. n에서 1을 빼는 경우 -> D[n-1] + 1
 * 이 세값중의 최소 값이 정답이다.
 */
#include <iostream>
using namespace std;

// 1 <= N <= 1,000,000
int d[1000001];
int main() {
    int n;
    cin >> n;
    d[1] = 0; // 자명한 식
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
            d[i] = d[i / 2] + 1;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
            d[i] = d[i / 3] + 1;
        } 
    }
    cout << d[n] << '\n';
    return 0;
}