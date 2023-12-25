// TITLE 암호 만들기 #1759

#include <bits/stdc++.h>
using namespace std;

// ? 최대 15개 중 순서 없이 l개를 뽑는 경우의 수와 같음

#define isVowel(a) ((a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u')) ? true : false

int c;
char cand[15]; // 사용했을법한 문자 목록

// | pw : 암호 후보
// | pw가 유효한 암호인지 확인 후 유효하면 출력
void validate(string pw)
{
    int vow = 0;
    int con = 0;
    for (char ch : pw) {
        if (isVowel(ch))
            vow++;
        else
            con++;
    }

    if (vow >= 1 && con >= 2)
        cout << pw << '\n';
}

// | len : 추가해야하는 문자 개수
// | start : 들어갈 수 있는 문자의 시작 위치
// | pw : 이미 추가한 문자 목록
// | len개만큼 문자를 pw에 추가하여 암호 만들기
void guess(int len, int start, string pw)
{
    // base case : 암호 후보를 완성한 경우
    if (len == 0) {
        validate(pw);
        return;
    }

    for (int i = start; i < c; i++) {
        pw.push_back(cand[i]);
        guess(len-1, i+1, pw);
        pw.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l;
    cin >> l >> c;

    for (int i = 0; i < c; i++)
        cin >> cand[i];
    sort(cand, cand+c);
    
    string pw = "";
    guess(l, 0, pw);

    return 0;
}