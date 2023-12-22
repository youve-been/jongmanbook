// TITLE N과 M (5) #15654

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[8];
bool visited[8] = {false, };

// | start : 수열을 고르기 시작하는 위치
// | cnt : 골라야할 수의 개수
// | chosen : 이미 고른 수의 목록
// | start번째 수부터 cnt개를 골라 수열 만들기
void func(int cnt, vector<int>& chosen)
{
    // base case : 수열을 모두 채웠을 경우
    if (cnt == 0) {
        for (int i : chosen) 
            cout << i << " ";
        cout << '\n';
        return;
    }

    // start부터 수를 하나 고름
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            chosen.push_back(arr[i]);
            func(cnt-1, chosen);
            chosen.pop_back();
            visited[i] = false;
        }
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
    func(m, chosen);

    return 0;
}