/**
 * BOJ_11727_2xn 타일링 2
 * https://www.acmicpc.net/problem/11727
 * 2xn 타일링 1에서 2x2 타일이 추가된 버전
 * D[i-2] 연산이 한번 더 추가된 것임.
 * 재귀버전
 */
#include <bits/stdc++.h>
using namespace std;

// 1 <= n <= 1000
int d[1001];

int dp(int n) {
    if( n <= 1 )
        return 1;
    if(d[n] > 0)
        return d[n];

    return d[n] = (dp(n - 1) + dp(n - 2) * 2) % 10007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << dp(n) << '\n';

    return 0;
}
