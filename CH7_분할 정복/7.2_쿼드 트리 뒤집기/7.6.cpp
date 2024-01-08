// TITLE 쿼드 트리 뒤집기

#include <bits/stdc++.h>
using namespace std;

// - 필요한 변수 및 함수 -
#define MAX_SIZE 100 // 그림의 최대 크기

// TODO 7.5 쿼드 트리 압축을 해제하는 재귀 호출 알고리즘
char decompressed[MAX_SIZE][MAX_SIZE];
void decompress(string::iterator& it, int y, int x, int size)
{
    // 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮김
    char head = *(it++);

    // 기저 사례 : 첫 글자가 b 또는 w인 경우
    if (head == 'b' || head == 'w') {
        for (int dy = 0; dy < size; dy++) {
            for (int dx = 0; dx < size; dx++)
                decompressed[y+dy][x+dx] = head;
        }
    }
    else {
        // 네 부분을 각각 순서대로 압축 해제
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x+half, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}


// TODO 7.6 쿼드 트리 뒤집기 문제를 해결하는 분할 정복 
// ? 시간복잡도 : O(n)

string reverse(string::iterator& it)
{
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 각각 위와 아래 조각들의 위치를 바꿈
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}