/**
 * BOJ_11726_2×n 타일링
 * https://www.acmicpc.net/problem/11726
 * 1x2, 2x1 타일, 직사각형은 2*n
 * D[n] = 2*n 직사각형을 채우는 방법의 수
 */
#include <bits/stdc++.h>
using namespace std;
// 1 <= n <= 1000
// d[n] = d[n-1] + d[n-2];
// d[5] = d[4] + d[3] 을 보면 도형의 가장 우측이 1x2, 2x1 두개인지에 따라 두가지 경우로 갈림
// 가장 우측 도형을 제외하고 보면 각각 d[4] 또는 d[3]의 구성과 동일하다. 
int d[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    d[0] = 1; // 0은 딱히 의미가 없고, 아래 for문에서 d[2]를 2로 만들어 주기 위해
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= 10007;
    }
    cout << d[n] << '\n';
    return 0;
}
