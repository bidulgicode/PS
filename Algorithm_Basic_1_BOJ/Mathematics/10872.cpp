/**
 * BOJ_10872_팩토리얼
 * https://www.acmicpc.net/problem/10872
 */
#include <iostream>
using namespace std;

// 재귀가 쓰기는 편하다..
int factorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << factorial(n) << '\n';
    return 0;
}
