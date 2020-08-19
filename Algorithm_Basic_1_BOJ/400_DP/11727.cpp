/**
 * BOJ_11727_2xn 타일링 2
 * https://www.acmicpc.net/problem/11727
 * 2xn 타일링 1에서 2x2 타일이 추가된 버전
 * D[i-2] 연산이 한번 더 추가된 것임.
 */
#include <bits/stdc++.h>
using namespace std;

int d[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    d[0] = 1, d[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 2];
        d[i] %= 10007;
    }
    cout << d[n] << '\n';
    return 0;
}
