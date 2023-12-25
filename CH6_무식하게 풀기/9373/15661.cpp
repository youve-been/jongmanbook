// TITLE 링크와 스타트 #15661

#include <bits/stdc++.h>
using namespace std;

// ? 최대 2^19*10*10*2 = 104857600번 연산 필요
// ! 같은 조합은 팀이 서로 바뀐다 해도 능력치 차이는 없으나 2배의 연산을 필요로 함
// ! 한 명을 한 팀에 고정해 같은 경우를 2번 발생시키지 않게 함

int n;
int power[20][20];
int minDiff = 1000000000;

void calcDiff(vector<int> start, vector<int> link)
{
    // 링크 팀에 아무도 없는 경우는 제외되어야 함
    if(link.empty())
        return;

    // 스타트 팀 능력치 계산
    int s = 0;
    for (int i : start) {
        for (int j : start)
            s += power[i][j];
    }

    // 링크 팀 능력치 계산
    int l = 0;
    for (int i : link) {
        for (int j : link)
            l += power[i][j];
    }

    // 능력치 차이 최솟값 업데이트
    if (minDiff > abs(s - l))
        minDiff = abs(s - l);
}

// | p : 팀을 배정해야 하는 사람
// | start : 스타트 팀 목록
// | link : 링크 팀 목록
// | p부터 능력치 차이가 최소가 되게 팀을 배정
void divide(int p, vector<int>& start, vector<int>& link)
{
    // base case : 모두에게 팀을 배정한 경우
    if (p == n) {
        calcDiff(start, link);
        return;
    }
    
    // p를 스타트 팀에 배정
    start.push_back(p);
    divide(p+1, start, link);
    start.pop_back();

    // p를 링크 팀에 배정
    link.push_back(p);
    divide(p+1, start, link);
    link.pop_back();
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
    
    vector<int> start, link;
    start.push_back(0); // ! start 팀에 0번 고정
    divide(1, start, link);

    cout << minDiff << endl;

    return 0;
}