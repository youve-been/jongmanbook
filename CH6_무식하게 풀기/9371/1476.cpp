// TITLE 날짜 계산 #1476

#include <bits/stdc++.h>
using namespace std;

// ? 최대 15*28*19 = 7980번 연산 필요

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int e = 1, s = 1, m = 1;
    int earth, sun, moon;
    int year = 1;

    cin >> earth >> sun >> moon;

    while (true) {
        if (e == earth && s == sun && m == moon) {
            cout << year << endl;
            return 0;
        }
        e == 15 ? e = 1 : e++;
        s == 28 ? s = 1 : s++;
        m == 19 ? m = 1 : m++;
        year++;
    }

    return 0;
}