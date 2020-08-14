/**
 * BOJ_1463_1로 만들기 (Top-Down(재귀) 방식)
 * https://www.acmicpc.net/problem/1463
 * D[n] = n을 1로 만드는데 필요한 최소 연산 횟수
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

int dp(int n) {
    if (n == 1) { // base case -> 재귀탈출조건, 이 문제 N의 최소값
        cout << "now : " << n << " -> return 0" << '\n';
        return 0;
    }
    if (d[n] > 0) {
        cout << "now : " << n << " -> return " << d[n] << '\n';
        return d[n];
    }
    d[n] = dp(n - 1) + 1;  // -1은 어느수가 와도 적용 가능
    if (n % 2 == 0) {
        int temp = d[n / 2] + 1; // 최단경로 찾을때 옆칸 거리에 +1 해주는 느낌임
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    if (n % 3 == 0) {
        int temp = d[n / 3] + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    cout << "now : " << n << " -> return " << d[n] << '\n';
    return d[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << dp(n) << '\n';
    return 0;
}

/*
최단경로 찾는거와 똑같네
10
now : 1 -> return 0
now : 2 -> return 1
now : 3 -> return 1
now : 4 -> return 2
now : 5 -> return 3
now : 6 -> return 2
now : 7 -> return 3
now : 8 -> return 3
now : 9 -> return 2
now : 10 -> return 3
3
*/