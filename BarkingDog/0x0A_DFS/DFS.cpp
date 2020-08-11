#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second 줄이기 용도
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행, m = 열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 이동시 x,y 좌표 변동치를 미리 저장
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<pair<int, int>> S; // DFS는 스택을 쓴다. 그 외 나머지는 BFS하고 똑같
    vis[0][0] = true; // (0, 0) 시작점을 방문했다고 명시함
    S.push({0, 0}); // 스택에 시작점 삽입
    while(!S.empty()){
        pair<int, int> cur = S.top();
        S.pop();
        cout << "(" << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir ++){
            // 상하좌우 칸을 살펴보기
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 범위체크
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(vis[nx][ny] || board[nx][ny] != 1) // 이미 방문했거나 파란 칸이 아닌 경우
                continue;
            vis[nx][ny] = true; // (nx, ny)칸을 방문했다고 명시함
            S.push({nx, ny});
        }
    }
}