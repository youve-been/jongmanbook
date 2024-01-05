// TITLE 외판원 순회 2 #10971

#include <bits/stdc++.h>
using namespace std;

// ? 최대 10!=3628800번 연산 필요

int n;
int cost[10][10];
bool visited[10] = {false, };

// | cnt : 여행해야할 도시 개수
// | city : 출발 도시
// | city부터 출발하여 cnt개의 도시를 순회했을 때 가장 적은 비용 반환
int travel(int cnt, int city)
{
    // base case : 도시를 모두 순회한 경우
    if (cnt == 1)
        return cost[city][0]; // 출발점으로 돌아가는 비용을 반환

    // city에서 출발하여 cnt개의 도시를 순회
    int min = 100000000;

    int curr;
    for (int i = 1; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = true;
            curr = travel(cnt-1, i);
            if (curr == 0)
                continue;
            curr += cost[city][i];
            if (curr < min)
                min = curr;
            visited[i] = false;
        }
        
    }

    return min;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }

    cout << travel(n, 0) << endl; // 순회이므로 어느 도시에서 출발해도 동일함

    return 0;
}