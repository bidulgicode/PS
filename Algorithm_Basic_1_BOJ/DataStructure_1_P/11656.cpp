/**
 * BOJ_11656_접미사배열
 * https://www.acmicpc.net/problem/11656
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> a;
    for (int i = 0; i < n; i++)
        a.push_back(i);

    sort(a.begin(), a.end(), [&s](int u, int v) {
        // strcmp (https://blockdmask.tistory.com/391)
        // s.c_str() + u, s.c_str() + v
        // 위 두개의 문자열을 비교하다가 다른문자가 나오는 시점에서
        // 그 문자의 아스키 코드 값을 비교해서 반환값이 정해짐
        // s.c_str() + u < s.c_str() + v 이면 -1
        // s.c_str() + u > s.c_str() + v 이면 1
        // 마지막으로 동일한 경우에는 0
        // 각 문자를 아스키 코드로 비교하기 때문에
        // 1. 대소문자 구분, 2. 각 문자별 숫자로 대소 비교 가능
        // EX) D, F, A의 경우 D < F 이므로 -1, D > A 이므로 1 반환
        // 이 람다 함수의 경우 -1인 경우에만 true를 리턴함.
        cout << u << '\n';
        cout << v << '\n';
        return strcmp(s.c_str() + u, s.c_str() + v) < 0;
    });

    return 0;
}
