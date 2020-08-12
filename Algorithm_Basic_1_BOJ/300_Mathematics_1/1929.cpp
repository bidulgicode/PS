/**
 * BOJ_1929_소수구하기
 * https://www.acmicpc.net/problem/1929
 */
#include <bits/stdc++.h>
using namespace std;
// 1 <= M <= N <= 1,000,000
const int MAX = 1000000;
bool check[MAX + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 일단 모든 범위의 수를 배열에 넣어놓고
    // 아래 코드를 통해 걸러냄
    check[0] = check[1] = true; // 0,1은 소수가 아님
    for (int i = 2; i * i <= MAX; i++)
    {
        if (check[i] == false)
        {
            // i*i or i+i 범위에 따라
            for (int j = i + i; j <= MAX; j += i)
            {
                // 찾아낸 소수의 배수는 전부 체크
                check[j] = true;
            }
        }
    }

    int m, n;
    cin >> m >> n;

    // 걸러낸 이후의 배열을 가공
    int prime[n];
    for (int i = m; i <= n; i++)
    {
        if (check[i] == false)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
