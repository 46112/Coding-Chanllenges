#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/*
<행사>
i번째 참가자 집의 위치 = (Xi, Yi)
행사장 위치 = (X, Y)

i번째 참가자가 행사장까지 이동하는 거리 
= 맨하튼 거리 
= |X - Xi| + |Y - Yi|

이동거리의 합이 최소가 되는 행사장 위치를 구하자

- 행사장 위치는 참가자 집 위치와 같을 수도 있다
- 참가자들이 같은 집에서 살 수도 있다
- 좌표는 0또는 양의 정수이다
- 정답이 되는 좌표가 여러개일 경우 아무거나 출력해도 된다

절댓값이라는 것은 좌표상 떨어져있는 거리이다
x의 계수가 모두 동일하다면, 중앙에서 가장 최소값이 형성된다
예를 들어 1,5,70,71,73이라고 한다면
y = |x-1| + |x-5| + |x-70| + |x-71| + |x-73|의 그래프를 그려보았을 때, 70에서 가장 작은 수를 갖는 것을 확인할 수 있다

그냥 단순하게 생각해도 1이하의 수부터 73이상의 수까지 전개해보았을 때
y값이 5씩 줄어듬 -> (1이상 진입) 3씩 줄어듬 -> (5이상 진입) 1씩 줄어듬
-> (70이상 진입) 1씩 늘어남 -> 3씩 늘어남 -> 5씩 늘어남

y값이 작아지다가 커지는 구간에 최소값이 존재한다

*/

class Participant {// 참가자 번호, 참가자 집의 X좌표, 참가자 집의 Y좌표
public:
    int index;
    int x;
    int y;

    Participant(int index, int x, int y) {
        this->index = index;
        this->x = x;
        this->y = y;
    }
};

void printBestLocation(const vector<Participant>& participants)
{
    vector<int> Xs, Ys;// X좌표들, Y좌표들만 따로 모아둠

    for (auto &p : participants)
    {
        Xs.push_back(p.x);
        Ys.push_back(p.y);
    }

    // 좌표 정렬 - 중앙값을 찾기 위해서
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());

    // 개수가 홀수개일 때는 최소값이 한곳에서만 나오고,
    // 짝수개일 때는 구간으로 나온다 - 짝수개일 때 size / 2를 하면 구간의 마지막 인덱스가 나오므로, 최소값을 만족한다
    int median_idx = participants.size() / 2;

    cout << Xs[median_idx] << " " << Ys[median_idx] << endl;
    cout << endl;
}

int main()
{
    int n;// 참가자 수
    cin >> n;

    vector<Participant> participants;// 참가자들의 집 좌표
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        participants.push_back(Participant(i, x, y));
    }

    clock_t start = clock();// 시간 측정 시작
    printBestLocation(participants);
    clock_t end = clock();// 시간 측정 끝

    cout << "실행시간: " << double(end - start) / CLOCKS_PER_SEC << "초" << endl;
    return 0;
}
