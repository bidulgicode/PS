// BOJ_10870_피보나치 수 5
#include <iostream>
using namespace std;

// 피보나치 수 예시
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... 
// 이거 O(2^N) 너무느림

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        // 여기서 두개의 함수를 호출하고 있고 이것을 n번 호출
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';

    return 0;
}
