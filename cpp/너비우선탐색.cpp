#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

/*
<너비 우선 탐색>
너비 우선 탐색은 말 그대로 너비를 우선 시해서 그래프를 탐색하는 방법이다
주변 노드들을 먼저 방문한 다음, 더 이상 방문한 노드가 없으면 그때서야 앞서 방문했던 
노드들의 주변노드를 방문하는 방식으로, 앞서 방문한 노드들에서 앞으로 방문할 후보 노드들을 미리 받아와야하기에
queue를 사용해서 구현한다. 또한 큐에 담긴 미리 방문할 노드들은 중복되면 안되므로 보통
정말로 방문했을 때 isVisited를 변경하지 않고, 큐에 담긴 순간 방문한 것으로 간주한다

*/
const int MAP_SIZE = 10;// map의 0은 사용하지 않는다고 했을 때, 노드 1부터 map_size-1만큼 노드들의 연결상황을 표현할 수 있다

int maps[MAP_SIZE][MAP_SIZE] = {0};
bool isVisited[MAP_SIZE] = {false};// 노드 방문 여부 표현
queue<int> q;
int num, edge_num;

void bfs(int start) {
    q.push(start);// 출발지 노드를 앞으로 방문할 노드들을 모아놓은 queue에 저장
    isVisited[start] = true;

    while (!q.empty()) {// 큐가 빌 때까지(더 이상 방문할 노드가 없을 때까지) 반복
        int cur_visited_node = q.front();// 이번에 방문할 노드
        cout << cur_visited_node << "\n";// 방문 노드 출력
        q.pop();// 방문했으니 큐에서 제거
        
        for (int i = 1; i < MAP_SIZE; i++) {// 방문 노드에서 bfs 알고리즘에 따라 다음에 방문할 노드들을 큐에 저장해놓음
            if (maps[cur_visited_node][i] == 1 && isVisited[i] == false)// 현재 방문 노드와 연결되어 있으면서 방문한 적 없는 노드들이 다음에 방문할 노드이다
            {
                q.push(i);// i번 노드는 앞으로 방문할 노드
                isVisited[i] = true; // 큐에 넣은 이상 언젠가는 방문하게 되는데 그 사이 중복되지 않도록 미리 방문처리를 해놓는다
            }
        }     
    }
}


int main() {
    cin >> num >> edge_num;
    for (int i = 0; i < edge_num; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        maps[v1][v2] = maps[v2][v1] = 1;// 무향 그래프이므로 양측에 대해 간선 표현
    }

    bfs(1);// 출발 노드 1로 bfs시작
    return 0;
}