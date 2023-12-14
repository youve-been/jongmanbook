// TITLE 소풍 (ID : PICNIC)

#include <bits/stdc++.h>
using namespace std;

bool friends[10][10]; // ! 인접행렬로 나타낸 친구관계

// | n : 전체 친구 수
// | matched : 이미 짝지어졌는지 확인하는 배열
// | start : 짝 찾기를 시작하는 위치
// | n명의 친구 중 start부터 짝이 없는 친구의 짝을 찾는 경우의 수를 계산
int match_friends(int n, bool matched[10], int start)
{
    // start에 가장 가까운 짝이 없는 친구 찾기
    while (start < n && matched[start])
        start++;
    
    // base cond : 친구를 모두 찾아준 경우 (성공)
    if (start >= n)
        return 1;

    int cnt = 0; // cnt : 현재 상태에서 짝지어줄 수 있는 경우의 수

    matched[start] = true;
    for (int i = 0; i < n; i++) {
        // i가 start와 친구 관계이면서 아직 짝지어지지 않았을 경우 계산
        if (friends[start][i] && !matched[i]) {
            matched[i] = true;
            cnt += match_friends(n, matched, start+1);
            matched[i] = false;
        }
    }

    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc, n, m;
    cin >> tc;
    for (int x = 0; x < tc; x++) {
        memset(friends, false, sizeof(friends));

        cin >> n >> m;

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            friends[a][b] = true;
            friends[b][a] = true;
        }

        bool matched[10] = {0, };

        cout << match_friends(n, matched, 0) << '\n';
    }

    return 0;
}