/** 
 * BOJ_2743_단어길이재기
 * https://www.acmicpc.net/problem/2743
 * length 못쓰면 이런식으로도 푼다
 */
#include <bits/stdc++.h>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int len = 0;
    // string size = 5 & capacity = 15
    for (int i = 0; s[i]; i++){
        len += 1;
    }

    cout << len << '\n';
    return 0;
}
