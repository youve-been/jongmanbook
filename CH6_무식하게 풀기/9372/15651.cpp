// TITLE N과 M (3) #15651

#include <bits/stdc++.h>
using namespace std;

// ? 최대 7^7 = 823543번 연산 필요

int n; // 수열에 포함될 수 있는 수의 최댓값

// | cnt : 수열에 넣어야할 수의 개수
// | chosen : 수열에 이미 포함된 수의 목록
// | cnt개의 수를 포함하여 수열 만들기
void func(int cnt, vector<int>& chosen)
{
    // base case : 수열에 수를 모두 넣음
    if (cnt == 0) {
        for (int i : chosen)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // 1부터 n까지의 수 중 하나를 수열에 넣음
    for (int i = 0; i < n; i++) {
        chosen.push_back(i+1);
        func(cnt - 1, chosen);
        chosen.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> n >> m;

    vector<int> chosen;
    func(m, chosen);

    return 0;
}