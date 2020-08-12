/**
 * BOJ_2609_최대공약수와 최소공배수
 * https://www.acmicpc.net/problem/2609
 */
#include <iostream>
using namespace std;

int gcd(int x, int y){
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    // 최소공배수 LCM = g*(a/g)*(b/g) = a*b/g
    cout << g << '\n'
         << a * b / g << '\n';

    return 0;
}
