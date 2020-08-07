/**
 * BOJ_1697_숨바꼭질
 * https://www.acmicpc.net/problem/1697
 * 여태 이차원 BFS 위주로 했기 때문에 접근하기가 어려움
 * 문제는 일차원 배열로 나왔지만 이것을
 * 수빈이가 X에 있다고 했을때 X-1, X+1, 2X로 이동하니깐
 * 2차원 정배열에 그려보면 좌,우,상 으로만 이동하는 2차원 BFS 마냥 됨
 * 근데 이 문제에서 BFS범위를 잡기가 어려운데 수빈이의 이동범위에 제한이 없다.
 * 하지만 어쨌든 동생은 0~100,000 사이에 있고, 이 범위를 벗어나는 것이 보통 손해라고 알아두자.
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 0 <= N <= 100,000
int dist[100002];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; // 수빈이, 동생 위치
    cin >> n >> k;
    fill(dist, dist + 100001, -1);
    dist[n] = 0; // 검색을 시작할 수빈이 좌표
    queue<int> Q;
    Q.push(n);
    while(dist[k] == -1){
        // dist[k]가 -1이라는것은 수빈이가 아직 못찾았다는것이기 때문
        int cur = Q.front();
        Q.pop();
        // 범위기반 for문
        for(int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt < 0 || nxt > 100000)
                continue;
            if(dist[nxt] != -1) // 이미 방문했다면
                continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k];
}