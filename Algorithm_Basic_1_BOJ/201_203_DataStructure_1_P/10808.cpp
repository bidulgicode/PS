/**
 * BOJ_10808_알파벳 개수
 * https://www.acmicpc.net/problem/10808
 */

#include <bits/stdc++.h>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z'; i++){
        cout << count(s.begin(), s.end(), i) << ' ';
    }
    cout << '\n';
    return 0;
}
