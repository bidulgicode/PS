// BOJ_2749_피보나치 수 3
// N이 너무 커서 범위를 축소시켜야함
// 피보나치 수를 K로 나눈 나머지는 항상 주기를 가지게 됨 -> 피사노 주기
// 주기의 길이가 P이면 N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째
// 피보나치 수를 M으로 나눈 나머지와 같다. -> ???
// ex) M = 10^K 일때 K > 2라면 주기는 항상 15 x 10^K-1
// 이 문제에서 M은 1,000,000 = 10^6 이니깐 주기는 15 x 10^5 = 1500000
#include <iostream>
using namespace std;
const int mod = 1000000; // M = 10^6
const int p = mod / 10 * 15; // 15 x 10^6-1
int fibo[p] = {0, 1};
int main(){
    long long n;
    cin >> n;
    for (int i = 2; i < p; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= mod; // N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M으로 나눈 나머지와 동일
        // 그래서 미리 나눠서 넣어놓음. 어차피 입력은 N%P로만 들어오게 할것
    }
    cout << fibo[n % p] << '\n';
    return 0;
}