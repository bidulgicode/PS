/**
 * BOJ_10824_네수
 * https://www.acmicpc.net/problem/10824
 */
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    string ab = to_string(a) + to_string(b);
    string cd = to_string(c) + to_string(d);

// 10^12까지 숫자 들어오니깐 int로 감당못함
    long long result = stoll(ab) + stoll(cd);

    cout << result << '\n';
    return 0;
}
