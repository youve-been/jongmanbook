// TITLE 일곱 난쟁이 #2309

#include <bits/stdc++.h>
using namespace std;

// ? 총 9C7 = 36가지 경우 계산 필요

vector<int> height(9);

// | sum : 현재까지 난쟁이 키의 합
// | visited : 현재까지 고른 난쟁이 목록
// | start : 탐색을 시작할 위치
// | left : 더 찾아야 할 난쟁이 수
// | start부터 left명의 난쟁이의 키의 합이 100-sum이 되면 목록을 출력
bool check_sum(int sum, vector<bool>& visited, int start, int left)
{
    // base case : 키의 합이 100을 넘어가는 경우 (실패)
    if (sum > 100)
        return false;
    
    // base case : 7명 모두 골랐을 때
    if (left == 0) {
        if (sum == 100)
            return true;
        else
            return false;
    }

    // base case : 남은 난쟁이 수가 골라야 하는 난쟁이 수보다 작을 때 (실패)
    if (left > 9 - start)
        return false;
    
    for (int i = start; i < 9 - left + 1; i++) {
        visited[i] = true;
        if (check_sum(sum + height[i], visited, i+1, left - 1))
            return true;
        visited[i] = false;
    }

    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++)
        cin >> height[i];
    
    sort(height.begin(), height.end());
    
    vector<bool> visited(9, false);

    check_sum(0, visited, 0, 7);

    for (int i = 0; i < 9; i++) {
        if (visited[i])
            cout << height[i] << '\n';
    }

    return 0;
}