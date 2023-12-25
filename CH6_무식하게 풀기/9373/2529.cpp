// TITLE 부등호 #2529

#include <bits/stdc++.h>
using namespace std;

// ? 최대 10! = 3628800번 연산 필요

int k;
char ineq[9];
bool visited[10] = {false, }; // 숫자를 사용했는지 표시하는 배열
string max_num = "0"; // 최댓값 저장
string min_num = "999999999"; // 최솟값 저장

// | nums : 숫자 목록
// | nums가 부등식을 만족하는지 확인후 최댓값 및 최솟값 업데이트
void check_ineq(string nums)
{
    bool flag = true;
    for (int i = 0; i < k; i++) {
        if ((ineq[i] == '<' && nums[i] >= nums[i+1]) || (ineq[i] == '>' && nums[i] <= nums[i+1])) {
            flag = false;
            break;
        }
    }

    if (!flag)
        return;
    
    if (max_num < nums)
        max_num = nums;
    if (min_num > nums)
        min_num = nums;
}

// | cnt : 더 입력해야 하는 숫자 개수
// | nums : 이미 입력된 숫자 목록
// | cnt개의 숫자를 입력하여 부등호를 만족시키는 문장을 찾음
void func(int cnt, string nums)
{
    // base case : 숫자 입력을 완료한 경우
    if (cnt == 0) {
        check_ineq(nums);
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            nums.push_back(i+'0');
            visited[i] = true;
            func(cnt - 1, nums);
            visited[i] = false;
            nums.pop_back();
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++)
        cin >> ineq[i];

    string nums = "";
    func(k+1, nums);

    cout << max_num << '\n';
    cout << min_num << '\n';

    return 0;
}