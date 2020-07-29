/**
 * BOJ_1978_소수찾기
 * https://www.acmicpc.net/problem/1978
 */
#include <iostream>

bool isPrime(int n){
    if(n < 2){
        // if n == 1
        return false;
    }

    for (int i = 2; i * i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(isPrime(num)){
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
