// TITLE 게임판 덮기

#include <bits/stdc++.h>
using namespace std;

// TODO 6.6 게임판 덮기 문제를 해결하는 재귀 호출 알고리즘
// ? 가능한 답의 상한은 2^32개이나 실제로 가능한 경우는 이보다 훨씬 적음

// 주어진 칸을 덮을 수 있는 네 가지 방법
// 블록을 구성하는 세 칸의 상대적 위치 (dy, dx)의 목록
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}}, // ㄱ 뒤집힌 모양
    {{0, 0}, {0, 1}, {1, 1}}, // ㄱ 모양
    {{0, 0}, {1, 0}, {1, 1}}, // ㄴ 모양
    {{0, 0}, {1, 0}, {1, -1}}, // ㄴ 뒤집힌 모양
};

// | board의 (y, x)를 type번 방법으로 덮거나, 덮었던 블록을 없앰
// | delta = 1이면 덮고, -1이면 덮었던 블록을 없앰
// | 만약 블록이 제대로 덮이지 않은 경우 (게임판 밖으로 나가거나, 겹치거나, 검은 칸을 덮을 때) false 반환
bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
    bool ok = true;

    for (int i = 0; i < 3; i++) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= board.size() || nx < 0 || nx>= board[0].size())
            ok = false;
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
        // ! 블록을 놓을 위치에 이미 블록이 있다고 해서 함수를 바로 종료하면
        // ! 이후 블록을 치울 때 이미 있던 블록의 일부가 함께 없어지므로
        // ! delta 값을 board에 더해줌으로써 블록이 겹쳐있다는 것만 표현
    }

    return ok;
}

// | board의 모든 빈 칸을 덮을 수 있는 방법의 수 반환
// | board[i][j] = 1 : 이미 덮인 칸 혹은 검은 칸
// | board[i][j] = 0 : 아직 덮이지 않은 칸
int cover(vector<vector<int>>& board) {
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }

    // 기저 사례 : 모든 칸을 채웠으면 1을 반환
    if (y == -1)
        return 1;
    
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        // 만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출
        if (set(board, y, x, type, 1))
            ret += cover(board);
        // 덮었던 블록을 치움
        set(board, y, x, type, -1);
    }
    return ret;
}