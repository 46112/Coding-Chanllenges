#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
<조세퍼스의 문제>
N명의 사람들이 원 모양으로 둥글게 앉아있음
시계방향으로 1부터 N까지 번호를 부여받음
1번부터 지목을 당하면서 게임이 시작됨 -> 그 다음번에는 시계방향으로 돌면서 바로 옆에 있는 사람을 지목함
M번째로 지목을 받은 사람은 게임에서 제외시킴 -> 제외된 사람 바로 다음 사람부터 다시 게임 시작

사람들이 게임에서 제외되는 순서를 출력하는 문제
순서대로 돌아가며 지목당하므로, 큐잉 필요
지목당한다 = pop
M번째 지목당한 사람이 아니다 = pop한 것을 다시 push

*/

class Player {
public:
    int index;

    Player(int index) {
        this->index = index;
    }
};

// 게임에서 제외된 플레이어들을 순서대로 집어넣은 배열을 만들어 반환하는 메서드
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players) {
    vector<Player> deadPlayers;

    queue<Player> playerQueue; // 큐에 지목되는 순서대로 채워넣어 초기화 = 게임시작 준비
    for (int i = 0; i < players.size(); i++)
    {
        playerQueue.push(players[i]);
    }

    int popCount = 0; // pop된 횟수
    // 실질적인 게임 시작
    while(!playerQueue.empty())// 큐가 비워질 때까지 (모두가 게임에서 제외될 때까지) 게임은 계속됨
    {
        Player temp = playerQueue.front();
        playerQueue.pop();// pop = 지목당한 것
        popCount++;
        
        if (popCount == m) // m번째로 지목된 사람 = 제거
        {
            deadPlayers.push_back(temp);
            popCount = 0;
            continue;// 제거된 사람은 플레이어 목록에 다시 집어넣으면 안됨
        }

        playerQueue.push(temp);
    }
    
    return deadPlayers;
}

void process(int caseIndex) {
    int n, m;
    cin >> n >> m;

    vector<Player> players;
    for (int i = 0; i < n; i++)
    {
        players.push_back(Player(i + 1));// 플레이어들에게 1부터 N까지 번호를 부여함
    }

    vector<Player> deadPlayers = getDeadPlayersList(n, m, players);
    for (int i = 0; i < n; i++)
    {
        if (i > 0) cout << " ";// 번호 가독성을 위해 첫번째 이후로는 띄어쓰기 포함해 출력
        
        Player p = deadPlayers[i];
        cout << p.index;// 게임에서 제외된 플레이어들의 번호를 제외된 순서대로 출력
    }
    cout << endl;
}

int main() {
    int caseSize;// 테스트 케이스 개수
    cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
        process(caseIndex); // 각 테스트 케이스별로 실행
    }
}