// TITLE 수 이어 쓰기 1 #1748

#include <bits/stdc++.h>
using namespace std;

// ! 최대 100000000번의 연산 필요 -> 0.15초 내에 불가능

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    if (n < 1000000) {
        for (int i = 1; i <= n; i++)
            cnt += to_string(i).length();
    }
    else if (n < 10000000) {
        cnt = 5888896 + (n / 1000000 - 1) * 7000000;
        cnt += n % 1000000 * 7;
    }
    else {
        cnt = 68888897 + 80000000 * (n / 10000000 - 1);
        cnt += n % 10000000 * 8;
    }

    if (n == 100000000)
        cnt++;

    cout << cnt << endl;

    return 0;
}