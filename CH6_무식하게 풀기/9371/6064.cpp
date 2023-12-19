// TITLE 카잉 달력 #6064

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    int m, n, x, y;
    cin >> tc;

    // ! 모든 케이스에 대해 1부터 탐색하면 한 케이스 당 최대 40000*40000번 연산 -> 불가능
    // ! 시간복잡도를 O(n^2)에서 O(n)으로 줄임
    
    for (int t = 0; t < tc; t++) {
        cin >> m >> n >> x >> y;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if ((m*i+x) % n == y % n) {
                cout << m * i + x << '\n';
                flag = true;
                break;
            }
        }

        if (!flag)
            cout << -1 << '\n';
    }

    return 0;
}

// TODO 추후 중국인의 나머지정리에 대해 공부한 후 다시 풀어보기