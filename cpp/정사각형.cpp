#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

/*
<정사각형>
N개의 좌표가 주어짐
이 중 4개를 골라 만들 수 있는 정사각형 중 가장 큰 넓이를 구하는 프로그램

*/

class Point2D {// 좌표 구조체
public:
    int x;
    int y;
    int index;

    Point2D(int index, int x, int y) {
        this->index = index;
        this->x = x;
        this->y = y;
    }

    Point2D(int x, int y) {// 인덱스가 주어지지 않았을 때의 생성자
        this->index = 1;
        this->x = x;
        this->y = y;
    }

    long long getSquaredDistanceTo(Point2D target) {// 두 좌표 간의 거리의 제곱 = 정사각형의 경우 넓이가 된다
        long long dx = abs(this->x - target.x);
        long long dy = abs(this->y - target.y);
        return dx * dx + dy * dy;
    }

    double getDistanceTo(Point2D target) {
        long long sqd = this->getSquaredDistanceTo(target);// 제곱에 제곱근을 씌워 두 좌표 간의 거리를 구한다
        return sqrt(sqd);
    }

    bool operator < (const Point2D& other) const {// 구조체 비교 연산 - x값을 통해 비교하고 동일할 경우 y값을 통해 비교한다
        if (this->x != other.x)
        {
            return this->x < other.x;
        }
        return this->y < other.y;
    }
};

long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0;

    set<Point2D> pSet;
    for (int i = 0; i < n; i++) {
        pSet.insert(points[i]);// set에 좌표값들을 입력함 - 빠른 탐색과 좌표값 중복 제거 가능
    }
    
    for (int i = 0; i < n; i++) {
        Point2D pa = points[i];
        for (int j = 0; j < n; j++) {// 이중 for문을 통해 각 좌표값들의 조합을 전부 탐색할 수 있음 - n이 500이하의 자연수이므로 이중 for문을 사용해도 시간 복잡도가 높지 않다
            Point2D pb = points[j];

            long long area = pa.getSquaredDistanceTo(pb);
            if (area <= answer) continue;// pa와 pb를 한 변으로 하는 정사각형을 구해보고, 그 넓이가 최댓값이 아닐 경우 애초에 아래 검증 절차를 거칠 필요가 없음
            
            int dx = pb.x - pa.x;// 이 경우 dx와 dy를 양수로 가정하고 그 아래의 좌표들이 존재하는지 탐색함
            int dy = pb.y - pa.y;// dx와 dy가 음수인 경우에도 결국 모든 pa와 pb의 조합을 살펴보고, 일관성있게 검증 좌표를 설정하므로, 문제가 없음

            Point2D under_pa = Point2D(pa.x + dy, pa.y - dx);
            Point2D under_pb = Point2D(pa.x + dy, pa.y - dx);
            if(pSet.find(under_pa) != pSet.end() && pSet.find(under_pb) != pSet.end()) {// set에 존재하다는 것은 좌표가 주어졌다는 것이고, 이는 정사각형을 만들 수 있다는 의미
                answer = area;// 애초에 이 부분까지 온 케이스는 area > answer이므로 바로 answer을 교체함
            }
        }
    }
    return answer;
}

void process(int caseIndex) {
    int n;// 각 테스트 케이스는 n개의 좌표를 갖는다 
    cin >> n;

    vector<Point2D> points;

    for (int i = 0; i < n; i++) {// 좌표값 입력 받음
        int x, y;
        cin >> x >> y;
        points.push_back(Point2D(x, y));
    }

    long long answer = getMaximumSquareArea(n, points);// 최대 넓이를 구해서

    cout << fixed << setprecision(2) << answer << endl;// 출력
}

int main() {
    int caseSize;// 테스트 케이스 개수
    cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
        process(caseIndex);
    }
}