/**
 * BOJ_6588_골드바흐의 추측
 * https://www.acmicpc.net/problem/6588
 */

#include <iostream>
using namespace std;
// 6 <= n <= 1,000,000
const int MAX = 1000000;
bool check[MAX + 1]; // check[MAX] 인덱스에 접근하려면 MAX+1로 생성
int pn; // prime 배열용 인덱스
int prime[MAX]; // 찾아낸 소수 저장

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 소수찾아내기
    for (int i = 2; i <= MAX; i++){
        if(check[i] == false){
            prime[pn++] = i; // prime[pn]에 i를 대입하고 pn을 +1
            for (int j = i + i; j <= MAX; j += i){
                check[j] = true; // check는 모든값이 펼쳐져있는 체임
            }
        }
    }

    while(true){
        int n;
        cin >> n;
        if(n == 0)
            break; // 입력의 끝

        for (int i = 1; i < pn; i++){
            // prime 배열의 인덱스 pn-1까지 숫자가 채워져 있음
            // n = prime[i] + check[n-prime[i]]
            // ==> check[n-prime[i]] = n - prime[i]
            if(check[n - prime[i]] == false){
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }
    
    return 0;
}
