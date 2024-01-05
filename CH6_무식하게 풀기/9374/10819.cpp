// TITLE 차이를 최대로 #10819

#include <bits/stdc++.h>
using namespace std;

// ? 최대 8!*8=322560번 연산 필요

int n;
bool visited[8] = {false, };
int arr[8];
int ans = -1;

// | pos : 수열을 만들기 시작할 위치
// | seq : 이미 고른 숫자 목록
// | pos부터 seq에 숫자를 넣어 수열을 완성 후 차이 비교
void makeSeq(int pos, vector<int> seq)
{
    // base case : 수열을 모두 완성한 경우
    if (pos == n) {
        int diff = 0;
        for (int i = 0; i < n-1; i++)
            diff +=  abs(seq[i] - seq[i+1]);
        if (diff > ans)
            ans = diff;
    }

    // pos에 아직 사용하지 않은 수를 대입해 차이 비교
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            seq.push_back(arr[i]);
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

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> seq;
    makeSeq(0, seq);

    cout << ans << endl;

    return 0;
}