// TITLE 퇴사 #14501

#include <bits/stdc++.h>
using namespace std;

int n;
int c_time[15]; // 날짜별 상담시간
int c_price[15]; // 날짜별 상담금액

// | start : 상담 시작 날짜
// | start일부터 상담을 통해 얻을 수 있는 최대 이익을 반환
int counsel(int start)
{
    // start일부터 상담했을 경우 최대 이익 비교
    int curr, max = 0;
    for (int i = start; i < min(n, start + c_time[start] ); i++) {
        if (i+c_time[i]-1 < n) {
            curr = c_price[i] + counsel(i+c_time[i]);
            if (curr > max)
                max = curr;
        }
    }

    return max;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> c_time[i] >> c_price[i];

    cout << counsel(0) << endl;

    return 0;
}