// TITLE 단어 수학 #1339

#include <bits/stdc++.h>
using namespace std;

int n, alphaNum; // n : 단어 개수, alphaNum : 알파벳 종류 개수
string str[10]; // 단어 목록
char alpha[10]; // 알파벳 종류
int num[26]; // 알파벳에 할당된 수
bool chosen[10] = {false, }; // 숫자가 사용되었는지 여부 
int ans = -1; // 단어의 합 최댓값

// | s : 숫자로 바꾸고자 하는 단어
// | s를 숫자로 바꿔주는 함수
int stringIntoNum(string s)
{
    int ret = num[s[0]-'A'];
    for (int j = 1; j < s.length(); j++) {
        ret *= 10;
        ret += num[s[j]-'A'];
    }

    return ret;
}

// | pos : 숫자를 넣을 위치
// | pos 위치에 수를 넣어 최댓값 찾기
void guess(int pos)
{
    // base case : 모든 알파벳에 수를 채웠을 경우
    if (pos == alphaNum) {
        int curr = 0;
        for (int i = 0; i < n; i++)
            curr += stringIntoNum(str[i]);
        if (curr > ans)
            ans = curr;
        return;
    }
    // 0부터 9까지 수를 하나씩 대입하여 최댓값 찾기
    for (int i = 0; i < 10; i++) {
        if (!chosen[i]) {
            num[alpha[pos]-'A'] = i;
            chosen[i] = true;
            guess(pos+1);
            chosen[i] = false;
            num[alpha[pos]-'A'] = -1;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];

    alphaNum = 0;
    for (int i = 0; i < n; i++) {
        for (char ch : str[i]) {
            bool flag = false;
            for (int j = 0; j < alphaNum; j++) {
                if (alpha[j] == ch) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            
            alpha[alphaNum++] = ch;
        }
    }

    guess(0);
    cout << ans << endl;

    return 0;
}