// TITLE 연산자 끼워넣기 #14888

#include <bits/stdc++.h>
using namespace std;

// ? 10! = 3628800보다 더 작은 횟수의 연산이 필요함

int n;
int arr[11];
int maxAns, minAns;

// | ans : 현재까지의 연산결과
// | pos : 연산 시작 위치
// | op : 남은 연산자 개수
// | pos부터 연산을 시작하여 최댓값 및 최솟값 업데이트
void calc(int ans, int pos, vector<int>& op)
{
    // base case : 모든 자리에 연산자를 넣은 경우
    if (pos == n - 1) {
        if (maxAns < ans)
            maxAns = ans;
        if (minAns > ans)
            minAns = ans;
        return;
    }

    // 덧셈
    if (op[0] > 0) {
        op[0]--;
        calc(ans + arr[pos+1], pos+1, op);
        op[0]++;
    }
    // 뺄셈
    if (op[1] > 0) {
        op[1]--;
        calc(ans - arr[pos+1], pos+1, op);
        op[1]++;
    }
    // 곱셈
    if (op[2] > 0) {
        op[2]--;
        calc(ans * arr[pos+1], pos+1, op);
        op[2]++;
    }
    // 나눗셈
    if (op[3] > 0) {
        op[3]--;
        calc(ans / arr[pos+1], pos+1, op);
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

    vector<int> op(4);
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    
    maxAns = -1000000005;
    minAns = 1000000005;
    calc(arr[0], 0, op);

    cout << maxAns << endl;
    cout << minAns << endl;

    return 0;
}