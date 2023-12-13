// TITLE 보글 게임
#include <bits/stdc++.h>
using namespace std;

// - 필요한 변수 및 함수 -
bool inRange(int y, int x); // (y, x)가 보드판 내에 있는지 확인
char board[5][5]; // 보글 게임의 보드판

// TODO 6.3 보글 게임판에서 단어를 찾는 재귀 호출 알고리즘
// ? 시간복잡도 : O(8^n)

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// | 5*5의 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word)
{
    // 기저 사례 1 : 시작 위치가 범위 밖이면 무조건 실패
    if (!inRange(y, x))
        return false;
    // 기저 사례 2 : 첫 글자가 일치하지 않으면 실패
    if (board[y][x] != word[0])
        return false;
    // 기저 사례 3 : 단어 길이가 1이면 성공
    if (word.size() == 1)
        return true;
    // ! 기저 사례의 순서가 중요

    // 인접한 여덟 칸을 검사
    for (int direction = 0; direction < 8; direction++) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        // 다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지 확인할 필요가 없음
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}