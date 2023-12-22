// TITLE N과 M (1) #15649

#include <bits/stdc++.h>
using namespace std;

// ? 최대 8! = 40320번 연산 필요

int n; // 수열에 포함시킬 수의 최댓값
bool visited[8] = {false, }; // 수를 수열에 포함시켰는지 확인하는 배열

// | cnt : 수열에 포함시켜야할 수의 개수
// | chosen : 이미 고른 수의 목록
// | cnt개의 숫자를 중복없이 뽑아 수열 만들기
void func(int cnt, vector<int>& chosen)
{
    // base case : 수열에 m개의 수를 모두 포함시킨 경우
    if (cnt == 0) {
        for (int i : chosen)
            cout << i << " ";
        cout << '\n';
        return;
    }

    // 중복 없이 1개를 골라 수열을 만듦
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            chosen.push_back(i+1);
            func(cnt - 1, chosen);
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
    
    vector<int> chosen;
    func(m, chosen);

    return 0;
}