// TITLE N과 M (8) #15657

#include <bits/stdc++.h>
using namespace std;


int n;
int arr[8];

// | start : 수열을 만들 수 있는 수의 최솟값
// | cnt : 골라야하는 수의 개수
// | chosen : 이미 고른 수의 목록
// | cnt개의 수를 중복을 포함하여 뽑아 비내림차순 수열 만들기
void func(int start, int cnt, vector<int>& chosen)
{
    // base case : 수열을 완성한 경우
    if (cnt == 0) {
        for (int i : chosen)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // 중복을 포함하여 수를 뽑아 수열에 포함
    for (int i = start; i < n; i++) {
        chosen.push_back(arr[i]);
        func(i, cnt-1, chosen);
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