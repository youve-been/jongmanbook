// TITLE 게임판 덮기 (ID : BOARDCOVER)

#include <bits/stdc++.h>
using namespace std;

#define BLOCK_NUM 4 // 가능한 블록 개수
int h, w; // h : 보드판의 세로 길이, w : 보드판의 가로 길이
int blockh[BLOCK_NUM][2] = {{0, 1}, {0, 1}, {1, 1}, {1, 1}}; // 가능한 블록의 가로
int blockw[BLOCK_NUM][2] = {{1, 1}, {1, 0}, {0, 1}, {0, -1}}; // 가능한 블록의 세로

// | left : 아직 보드판에 올리지 않은 블록의 개수
// | left개의 블록을 보드판의 흰 칸에 놓는 경우의 수 계산
int cover(bool board[22][22], int left)
{
    // base case : 모든 블록을 보드판에 다 올린 경우 (성공)
    if (left == 0)
        return 1;
    
    // 가장 왼쪽 위에서부터 블록이 없는 흰 칸 찾기
    int sh = -1, sw = -1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (board[i][j]) {
                sh = i;
                sw = j;
                break;
            }
        }
        if (sh != -1 && sw != -1)
            break;
    }

    // (sh, sw) 칸을 채우는 경우를 모두 체크
    int ans = 0;
    board[sh][sw] = false;
    for (int cnt = 0; cnt < BLOCK_NUM; cnt++) {
        // 블록이 들어갈 곳이 비어있는 흰 칸이라면 채워서 경우의 수 계산
        if (board[sh+blockh[cnt][0]][sw+blockw[cnt][0]] && board[sh+blockh[cnt][1]][sw+blockw[cnt][1]]) {
            board[sh+blockh[cnt][0]][sw+blockw[cnt][0]] = false;
            board[sh+blockh[cnt][1]][sw+blockw[cnt][1]] = false;
            ans += cover(board, left-1);
            board[sh+blockh[cnt][0]][sw+blockw[cnt][0]] = true;
            board[sh+blockh[cnt][1]][sw+blockw[cnt][1]] = true;
        }
    }
    board[sh][sw] = true; // ? 이차원 배열은 모두 포인터로 넘어가므로 초기화 해주기

    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    string str;
    for (int x = 0; x < tc; x++) {
        // 블록이 보드판 밖으로 벗어나는 경우를 확인하지 않는 대신
        // 보드판을 최대 22*22 크기의, 테두리가 검은 칸으로 둘러싸인 보드판으로 생각
        // false : 검은 칸 / true : 흰 칸
        bool board[22][22] = {false, };
        cin >> h >> w;
        
        int cnt = 0;
        for (int i = 1; i <= h; i++) {
            cin >> str;
            for (int j = 0; j < w; j++) {
                if (str[j] == '.') {
                    board[i][j+1] = true;
                    cnt++;
                }
            }
        }

        // 채워야하는 흰 칸의 개수가 3의 배수가 아닌 경우 배제
        if (cnt % 3 != 0)
            cout << 0 << '\n';
        else
            cout << cover(board, cnt/3) << '\n';
    }

    return 0;
}