/**
 * BOJ_2004_조합 0의 개수
 * https://www.acmicpc.net/problem/2004
 * 
 * 범위 최대치가 2,000,000,000 이므로 longlong사용
 * 조합 공식 nCm = n! / (n-m)! * m!
 * 팩토리얼과는 다르게 2, 5 둘다 개수를 세어주고 큰놈이 답임
 * 2와 5에 대해서 n!, (n-m)!, m! 세종류의 결과를 다 구하면 됨
 */

#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long two = 0, five = 0;
    long long n, m;
    cin >> n >> m; // nCm

    // 2
    for (long long i = 2; i <= n; i *= 2)
    {
        two += n / i;
    }
    for (long long i = 2; i <= n - m; i *= 2)
    {
        two -= (n - m) / i;
    }
    for (long long i = 2; i <= m; i *= 2)
    {
        two -= m / i;
    }

    // 5
    for (long long i = 5; i <= n; i *= 5)
    {
        five += n / i;
    }
    for (long long i = 5; i <= n - m; i *= 5)
    {
        five -= (n - m) / i;
    }
    for (long long i = 5; i <= m; i *= 5)
    {
        five -= m / i;
    }

    cout << min(two, five) << '\n';
    return 0;
}
