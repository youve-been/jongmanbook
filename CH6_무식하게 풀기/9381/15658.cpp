// TITLE 연산자 끼워넣기 (2) #15658

#include <bits/stdc++.h>
using namespace std;

// ? 최대 4^10 = 1048576번 계산 필요

int n;
int arr[11];
int maxAns, minAns;

// | pos : 연산자를 끼워넣을 위치
// | op : 네 연산자의 남은 개수
// | res : 현재까지의 계산 결과
// | pos부터 연산자를 끼워넣어 그 결과를 확인
void calc(int pos, vector<int>& op, int res)
{
    // base case : 연산자를 모두 끼워넣은 경우
    if (pos == n - 1) {
        if (res > maxAns)
            maxAns = res;
        if (res < minAns)
            minAns = res;
        return;
    }

    // 덧셈
    if (op[0] > 0) {
        op[0]--;
        calc(pos+1, op, res + arr[pos+1]);
        op[0]++;
    }
    // 뺄셈
    if (op[1] > 0) {
        op[1]--;
        calc(pos+1, op, res - arr[pos+1]);
        op[1]++;
    }
    // 곱셈
    if (op[2] > 0) {
        op[2]--;
        calc(pos+1, op, res * arr[pos+1]);
        op[2]++;
    }
    // 나눗셈
    if (op[3] > 0) {
        op[3]--;
        calc(pos+1, op, res / arr[pos+1]);
        op[3]++;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> op(4, 0); // 순서대로 덧셈, 뺄셈, 곱셈, 나눗셈 연산자의 개수
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    
    maxAns = -1000000005;
    minAns = 1000000005;

    calc(0, op, arr[0]);

    cout << maxAns << '\n';
    cout << minAns << '\n';

    return 0;
}