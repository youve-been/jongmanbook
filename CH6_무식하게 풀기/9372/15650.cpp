// TITLE N과 M (2) #15650

#include <bits/stdc++.h>
using namespace std;

int n; // 수열에 넣을 수 있는 수의 최댓값
bool visited[8] = {false, }; // 수열에 수를 포함시켰는지 나타내는 배열

// | start : 수열에 넣을 수 있는 최솟값
// | cnt : 수열에 넣어야할 수의 개수
// | start부터 n까지의 수 중 cnt개를 중복없이 뽑아 오름차순인 수열 만들기
void func(int start, int cnt)
{
    // base case : 수열에 수를 모두 뽑은 경우
    if (cnt == 0) {
        for (int i = 0; i < n; i++) {
            if (visited[i])
                cout << i+1 << " ";
        }
        cout << '\n';
        return;
    }

    // 중복 없이 1개를 골라 수열을 만듦
    for (int i = start; i < n - cnt + 1; i++) {
        visited[i] = true;
        func(i+1, cnt-1);
        visited[i] = false;
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> n >> m;

    func(0, m);

    return 0;
}