/**
 * BOJ_1934_최소공배수
 * https://www.acmicpc.net/problem/1934
 */
#include <iostream>

int gcd(int x, int y){
    while(y != 0){
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    while(n--){
        int x, y;
        cin >> x >> y;
        int g = gcd(x, y);
        cout << x*y/g << '\n';
    }

    return 0;
}

