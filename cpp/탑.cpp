#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
<탑>
꼭대기 층에서 레이저 신호를 보낼 수 있는 크기가 다른 타워들이 순서대로 세워짐
레이저 신호는 오른쪽에서 왼쪽 방향으로만 발사
오른쪽 타워에서 보낸 신호는 왼쪽 타워의 높이가 더 클 경우에만 수신 가능
각각의 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는 지 타워 번호(1,2,...,N)를 저장
만약 아무도 신호를 받을 수 없는 경우는 0출력
*/

class Tower {
public:
    int index;
    int height;
    int targetTowerIndex;//기본값은 0으로 설정해 아무도 수신하지 않는 경우 기본값으로 반환

    Tower(int index, int height) {
        this->index = index;
        this->height = height;
        this->targetTowerIndex = 0;
    }

    void setTargetTowerIndex(int targetTowerIndex) {//수신 타워 인덱스 setter
        this->targetTowerIndex = targetTowerIndex;
    }

    int getTargetTowerIndex() {//수신 타워 인덱스 getter
        return this->targetTowerIndex;
    }
};

// 수신 타워의 인덱스를 알아내는 함수
void findTargetTowers(vector<Tower>& towers) {
    stack<Tower> touchableTowers;//앞으로 수신될 가능성이 있는 탑들

    for (int i = 0; i < towers.size(); i++)
    {
        Tower& curTower = towers[i];
        int targetTowerIndex = 0;

        while(!touchableTowers.empty() && touchableTowers.top().height < curTower.height) {
            // 현재 탑(상대적으로 오른쪽에 있는 탑)보다 작은 탑들은 앞으로는 수신될 가능성이 없다 - 현재 탑이 앞에 서서 모든 신호를 수신해버릴 것이니
            touchableTowers.pop();
        }

        // pop이 끝나고 남은 stack에는 현재 타워보다 더 큰 타워들만 남아있다
        if (touchableTowers.size() > 0)
        {
            // stack 맨 위에 있다 = (현재 타워보다 더 큰 타워들 중에서) 현재타워랑 가장 가까이에 있다 = 수신
            targetTowerIndex = touchableTowers.top().index;
        }
        
        curTower.setTargetTowerIndex(targetTowerIndex);
        touchableTowers.push(curTower);
    }
}

int main() {
    int n;//탑의 개수
    cin >> n;

    vector<Tower> towers;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        towers.push_back(Tower(i+1, h));//탑의 인덱스는 1부터 시작함
    }
    
    findTargetTowers(towers);// 수신 타워 찾기

    for (int i = 0; i < n; i++)// 수신 타워 인덱스 출력
    {
        if (i > 0) cout << " ";
        
        Tower t = towers[i];
        int targetIndex = t.getTargetTowerIndex();
        cout << targetIndex;
    }
}