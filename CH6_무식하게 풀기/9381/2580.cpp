// TITLE 스도쿠 #2580

#include <bits/stdc++.h>
using namespace std;

// ? (빈칸)^9번 연산이 필요하지만 가능한 경우가 많지 않음 

int board[9][9];
bool row[9][10], col[9][10], box[9][10];

// | x, y : 숫자 대입을 시작할 위치
// | (x, y)부터 빈 칸을 찾아 숫자를 대입하여 스도쿠 완성
bool guess(int x, int y)
{
    // 가장 가까운 빈 칸 찾기
    bool found = false;
    while (x < 9) {
        while (y < 9) {
            if (board[x][y] == 0) {
                found = true;
                break;
            }
            y++;
        }
        if (found)
            break;
        x++;
        y = 0;
    }

    // base case : 모든 빈 칸을 채운 경우
    if (x == 9)
        return true;
    
    // 빈칸에 1부터 9까지 수 대입
    for (int i = 1; i <= 9; i++) {
        if (!row[x][i] && !col[y][i] && !box[x/3*3+y/3][i]) {
            row[x][i] = col[y][i] = box[x/3*3+y/3][i] = true;
            board[x][y] = i;
            if (guess(x, y+1))
                return true;
            board[x][y] = 0;
            row[x][i] = col[y][i] = box[x/3*3+y/3][i] = false;
        }
    }

    // 대입할 수 있는 수가 없거나 모든 수를 대입해도 답을 찾지 못한 경우
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                box[i/3*3+j/3][board[i][j]] = true;
            }
        }
    }

    guess(0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << '\n';
    }

    return 0;
}