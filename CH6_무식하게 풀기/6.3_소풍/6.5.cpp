// TITLE 소풍

#include <bits/stdc++.h>
using namespace std;

// TODO 6.4 소풍 문제를 해결하는 (잘못된) 재귀 호출 코드

int n;
bool areFriends[10][10];

// | taken[i] : i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10])
{
    // 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료
    bool finished = true;
    for (int i = 0; i < n; i++) {
        if (!taken[i])
            finished = false;
    }
    if (finished)
        return 1;
    
    int ret = 0;
    // 서로 친구인 두 학생을 찾아 짝을 지어줌
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!taken[i] && areFriends[i][j]) {
                taken[i] = taken[j] = true;
                ret += countPairings(taken);
                taken[i] = taken[j] = false;
            }
        }
    }

    return ret;
}
// ! 같은 학생 쌍을 두 번 짝지어줌
// ! 다른 순서로 같은 쌍의 학생을 짝짓는 것을 서로 다른 경우로 계산함


// TODO 6.5 소풍 문제를 해결하는 재귀 호출 코드
// ? 가장 경우의 수가 많을 때 : 945가지

int n;
bool areFriends[10][10];

// | taken[i] : i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10])
{
    // 남은 학생들 중 가장 번호가 빠른 학생을 찾음
    int firstFree = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }
    // 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료
    if (firstFree == -1)
        return 1;
    
    int ret = 0;
    // 이 학생과 짝지을 학생을 결정
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}