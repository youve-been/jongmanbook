// TITLE 1, 2, 3 더하기 #9095

#include <bits/stdc++.h>
using namespace std;

// ? 최대 3^10가지 경우가 존재하지만 가능한 경우의 수는 훨씬 작음

// | num : 1, 2, 3으로 나타내야 하는 수
// | num을 1, 2, 3을 이용하여 나타내는 경우의 수
int calc(int num)
{
    // base case : num이 0, 1, 2, 3인 경우
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else if (num == 2)
        return 2;
    else if (num == 3)
        return 4;
    

    // num을 구성하는 첫 수로 1, 2, 3을 골랐을 때 경우의 수 각각 계산
    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans += calc(num - i);
    
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;
    
    for (int x = 0; x < tc; x++) {
        int n;
        cin >> n;

        cout << calc(n) << '\n';
    }

    return 0;
}