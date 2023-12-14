// TITLE 여행하는 외판원 문제

#include <bits/stdc++.h>
using namespace std;

// - 필요한 변수 및 함수 -
#define MAX 10 // 도시의 수
#define INF 2000000000 // 초기화에 필요한 매우 큰 값

// TODO 6.7 여행하는 외판언 문제를 해결하는 재귀 호출 알고리즘

int n; // 도시의 수
double dist[MAX][MAX]; // 두 도시 간의 거리를 저장하는 배열

// | path : 지금까지 만든 경로
// | visited : 각 도시의 방문 여부
// | currentLength : 지금까지 만든 경로의 길이
// | 나머지 도시들을 모든 방문하는 경로 중 가장 길이가 짧은 것의 길이를 반환
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
    // 기저 사례 : 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료
    if (path.size() == n)
        return currentLength + dist[path[0]][path.back()];
    
    double ret = INF; // 매우 큰 값으로 초기화
    // 다음 방문할 도시를 전부 시도
    for (int next = 0; next < n; next++) {
        if (visited[next])
            continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        // 나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻음
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}