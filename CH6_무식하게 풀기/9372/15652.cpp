// TITLE N과 M (4) #15652

#include <bits/stdc++.h>
using namespace std;

int n;

// | prev : 수열에 가장 마지막으로 들어간 수, 이후 수열의 하한
// | cnt : 수열에 들어가야하는 수의 개수
// | chosen : 이미 수열에 포함되어 있는 수
// | prev보다 크거나 같은 수 cnt개로 수열 만들기
void func(int prev, int cnt, vector<int>& chosen)
{
    // base case : 수열을 모두 만든 경우
    if (cnt == 0) {
        for (int i : chosen)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // prev보다 크거나 같은 수 뽑기
    for (int i = prev; i < n; i++) {
        chosen.push_back(i+1);
        func(i, cnt - 1, chosen);
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
    func(0, m, chosen);

    return 0;
}