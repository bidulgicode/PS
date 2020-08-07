/**
 * BOJ_4179_불!
 * https://www.acmicpc.net/problem/4179
 * 지훈이와 불의 BFS를 각각 구함
 * 일단 지훈이는 신경 끄고, 불에대한 BFS를 돌려서 
 * 미리 각 칸에 불이 전파되는 시간을 구해놓자
 * 그 다음에 지훈이에 대한 BFS를 돌리는데
 * 만약 지훈이가 특정 칸을 x시간에 최초로 방문할 수 있는데
 * 그 칸에 x시간이나 그 이전에 불이 붙는다고 하면 못가는거임
 * 원래 BFS 구현에는 큐 안에서 (nx, ny)를 살펴볼때 방문했는지 여부를
 * vis[nx][ny]가 ture인지, dist[nx][ny]가 0 이상인지 확인하고
 * 이미 방문하거나 dist가 0이하면 continue를 한다.
 * 이 문제에서는 여기에 추가로 해당 칸에 불이 붙은 시간까지 체크해서 
 * continue 처리를 하면 됨
 * 결과적으로 불에대한 BFS를 먼저 구해서 갖고 있고
 * 큐에서 나온 좌표를 통해 nx,ny를 살펴볼때의 조건에 불보다 먼저 갈 수 있는지
 * 확인해주면 됨.
 * https://www.acmicpc.net/problem/18809
 * 위 문제의 경우 A,B가 동시에 진행하면서 서로를 체크하기 때문에 (지금 문제는 불은 지훈이를 체크하지 않음)
 * 백트래킹 기법으로 풀어야 한다는데 나중에 나옴
 */

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 1 <= R, C <= 1000 // R은 행 C는 열
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m; // 행 >> 열
    for (int i = 0; i < n; i++)
    {
        // 모든 이동시간을 -1로
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
    for (int i = 0; i < n; i++)
        cin >> board[i];      // 맵을 받아옴
    queue<pair<int, int>> Q1; // 불
    queue<pair<int, int>> Q2; // 지훈이
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'F')
            {
                // 불이 난 곳이면?
                Q1.push({i, j});
                dist1[i][j] = 0; // 시작점은 dist가 0
            }
            if (board[i][j] == 'J')
            {
                // 지훈이의 초기 위치
                Q2.push({i, j});
                dist2[i][j] = 0; // 시작점
            }
        }
    }

    // 불 BFS
    while (!Q1.empty())
    {
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue; // 이미 갔던곳이나 벽이면 못번짐
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny}); // 새로 번진곳은 큐에 삽입
        }
    }

    // 지훈이 BFS
    while (!Q2.empty())
    {
        auto cur = Q2.front(); // 좌표쌍을 꺼내옴
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                // 범위를 벗어난 경우 탈출에 성공했다는거
                // 큐에 거리순으로 들어가니깐 cur 출력하고
                // 밖에 나가는시간 +1 하면됨
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue; // 방문한적이 있거나 벽이면 패스
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                continue;                            // 불이 번져 있고, 내가 (nx,ny)좌표에 도달하는 시간이 같거나 더 크면 패스
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1; // 아니면 방문
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE"; // 여기에 오면 결국 못나갔다는거임
}