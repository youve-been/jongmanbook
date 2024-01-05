// TITLE 모든 순열 #10974

#include <bits/stdc++.h>
using namespace std;

// ? 최대 8!=40320번 연산 필요

int n;
bool visited[8] = {false, };

// | pos : 숫자를 대입할 위치
// | seq : 이미 선택한 숫자 목록
// | pos부터 숫자를 선택하여 수열 완성 후 출력
void makeSeq(int pos, vector<int>& seq)
{
    // base case : 수열을 완성한 경우
    if (pos == n) {
        for (int i : seq)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // 사용하지 않은 수 중 숫자를 골라 수열을 이어서 완성
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            seq.push_back(i+1);
            makeSeq(pos+1, seq);
            seq.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<int> seq;
    makeSeq(0, seq);

    return 0;
}