// TITLE Guess #1248

#include <bits/stdc++.h>
using namespace std;

// ? 최대 10^10번 이상의 가능성이 많지만 가능한 정답이 많아
// ? 모두 시도하기 이전에 빨리 결과 도출 가능

int n;
char mat[10][10];
int sign[10];

// | x : 계산하고자 하는 곳의 세로 위치
// | y : 계산하고자 하는 곳의 가로 위치
// | seq : 수열
// | seq가 (i, j) 위치의 sign matrix에 성립하는지 확인
bool validate(int x, int y, vector<int>& seq)
{
    int ans = 0;
    for (int i = x; i <= y; i++)
        ans += sign[i] * seq[i];
    
    if ((mat[x][y] == '+' && ans > 0) || (mat[x][y] == '-' && ans < 0) || (mat[x][y] == '0' && ans == 0))
        return true;
    else
        return false;
}

// |
bool genSeq(int pos, vector<int>& seq)
{
    // base case : 수열을 완성한 경우
    if (pos == n) {
        for (int i = 0; i < n; i++)
            cout << seq[i] * sign[i] << " ";
        return true;
    }

    // pos 자리에 0이 들어가야 하는 경우
    if (sign[pos] == 0) {
        seq.push_back('0');
        if (genSeq(pos+1, seq))
            return true;
        seq.pop_back();
        return false;
    }

    bool flag;
    for (int i = 1; i <= 10; i++) {
        flag = true;
        seq.push_back(i);

        // pos 열의 sign matrix가 유효한지 확인
        for (int j = 0; j < pos; j++) {
            if (!validate(j, pos, seq)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (genSeq(pos+1, seq))
                return true;
        }
        seq.pop_back();
    }

    return false;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    string s;
    cin >> s;

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            mat[i][j] = s[idx++];
        sign[i] = mat[i][i] == '+' ? 1 : (mat[i][i] == '0' ? 0 : -1);
    }

    vector<int> seq;
    if (!genSeq(0, seq))
        cout << "WHAT?" << endl;

    return 0;
}