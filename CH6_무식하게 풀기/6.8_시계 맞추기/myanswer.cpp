// TITLE 시계 맞추기 (ID : CLOCKSYNC)

#include <bits/stdc++.h>
using namespace std;

#define INF 10000 // 초기화를 위한 매우 큰 수
vector<vector<int>> clock_switch = {
    {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15},
    {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15},
    {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
}; // 각 스위치가 바꾸는 시계의 번호 목록
int clocks[16]; // 시계의 현재 상태

void push_switch(int switch_num, int times)
{
    if (times % 4 == 0)
        return;
    for (int c : clock_switch[switch_num]) 
        clocks[c] = (clocks[c] + times * 3) % 12;
}

// ! 스위치를 누르는 순서는 중요하지 않고 횟수만 중요
// | cnt : 이전까지 스위치를 누른 횟수
// | switch_num : 누를 스위치 번호
// | 시계를 모두 12시에 맞추기 위해 스위치를 누르는 최소 횟수 반환
int clock_to_twelve(int cnt, int switch_num)
{
    // base case : 시계가 모두 12시를 가리키는 경우 (성공)
    bool flag = false;
    for (int i = 0; i < 16; i++) {
        if (clocks[i] != 0) {
            flag = true;
            break;
        }
    }
    if (!flag)
        return cnt;
    
    // base case : 스위치를 모두 눌렀으나 모두 12시가 아닌 경우 (실패)
    if (switch_num >= 10)
        return INF; // 큰 수를 반환하여 실패했음을 표현

    // 최솟값을 구해야 하므로 결과값을 매우 큰 수로 초기화
    int ref = INF;
    // 현재 스위치 이후의 스위치로 모두 12시를 만드는 최소 횟수 찾기
    for (int i = 0; i < 4; i++) {
        push_switch(switch_num, i); 
        ref = min(ref, clock_to_twelve(cnt+i, switch_num + 1));
        push_switch(switch_num, 4 - i); // 4-i번 눌러서 시계 원상복구
    }
    // ! 스위치를 4번 누르면 원래 상태로 돌아오므로
    // ! 4번 이상 누르는 것은 무의미함 --> 스위치별로 3번까지만 확인해보면 됨

    return ref;
}
// ! 남은 스위치를 눌러서 시계를 모두 12시로 맞추는 최소 반환이 목적이므로
// ! 인자로 이전의 스위치 누른 횟수를 받아서 합을 반환하는 것보다
// ! 덧셈은 재귀 함수 호출 전의 함수가 하고 함수는 남은 스위치들의 횟수만 반환하는 것이 바람직해보임
// ! 6.8.cpp의 덧셈 위치 참고

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int x = 0; x < tc; x++) {
        for (int i = 0; i < 16; i++) {
            cin >> clocks[i];
            if (clocks[i] == 12)
                clocks[i] = 0;
        }
        
        int ans = clock_to_twelve(0, 0);
        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}