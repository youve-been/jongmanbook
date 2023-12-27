// TITLE 에너지 모으기 #16198

#include <bits/stdc++.h>
using namespace std;

// ? O(2n*(n-2)!)이지만 n이 10으로 매우 작으므로 시간내에 수행 가능

// | n : 남아있는 구슬의 수
// | weight : 남아있는 구슬의 무게 목록
// | 구슬을 모두 모아 만들 수 있는 에너지 최댓값 반환
int collect(int n, vector<int>& weight)
{
    // base case : 에너지 구슬이 3개 남은 경우
    if (n == 3) 
        return weight[0] * weight[2];

    int e, curr;
    int max = -1;
    for (int i = 1; i < n - 1; i++) {
        e = weight[i];
        weight.erase(weight.begin() + i);
        curr = collect(n-1, weight) + weight[i-1] * weight[i];
        weight.insert(weight.begin() + i, e);

        if (curr > max)
            max = curr;
    }

    return max;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    
    cout << collect(n, weight) << endl;


    return 0;
}