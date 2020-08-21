/**
 * BOJ_11052_카드 구매하기
 * https://www.acmicpc.net/problem/11052
 * 마지막에 구매한 카드팩에 카드가 몇개 있었을까?
 * 마지막 카드팩 구매전까지 구매한 카드 N-i개
 * 마지막에 구매한 i개 들어있는 카드팩 -> N개 완성
 * D[n] = D[n-i] + p[i], 왜 p[i]냐면 밑에 정의되어 있음.
 * i번째 카드팩은 i개의 카드를 담고 있고 가격은 p[i]원 이다.
 * D[n-1] + p[i]는 마지막에 i번째 카드팩을 구매했을때 카드가 N개가 되는 비용
 * D[n] = max(d[n-1] + p[i]), 최대비용
 * 변수의 범위를 정해야 함. n은 이미 정해져 있음, i가 변수임
 * i의 범위는 1 <= i <= n, 제일 적은 개수의 카드팩은 1, 경우에 따라서는 n개짜리를 구매
 * 전체 문제 개수는 배열의 크기와 동일
 * 복잡도 => O(n^2) = 배열사이즈 n x 배열 한칸을 구하는데 걸리는 시간 O(n)
 * 쪼매 느리네?
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  // 구매하려는 카드 개수
    cin >> n;

    vector<int> p(n + 1);  // i개 들어간 카드팩의 가격, 인덱스를 1부터 시작해야해서, n+1
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> d(n + 1); // d[n], 카드 n개를 갖기 위해 지불해야 하는 금액의 최댓값
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = max(d[i], d[i - j] + p[j]); 
            // p배열에는 확실한 값들이 들어있기 때문에
            // 이 값을 이용해서 d배열을 채워나간다고 생각하면 좀 편하다.
            // d에는 정답이 없지만 p배열에 들어있는 값을 통해서 최적값을 채워나갈 수 있음
        }
    }

    cout << d[n] << '\n';
    return 0;
}
