/**
 * BOJ_1676_팩토리얼 0의 개수
 * https://www.acmicpc.net/problem/1676
 * 
 * 10! = 3628800
 * 10! = 2^8 * 3^4 * 5^2 * 7
 * 위 소인수분해 결과에서, 끝이 0이 되는 조합 2*5가 몇제곱인지 보면 0의 개수를 알 수 있음
 * 10! = 2^6 * 3^4 * 7 * (2^2 * 5^2) = 2^6 * 3^4 * 7 * 10^2
 * 5의 개수는 항상 2보다 적기 때문에 5의 개수만 세어주면 됨.
 * N!의 0의 개수 = ⌊N/5⌋ + ⌊N/5^2⌋ + ⌊N/5^3⌋ + ... 
 */
#include <iostream>
using namespace std;

int main()
{
    // 100! 의 경우 5로 나누면 20개가 나오고
    // 여기서 5^2인경우를 한번씩 더 해주면 됨
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 5; i <= n; i*=5){
        ans += n / i;
    }

    cout << ans << '\n';
    return 0;
}
