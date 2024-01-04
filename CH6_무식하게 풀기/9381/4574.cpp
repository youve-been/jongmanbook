// TITLE 스도미노쿠 #4574

#include <bits/stdc++.h>
using namespace std;

int board[9][9]; // 스도쿠 보드
bool domino[9][10]; // 도미노 타일 사용 여부
bool row[9][10]; // 행마다 숫자 사용 여부
bool col[9][10]; // 열마다 숫자 사용 여부
bool box[9][10]; // 박스 안 숫자 사용 여부

// | r : 확인해야할 행
// | c : 확인해야할 열
// | num : 확인해야할 수
// | (r, c)에 num을 넣을 수 있는지 확인
bool able(int r, int c, int num)
{
    return !row[r][num] && !col[c][num] && !box[r/3*3+c/3][num];
}

// | r : 타일을 넣을 행
// | c : 타일을 넣을 열
// | num : 칸에 넣을 수
// | flag : true면 칸에 수 넣기, false면 칸에서 수 제거하기
// | (r, c)에 num을 넣거나 제거함
void tile(int r, int c, int num, bool flag)
{
    board[r][c] = flag ? num : 0;
    row[r][num] = flag;
    col[c][num] = flag;
    box[r/3*3+c/3][num] = flag;
}

// | r : 채워넣을 행
// | c : 채워넣을 열
// | (r, c) 칸에 타일을 채워 판 완성 여부 확인
bool guess(int r, int c)
{
    if (c >= 9) {
        r++;
        c = 0;
    }
    // 가까운 빈 칸 찾기
    while (board[r][c] != 0 && r < 9) {
        c++;
        if (c >= 9) {
            r++;
            c = 0;
        }
    }

    // base case : 모든 칸을 채운 경우
    if (r == 9)
        return true;

    // base case : 타일을 놓을 수 없는 경우
    if ((r+1 >= 9 || board[r+1][c] > 0) && (c+1 >= 9 || board[r][c+1] > 0))
        return false;
    
    // 타일 넣어보기
    for (int i = 1; i < 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            if (domino[i][j])
                continue;
            
            // 세로로 타일 넣기
            if (r+1 < 9 && board[r+1][c] == 0) {
                if (able(r, c, i) && able(r+1, c, j)) {
                    tile(r, c, i, true);
                    tile(r+1, c, j, true);
                    domino[i][j] = true;
                    if (guess(r, c+1))
                        return true;
                    domino[i][j] = false;
                    tile(r, c, i, false);
                    tile(r+1, c, j, false);
                }
                if (able(r, c, j) && able(r+1, c, i)) {
                    tile(r, c, j, true);
                    tile(r+1, c, i, true);
                    domino[i][j] = true;
                    if (guess(r, c+1))
                        return true;
                    domino[i][j] = false;
                    tile(r, c, j, false);
                    tile(r+1, c, i, false);
                }
            }
            // 가로로 타일 넣기
            if (c+1 < 9 && board[r][c+1] == 0) {
                if (able(r, c, i) && able(r, c+1, j)) {
                    tile(r, c, i, true);
                    tile(r, c+1, j, true);
                    domino[i][j] = true;
                    if (guess(r, c+2))
                        return true;
                    domino[i][j] = false;
                    tile(r, c, i, false);
                    tile(r, c+1, j, false);
                }
                if (able(r, c, j) && able(r, c+1, i)) {
                    tile(r, c, j, true);
                    tile(r, c+1, i, true);
                    domino[i][j] = true;
                    if (guess(r, c+2))
                        return true;
                    domino[i][j] = false;
                    tile(r, c, j, false);
                    tile(r, c+1, i, false);
                }
            }
        }
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, u, v, idx = 1;
    int r, c;
    string lu, lv;

    cin >> n;
    while (n != 0) {
        for (int i = 0; i < 9; i++) {
            memset(domino[i], false, sizeof(domino[i]));
            memset(board[i], 0, sizeof(board[i]));
            memset(row[i], false, sizeof(row[i]));
            memset(col[i], false, sizeof(col[i]));
            memset(box[i], false, sizeof(box[i]));
        }

        for (int i = 0; i < n; i++) {
            cin >> u >> lu >> v >> lv;
            r = lu[0]-'A';
            c = lu[1]-'1';
            board[r][c] = u;
            row[r][u] = true;
            col[c][u] = true;
            box[r/3*3+c/3][u] = true;
            r = lv[0]-'A';
            c = lv[1]-'1';
            board[r][c] = v;
            row[r][v] = true;
            col[c][v] = true;
            box[r/3*3+c/3][v] = true;
            if (u > v)
                swap(u, v);
            domino[u][v] = true;
        }

        for (int i = 0; i < 9; i++) {
            cin >> lu;
            r = lu[0]-'A';
            c = lu[1]-'1';
            board[r][c] = i+1;
            row[r][i+1] = true;
            col[c][i+1] = true;
            box[r/3*3+c/3][i+1] = true;
        }
        
        guess(0, 0);

        cout << "Puzzle " << idx << '\n';
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j];
            cout << '\n';
        }

        cin >> n;
        idx++;
    }

    return 0;
}