// TITLE 부분수열의 합 #14225

#include <bits/stdc++.h>
using namespace std;

// ? O(2^n * n)이지만 n이 20까지로 매우 작으므로 시간 내에 실행될 수 있음
// ! 1부터 자연수를 세며 해당 자연수를 만들 수 있는지를 판별한다면
// ! 최악의 경우 계산횟수가 너무 많아짐
// ! 따라서 미리 만들 수 있는 수의 조합을 bool 배열에 표시하고
// ! 해당 배열에서 표시되지 않은 가장 작은 자연수를 찾는 것이 빠름

int n;
int arr[20];
bool able[2000001];

// | pos : 사용 여부를 결정할 수의 위치
// | sum : 이미 포함된 수의 합
// | pos 이후의 수를 사용하여 만들 수 있는 수를 확인
void make(int pos, int sum)
{
    // base case : 모든 수의 사용 여부를 결정한 경우
    if (pos == n) {
        able[sum] = true;
        return;
    }
    
    // arr[pos]를 사용하는 경우
    make(pos+1, sum + arr[pos]);
    // arr[pos]를 사용하지 않는 경우
    make(pos+1, sum);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    make(0, 0);
    
    int i = 1;
    while (true) {
        if (!able[i]) {
            cout << i << endl;
            break;
        }
        i++;
    }

    return 0;
}