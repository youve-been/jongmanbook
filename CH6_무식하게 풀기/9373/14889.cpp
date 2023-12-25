// TITLE 스타트와 링크 #14889

#include <bits/stdc++.h>
using namespace std;

int n;
int power[20][20] = {0, };
int diff;

// ? 최대 20C10*10*10*2 = 36951200번 연산 필요

// | start : 스타트 팀 목록
// | link : 링크 팀 목록
// | 스타트 팀과 링크 팀의 능력치 차이를 계산하여 최솟값 업데이트
void check_pow_diff(vector<int>& start, vector<int>& link)
{
    int s = 0, l = 0;
    
    // 스타트 팀의 능력치 계산
    for (int i : start) {
        for (int j : start)
            s += power[i][j];
    }

    // 링크 팀의 능력치 계산
    for (int i : link) {
        for (int j : link)
            l += power[i][j];
    }

    // 능력치 차이 최솟값 업데이트
    if (abs(s - l) < diff)
        diff = abs(s - l);
}

// | p : 처음으로 팀을 정해줄 사람
// | start : 스타트 팀 목록
// | link : 링크 팀 목록
// | p부터 남은 사람을 팀에 배정한 후 최소 능력치 차이 확인
void divide(int p, vector<int>& start, vector<int>& link)
{
    // base case : 모든 사람을 팀에 배정한 경우
    if (p == n)
        check_pow_diff(start, link);
    
    // 스타트 팀에 빈 자리가 있을 경우
    if (start.size() < n/2) {
        start.push_back(p);
        divide(p+1, start, link);
        start.pop_back();
    }

    // 링크 팀에 빈 자리가 있을 경우
    if (link.size() < n/2) {
        link.push_back(p);
        divide(p+1, start, link);
        link.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> power[i][j];
    }

    diff = 100000000; // diff의 초기값을 매우 큰 수로 설정
    vector<int> start, link;
    divide(0, start, link);

    cout << diff << endl;

    return 0;
}