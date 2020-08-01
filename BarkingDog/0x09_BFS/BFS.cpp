/**
 * Breadth First Search
 * Best First Search
 * 코드 원본 : https://github.com/encrypted-def/basic-algo-lecture-metarial/blob/master/0x09/BFS.cpp
 * BFS는 거의 레퍼런스에 가까운 구현이 있기 때문에 이것을 익히고 생각해보는게 좋다.
 */
#include <bits/stdc++.h>
using namespace std;
// 여기서 first(X)는 행, second(Y)는 열이다. 햇갈림 주의
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 1이 파란 칸(이동가능), 0이 빨간 칸(이동불가)에 대응
bool vis[502][502];                   // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10;                    // n = 행의 수, m = 열의 수
// dx, dy 값에 따른 순서는 아래,오른,위,왼 순서임, 아래로가면 x값증가, 오른쪽으로 가면 y값증가
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향을 의미
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    vis[0][0] = 1;  // (0, 0)을 방문했다고 명시
    Q.push({0, 0}); // 큐에 시작점인 (0, 0)을 삽입.
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++)
        { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;    // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            Q.push({nx, ny});
        }
    }
}