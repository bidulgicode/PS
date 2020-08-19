/**
 * BOJ_11726_2×n 타일링
 * https://www.acmicpc.net/problem/11726
 * 1x2, 2x1 타일, 직사각형은 2*n
 * D[n] = 2*n 직사각형을 채우는 방법의 수
 * Top-Down 방식으로 풀어봄
 */

#include <bits/stdc++.h>
using namespace std;
// 1 <= n <= 1000
int d[1001];

int dp(int n) {
    if (n <= 1)
        return 1;
    if (d[n] != 0 && n >= 2)
        return d[n];

    return d[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << dp(n) << '\n';

    return 0;
}
