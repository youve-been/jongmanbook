// TITLE 두 동전 #16197

#include <bits/stdc++.h>
using namespace std;

// ? 최대 4^10 = 1048576번 연산 필요

int n, m;
char board[22][22];
int minimum = 11;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
// inRange : 해당 위치가 보드판 위인지, 아닌지를 확인
#define inRange(a, b) ((a >= 1) && (b >= 1) && (a <= n) && (b <= m))

// | x1, y1 : 동전 1의 좌표
// | x2, y2 : 동전 2의 좌표
// | cnt : 버튼을 누른 횟수
// | cnt만큼 눌러 둘 중 하나를 떨어뜨릴 수 있는지 확인
void move(int x1, int y1, int x2, int y2, int cnt)
{
    // base case : 동전을 10번 안에 떨어뜨릴 수 없는 경우
    if (cnt > 10)
        return;
    // base case : 두 동전이 모두 바깥에 떨어진 경우
    if (!inRange(x1, y1) && !inRange(x2, y2))
        return;
    // base case : 두 동전 중 하나만 바깥에 떨어진 경우
    else if (!inRange(x1, y1) || !inRange(x2, y2)) {
        if (cnt < minimum)
            minimum = cnt;
        return;
    }
    int nx1, nx2, ny1, ny2;
    for (int i = 0; i < 4; i++) {
        nx1 = board[x1+dx[i]][y1+dy[i]] == '#' ? x1 : x1+dx[i];
        ny1 = board[x1+dx[i]][y1+dy[i]] == '#' ? y1 : y1+dy[i];
        nx2 = board[x2+dx[i]][y2+dy[i]] == '#' ? x2 : x2+dx[i];
        ny2 = board[x2+dx[i]][y2+dy[i]] == '#' ? y2 : y2+dy[i];

        swap(board[x1][y1], board[nx1][ny1]);
        swap(board[x2][y2], board[nx2][ny2]);
        move(nx1, ny1, nx2, ny2, cnt + 1);
        swap(board[x1][y1], board[nx1][ny1]);
        swap(board[x2][y2], board[nx2][ny2]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    // ! fill(배열의 시작위치, &배열이름[행개수-1][열개수], 초기화값)
    fill(&board[0][0], &board[21][22], '.');

    string s;
    int x1, x2, y1, y2;
    bool foundCoin = false;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            board[i][j] = s[j-1];
            if (board[i][j] == 'o') {
                if (foundCoin) {
                    x2 = i;
                    y2 = j;
                }
                else {
                    foundCoin = true;
                    x1 = i;
                    y1 = j;
                }
            }
        }
    }

    move(x1, y1, x2, y2, 0);

    minimum == 11 ? cout << -1 << endl : cout << minimum << endl;

    return 0;
}