// TITLE 부분수열의 합 #1182

#include <bits/stdc++.h>
using namespace std;

// ? 최대 2^20 - 1 = 1048575가지 경우의 수 존재

int n, s;
int arr[20];

// | sum : 선택한 수를 더한 합계
// | pos : 숫자 고르기를 시작할 위치
// | cnt : 수열에 포함된 수의 개수
// | pos부터 숫자를 골라 sum이 s가 되게 할 수 있는 경우의 수 반환
int add(int sum, int pos, int cnt)
{
    int ans = 0;
    // base case : 숫자를 모두 고른 경우
    if (pos == n)
        return (sum == s && cnt > 0) ? 1 : 0;
    
    // arr[pos]를 수열에 포함한 경우
    ans += add(sum + arr[pos], pos + 1, cnt + 1);
    // s[pos]를 수열에 포함하지 않은 경우
    ans += add(sum, pos + 1, cnt);

    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << add(0, 0, 0) << endl;

    return 0;
}