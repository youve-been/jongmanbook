// TITLE 쿼드 트리 뒤집기 (ID : QUADTREE)

#include <bits/stdc++.h>
using namespace std;

int pos;
string pic;

// | pos 위치부터 x로 시작하는 문자열의 상하 뒤집기
string flip()
{
    string top = ""; // 위쪽에 해당하는 문자열
    string bottom = ""; // 아래쪽에 해당하는 문자열

    pos++;
    // 위쪽 문자열 구성하기
    for (int i = 0; i < 2; i++) {
        if (pic[pos] == 'x')
            top += flip();
        else {
            top += pic[pos];
            pos++;
        }
    }

    // 아래쪽 문자열 구성하기
    for (int i = 0; i < 2; i++) {
        if (pic[pos] == 'x')
            bottom += flip();
        else {
            bottom += pic[pos];
            pos++;
        }
    }

    return "x" + bottom + top;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int x = 0; x < tc; x++) {
        cin >> pic;
        if (pic.size() > 1) {
            pos = 0;
            cout << flip() << '\n';
        }
        // 크기가 1인 경우 뒤집어도 동일하므로 입력 그대로 출력
        else
            cout << pic << '\n';
    }

    return 0;
}