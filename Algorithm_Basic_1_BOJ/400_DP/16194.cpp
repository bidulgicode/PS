/**
 * BOJ_16194_카드 구매하기 2
 * https://www.acmicpc.net/problem/16194
 * 카드구매하기1 코드에 max를 min으로 바꿔치기하면 될 것 같지만
 * int 배열 초기값이 0이어서 제대로 안구해짐.
 * 그래서 배열에 들어갈 수 있는 최대값을 구해야 하는데
 * 구매하려는 카드가 1,000장 이하, 카드팩의 가격이 10,000 이하니깐
 * 최대가격은 1000*10000 를 넘지 않는다. -> 이게 최대값
 * 그런데 이것보다는 -1로 초기화 해주는게 더 권장됨.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> d(n + 1, -1);  // 초기값을 -1로
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (d[i] == -1 || d[i] > d[i - j] + p[j]) { // d[i] == -1 이면 뒤에 계산할 필요도 없이 대입
                d[i] = d[i - j] + p[j]; // if에서 뭐가 더 작은지 계산하니깐 min함수 없이 대입.
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
