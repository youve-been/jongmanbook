// TITLE 중첩 반복문 대체하기
#include <bits/stdc++.h>
using namespace std;

int main(void) {

    // - 필요한 변수 및 상수 -
    int n; // 원소의 총 개수

    // TODO n개의 원소 중 4개를 고르는 모든 경우를 출력 (4중 for문)
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                for (int l = k+1; l < n; l++)
                    cout << i << " " << j << " " << k << " " << l << endl;
            }
        }
    }
}



// - 필요한 변수 및 함수 -
void printPicked(vector<int> picked); // 고른 원소들의 번호를 출력

// TODO 6.2 n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘

// | n : 전체 원소의 수
// | picked : 지금까지 고른 원소들의 번호
// | toPick : 더 고를 원소의 수
// | 일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력
void pick(int n, vector<int>& picked, int toPick)
{
    // 기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력
    if (toPick == 0) {
        printPicked(picked);
        return;
    }
    // 고를 수 있는 가장 작은 번호를 계산
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    // 이 단계에서 원소 하나를 고름
    for (int next = smallest; next < n; next++) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}