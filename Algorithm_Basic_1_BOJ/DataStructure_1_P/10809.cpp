/**
 * BOJ_10809_알파벳찾기
 * https://www.acmicpc.net/problem/10809
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
        auto loc = find(s.begin(), s.end(), i);
        if(loc == s.end()){
            // find는 begin부터 end바로전까지 찾으며
            // 못찾으면 end를 반환
            cout << -1 << ' ';
        } else {
            // 뭔가 찾음
            cout << (loc - s.begin()) << ' ';
        }
    }

    cout << '\n';
    return 0;
}
