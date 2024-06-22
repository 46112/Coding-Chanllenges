#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

/*

<데스티니>
Point2D 객체는 필드값으로 좌표 x, y를 갖고. 다른 Point2D 객체 간의 
거리를 구하는 메서드를 갖는다. getSquaredDistanceTo에서 (x1-x2)^2 + (y1-y2)^2를 구한다
이이 대한 제곱근이 두 좌표간의 거리이다.

이중 반복문을 돌려가며 최소값을 구해준다.

*/

class Point2D {
    // private 필드값은 좌표 정보를 갖고 있음
private:
    int x;
    int y;

public:
    Point2D(int x = 0, int y = 0) {//생성자
        this -> x = x;
        this -> y = y;
    }
// 두 객체 간의 거리를 구하기 위해 둘 좌표의 제곱의 합을 구하는 함수
    int getSquaredDistanceTo(const Point2D &target) const {
        int x_diff = this->x - target.x;
        int y_diff = this->y - target.y;

        return pow(x_diff, 2) + pow(y_diff, 2);
    }
// getSquaredDistanceTo를 호출하여 제곱의 합을 구한 뒤, 루트를 씌워 둘 사이의 거리를 구하는 함수
    double getDistanceTo(const Point2D &target) const {
        double sqd = (double) this -> getSquaredDistanceTo(target);
        return sqrt(sqd);
    }
};


int main()  // 입력값 받아 검증
{
    int n;
    Point2D *points;

    scanf("%d", &n);
    points = new Point2D[n];

// 입력받은 데이터를 이용해서 좌표 객체들을 생성
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        points[i] = Point2D(x, y);
    }

// 원활한 대소관계 비교를 위해 변수 초기화시에 int형 최대값으로 선언
    int min_sqd = INT_MAX;
    int min_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int sqd = points[i].getSquaredDistanceTo(points[j]);// 거리구하기
            if (sqd < min_sqd) {// 최소값과 비교해서 새로 도출한 값이 최소일 때
                min_sqd = sqd; // 최소값을 갱신하고
                min_cnt = 1; // 최소값인 경우는 이제 막 갱신되었으므로 한 개이다
            } else if (sqd == min_sqd) {// 최소값과 동일할 때는
                min_cnt++;// cnt를 늘려간다
            }
        }
    }

    double distance = sqrt(min_sqd);
    printf("%.1f\n", distance);
    printf("%d\n", min_cnt);

    delete[] points;
    return 0;
}
