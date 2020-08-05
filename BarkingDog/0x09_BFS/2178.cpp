/**
 * BOJ_2178_미로탐색
 * https://www.acmicpc.net/problem/2178
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// 2 <= N, M <= 100
string board[102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++) // n열의 m행까지 -1로 채움
        fill(dist[i], dist[i] + m, -1);
    queue<pair<int, int>> Q; // BFS용
    Q.push({0, 0});          // = 시작점 1,1
    dist[0][0] = 0;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            // cur 기준 상하좌우 체크
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // 이미 방문했거나, 못가는거면 continue
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                continue;
            // cur기준 한칸다음이니 시작점으로부터 거리가 1 늘어남
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny}); // 찾아낸 방문지 기준으로도 탐색하게 큐에 넣음
        }
    }
    // 문제풀때 0,0 기준이어서 -1함
    // 칸을 셀 때에 시작위치도 포함한다고 했으니 +1
    cout << dist[n - 1][m - 1] + 1; 

    return 0;
}
