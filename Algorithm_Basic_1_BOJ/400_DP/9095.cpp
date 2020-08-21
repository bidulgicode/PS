/**
 * BOJ_9095_1,2,3 더하기
 * https://www.acmicpc.net/problem/9095
 * D[n] = D[n-1] + D[n-2] + D[n-3]
 * if n=4 -> 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1
 */

#include <bits/stdc++.h>
using namespace std;

// 0 < n < 11
int d[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    d[0] = 1; // start, base
    // d[1] = 1;
    for (int i = 1; i <= 10; i++) {
        if (i - 1 >= 0) {
            d[i] += d[i - 1];
        }
        if (i - 2 >= 0) {
            d[i] += d[i - 2];
        }
        if (i - 3 >= 0) {
            d[i] += d[i - 3];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}
