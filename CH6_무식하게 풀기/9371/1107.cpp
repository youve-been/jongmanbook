// TITLE 리모컨 #1107

#include <bits/stdc++.h>
using namespace std;

// ? 최대 1000000까지만 검사하면 되고, 시간제한이 넉넉함

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    bool button[10] = {false, };
    int tmp;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        button[tmp] = true;
    }

    int ans = abs(n - 100); // 100부터 '+'나 '-'를 이용해 이동하는 횟수
    string channel;
    for (int i = 0; i < 1000000; i++) {
        channel = to_string(i);

        // 고장난 버튼을 눌러야 하는지 확인
        bool flag = false;
        for (char ch : channel) {
            if (button[ch - '0']) {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        
        // i번 채널에서 n번 채널로 가는 횟수 계산
        ans = ans > channel.length() + abs(i - n) ? channel.length() + abs(i - n) : ans;
    }

    cout << ans << endl;

    return 0;
}