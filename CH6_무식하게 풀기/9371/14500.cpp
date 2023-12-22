// TITLE 테트로미노 #14500

#include <bits/stdc++.h>
using namespace std;


int n, m; // 보드판의 가로, 세로 길이
int board[500][500]; // 숫자가 적힌 보드판
bool visited[500][500] = {false, }; // 보드판 방문여부를 표시
int dx[4] = {-1, 0, 1, 0}; // 상하좌우 x값을 나타낸 배열
int dy[4] = {0, -1, 0, 1}; // 상하좌우 y값을 나타낸 배열
// check(a, b) : (a, b)가 보드판 위의 위치인지 확인
#define check(a, b) ((((a) >= 0) && ((a) < n) && ((b) >= 0) && ((b) < m)) ? true : false)

// | x : 세로 위치
// | y : 가로 위치
// | cnt : 이동가능한 횟수
// | (x,y)에서 cnt만큼 블록을 놓았을 때 얻을 수 있는 최대 합계
int dfs(int x, int y, int cnt)
{
    // base case : 현재칸이 움직일 수 있는 마지막 칸인 경우
    if (cnt == 1)
        return board[x][y];

    // 상하좌우에 대해 모두 확인
    int max = 0;
    for (int i = 0; i < 4; i++) {
        if (check(x+dx[i], y+dy[i]) && !visited[x+dx[i]][y+dy[i]]) {
            visited[x+dx[i]][y+dy[i]] = true;
            int curr = dfs(x+dx[i], y+dy[i], cnt-1);
            max = curr > max ? curr : max;
            visited[x+dx[i]][y+dy[i]] = false;
        }
    }

    return board[x][y] + max;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            int curr = dfs(i, j, 4);
            max = curr > max ? curr : max;

            // 'ㅗ' 모양 블록만 따로 계산
            // ! 테두리에 있는 'ㅗ' 블록을 계산할 때 예외처리 필요
            int min = 10000;
            int tot = 0;
            int no = 0;
            for (int k = 0; k < 4; k++) {
                if (!check(i+dx[k], j+dy[k])) {
                    no++;
                    continue;
                }
                min = board[i+dx[k]][j+dy[k]] < min ? board[i+dx[k]][j+dy[k]] : min;
                tot += board[i+dx[k]][j+dy[k]];
            }
            if (no == 0)
                max = board[i][j] + tot - min > max ? board[i][j] + tot - min : max;
            else if (no == 1)
                max = board[i][j] + tot > max ? board[i][j] + tot : max;
            visited[i][j] = false;
        }
    }

    cout << max << endl;

    return 0;
}

// TODO 힌트를 많이 보고 풀었으니 나중에 다시 풀어볼 것