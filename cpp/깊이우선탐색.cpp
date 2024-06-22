#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/*
<깊이 우선 탐색>
깊이 우선 탐색은 말 그대로 깊이를 우선 시해서 그래프를 탐색하는 방법이다
시작노드에서부터 더 이상 탐색이 불가능할 때까지 내려가서 탐색한 뒤, 탐색이 가능한 노드가 나올 때까지 지나온 길을 되돌아가는 방식이다
그렇기에 깊이 우선 탐색은 재귀함수를 사용하거나 스택 구조를 이용해 구현할 수 있다

*/
const int MAP_SIZE = 10;// map의 0은 사용하지 않는다고 했을 때, 노드 1부터 map_size-1만큼 노드들의 연결상황을 표현할 수 있다

int maps[MAP_SIZE][MAP_SIZE];
bool isVisited[MAP_SIZE] = {false};// 노드 방문 여부 표현
int num;

void init() {// 그래프를 나타내는 이차원 배열 maps 초기화
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            maps[i][j] = 0;
        }
    }
}

void dfs(int visited_node) {
    // 방문 노드는 출력한 뒤, 표시해둔다
    isVisited[visited_node] = true;
    cout << visited_node << endl;

    // 노드 번호는 1번부터 시작
    for (int candidate = 1; candidate < MAP_SIZE; candidate++)//
    {
        // 방문 후보 노드들을 찾는다 - 1. 현재 방문 노드와 연결되어있어야하고 2. 방문한 적이 없어야한다
        if (maps[visited_node][candidate] == 1 && isVisited[candidate] == false)
        {
            dfs(candidate);// 재귀함수로 dfs구현
        }
    }
}

int main() {
    int v1, v2;
    init();// maps배열 초기화
    cin >> num;
    for (int i = 0; i < num; i++) // input으로 연결 현황 정보를 받는다 - 노드들의 번호는 map_size보다 작아야한다
    {
        cin >> v1 >> v2;
        maps[v1][v2] = maps[v2][v1] = 1; // v1과 v2가 연결되어 있음(무향 그래프이므로 둘 다 표현)
    }

    dfs(1);// 1번 노드를 시작점으로 깊이 우선 탐색 시작
    return 0;
}