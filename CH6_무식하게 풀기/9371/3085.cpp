// TITLE 사탕 게임 #3085

#include <bits/stdc++.h>
using namespace std;

// ? 시간복잡도는 O(n^4)이지만 n의 최댓값이 작으므로 시간 내에 계산 가능

int n;
string board[51];
int max_candy = -1;

// | 가장 긴 연속 부분을 계산하여 최댓값을 업데이트
void find_longest()
{
    int cnt, ans = 0;

    // 행에서 가장 긴 연속부분 찾기
    for (int i = 0; i < n; i++) {
        // ! for문의 변수가 for문 내에서도 증감되므로 증감식을 사용하면 중복될 수 있음
        // ! 따라서 for문으로 작성하는 경우 증감식 칸을 비워야 함
        // ! 또는 종료조건만 결정해주는 while문으로 작성하는 방법이 있음
        for (int j = 0; j < n;) {  
            char curr = board[i][j];
            j++;
            cnt = 1;
            while (j < n && board[i][j] == curr) {
                j++;
                cnt++;
            }
            if (cnt > ans)
                ans = cnt;
        }
    }

    // 열에서 가장 긴 연속부분 찾기
    for (int j = 0; j < n; j++) {
        // ! for문의 변수가 for문 내에서도 증감되므로 증감식을 사용하면 중복될 수 있음
        // ! 따라서 for문으로 작성하는 경우 증감식 칸을 비워야 함
        // ! 또는 종료조건만 결정해주는 while문으로 작성하는 방법이 있음
        for (int i = 0; i < n;) {
            char curr = board[i][j];
            i++;
            cnt = 1;
            while (i < n && board[i][j] == curr) {
                i++;
                cnt++;
            }
            if (cnt > ans)
                ans = cnt;
        }
    }

    if (ans > max_candy)
        max_candy = ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    // 같은 행의 인접한 두 칸 바꾸기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (board[i][j] != board[i][j+1]) { 
                swap(board[i][j], board[i][j+1]);
                find_longest();
                swap(board[i][j], board[i][j+1]);
            }
        }
    }

    // 같은 열의 인접한 두 칸 바꾸기
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n-1; i++) { 
            if (board[i][j] != board[i+1][j]) {
                swap(board[i][j], board[i+1][j]);
                find_longest();
                swap(board[i][j], board[i+1][j]);
            }
        }
    }
    // ! 사탕의 색이 서로 다른 두 칸만 교환 가능

    cout << max_candy << endl;

    return 0;
}