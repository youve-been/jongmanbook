// TITLE N-Queen #9663

#include <bits/stdc++.h>
using namespace std;

// ? 최대 14!번 연산이 필요하나 불가능한 경우가 많고 시간제한이 김

int n;
bool col[14] = {false, }; // 퀸이 있는 열을 표시
bool up[27] = {false, }; // 상향 대각선에 퀸이 있는 곳을 표시, 2n+1개 필요
bool down[27] = {false, }; // 상향 대각선에 퀸이 있는 곳을 표시, 2n+1개 필요

// | row : 퀸을 놓기 시작할 행
// | row행부터 퀸을 놓아 퀸을 공격할 수 없게 하는 경우의 수 계산
int putQueen(int row)
{
    // base case : 퀸을 모두 놓은 경우
    if (row == n)
        return 1;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!col[i] && !up[row+i] && !down[row-i+n-1]) {
            col[i] = up[row+i] = down[row-i+n-1] = true;
            ans += putQueen(row+1);
            col[i] = up[row+i] = down[row-i+n-1] = false;
        }
    }

    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    cout << putQueen(0) << endl;

    return 0;
}