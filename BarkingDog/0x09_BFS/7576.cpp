/**
 * BOJ_7576_토마토
 * https://www.acmicpc.net/problem/7576
 * 모든 익은 토마토들에 대해 해당 위치를 시작점으로 하는 BFS를 다 돌리면?
 * BFS의 시간복잡도는 O(NM)이고 익은 토마토 또한 최대 NM개 있을 수 있으니
 * 시간 복잡도는 총 O(N^2M^2)이 되니깐 시간내로 해결 못함
 * 모든 익은 토마토별로 BFS를 돌지 않고
 * 모든 익은 토마토를 처음부터 큐에 넣고 BFS를 시작하면 됨.
 */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

// 2 <= M,N <= 1,000
int board[1002][1002];
int dist[1002][1002]; // 익지 않은 토마토는 -1, int 초기값이 0이니 익었거나 토마토가 없는 칸은 0
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j]; // 상자에 저장된 토마토들의 정보를 입력.
            if (board[i][j] == 1)
                Q.push({i, j}); // 익은토마토는 큐로
            if (board[i][j] == 0)
                dist[i][j] = -1; // 익지 않은 토마토는 dist를 -1로
            // 토마토가 들어있지 않은 곳은 dist가 0임
        }
    }
    // BFS 시작
    while (!Q.empty())
    {
        auto cur = Q.front();        
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0)
                continue; // dist가 0이거나 크면 빈곳 또는 이미 익은곳
            // if dist == -1
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            { // BFS 다했는데 안익은게 있으면 -1
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}


