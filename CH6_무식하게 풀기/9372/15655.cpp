// TITLE N과 M (6) #15655

#include <bits/stdc++.h>
using namespace std;

// ? 최대 8! = 40320번 연산 필요

int n;
int arr[8];

// | start : 숫자를 고르기 시작하는 위치
// | cnt : 골라야할 수의 개수
// | chosen : 이미 고른 수의 목록
// | start 이후의 cnt개의 수를 골라 수열 만들기
void func(int start, int cnt, vector<int>& chosen)
{
    // base case : 수열을 모두 완성한 경우
    if (cnt == 0) {
        for (int i : chosen)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // 오름차순으로 start 이후의 수를 고름
    for (int i = start; i < n - cnt + 1; i++) {
        chosen.push_back(arr[i]);
        func(i+1, cnt-1, chosen);
        chosen.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    vector<int> chosen;
    func(0, m, chosen);

    return 0;
}