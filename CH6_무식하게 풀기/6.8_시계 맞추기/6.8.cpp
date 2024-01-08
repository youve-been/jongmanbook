// TITLE 시계 맞추기

#include <bits/stdc++.h>
using namespace std;

// TODO 6.8 시계 맞추기 문제를 해결하는 완전 탐색 알고리즘

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
// linked[i][j] = 'x' : i번 스위치와 j번 시계가 연결되어 있음
// linked[i][j] = '.' : i번 스위치와 j번 시계가 연결되어 있지 않음
const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

// | 모든 시계가 12시를 가리키고 있는지 확인
bool areAligned(const vector<int>& clocks);

// | swtch번 스위치를 누름
void push(vector<int>& clocks, int swtch)
{
    for (int clock = 0; clock < CLOCKS; clock++) {
        if (linked[swtch][clock] == 'x') {
            clocks[clock] += 3;
            if (clocks[clock] == 15)
                clocks[clock] = 3;
        }
    }
}

// | clocks : 현재 시계들의 상태
// | swtch : 이번에 누를 스위치의 번호
// | 가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수 반환
// | 만약 불가능하다면 INF 이상의 큰 수 반환
int solve(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES)
        return areAligned(clocks) ? 0 : INF; // ! 성공할 경우 0 반환
    
    // 이 스위치를 0번 누르는 경우부터 3번 누르는 경우까지를 모두 시도
    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++) {
        ret = min(ret, cnt + solve(clocks, swtch+1)); // ! 덧셈을 호출된 함수가 아니라 호출하는 함수가 수행
        push(clocks, swtch);
    }
    // push(clocks, swtch)가 4번 호출되었으니 clocks는 원래와 같은 상태가 됨
    return ret;
}