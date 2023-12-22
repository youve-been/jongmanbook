// TITLE NM과 K (1) #18290

#include <bits/stdc++.h>
using namespace std;

// ? 시간복잡도 : 모르겠음
// TODO 시간복잡도 알아보기

int n, m;
int board[12][12]; // 보드판. 범위 검사를 하지 않기 위해 n+2 * m+2 크기로 만듦
int visited[12][12] = {0, }; // 칸별 방문횟수를 표현하는 배열
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

// | x : 방문할 위치의 세로 좌표
// | y : 방문할 위치의 가로 좌표
// | (x, y)와 이 점의 상하좌우를 방문 표시
void visit(int x, int y, int op) {
    visited[x][y] = visited[x][y] + op <= 0 ? 0 : visited[x][y] + op;
    for (int i = 0; i < 4; i++)
        visited[x+dx[i]][y+dy[i]] = visited[x+dx[i]][y+dy[i]] + op <= 0 ? 0 : visited[x+dx[i]][y+dy[i]] + op;
}

// | x : 현재 위치의 세로 좌표
// | y : 현재 위치의 가로 좌표
// | cnt : 골라야하는 칸의 개수
// | (x, y)에서부터 오른쪽 아래로 내려가며 
// | cnt개의 인접하지 않은 숫자를 골라 최댓값을 찾음
int find_max(int x, int y, int cnt)
{
    // base case :
    if (cnt == 0) 
        return 0;
    
    // ! 입력값의 범위를 잘 확인할 것
    int curr, max = -100000;
    // x행부터 이어서 탐색
    for (int j = y; j <= m; j++) {
        if (visited[x][j] <= 0) {
            visit(x, j, 1);
            curr = board[x][j] + find_max(x, j, cnt - 1);
            visit(x, j, -1);

            if (curr > max)
                max = curr;
        }
    }

    // x+1행부터 n행까지 탐색
    for (int i = x+1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] <= 0) {
                visit(i, j, 1);
                curr = board[i][j] + find_max(i, j, cnt - 1);
                visit(i, j, -1);

                if (curr > max)
                    max = curr;
            }
        }
    }

    return max;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    }
    
    cout << find_max(1, 1, k) << endl;

    return 0;
}