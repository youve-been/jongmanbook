// TITLE 로또 #6603

#include <bits/stdc++.h>
using namespace std;

// ? 최대 13C6*tc수 만큼의 연산 필요

int k;
int s[13];

// | start : 숫자를 뽑기 시작하는 위치
// | chosen : 이미 뽑은 숫자 목록
// | cnt : 더 뽑아야 하는 숫자 개수
// | start부터 cnt개의 숫자를 뽑아 출력
void choose(int start, vector<int>& chosen, int cnt)
{
    // base case : 숫자를 모두 뽑았을 경우
    if (cnt == 0) {
        for (int i : chosen)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // start부터 시작하여 숫자를 하나 뽑음
    for (int i = start; i < k - cnt + 1; i++) {
        chosen.push_back(s[i]);
        choose(i+1, chosen, cnt-1);
        chosen.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    
    while (k != 0) {
        for (int i = 0; i < k; i++)
            cin >> s[i];
        
        vector<int> chosen;
        choose(0, chosen, 6);

        cout << '\n';
        cin >> k;
    }

    return 0;
}
