#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
<두 직사각형>


*/

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb)
{
    /*
    직사각형이 겹칠 때 높이는 상대적으로 아래쪽에 위치한 직사각형의 위쪽 y좌표에서 
    상대적으로 위쪽에 위치한 직사각형의 아래쪽 y좌표를 뺀 값이다.

    마찬가지로 너비는 상대적으로 왼쪽에 위치한 직사각형의 오른쪽 x좌표에서 
    상대적으로 오른쪽에 위치한 직사각형의 왼쪽 x좌표를 뺀 값이다.
    */
    int height = min(ta, tb) - max(ba, bb);
    int width = min(ra, rb) - max(la, lb);

    if (height <= 0 || width <= 0) return 0;// 높이나 너비가 0이면 겹치지 않는다
    return height * width;
}

void test_case()
{
    int ax, ay, bx, by;// 첫번째 직사각형 대각선 두 점 좌표
    int px, py, qx, qy;// 두번째 직사각형 대각선 두 점 좌표
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    int la, ra, ba, ta;
    la = min(ax, bx);// 첫번째 직사각형 가장 왼쪽에 있는 x좌표
    ra = max(ax, bx);// 첫번째 직사각형 가장 오른쪽에 있는 x좌표
    ta = max(ay, by);// 첫번째 직사각형 가장 위쪽에 있는 y좌표
    ba = min(ay, by);// 첫번째 직사각형 가장 아래쪽에 있는 y좌표

    int lb, rb, bb, tb;
    lb = min(px, qx);// 두번째 직사각형 가장 왼쪽에 있는 x좌표
    rb = max(px, qx);// 두번째 직사각형 가장 오른쪽에 있는 x좌표
    tb = max(py, qy);// 두번째 직사각형 가장 위쪽에 있는 y좌표
    bb = min(py, qy);// 두번째 직사각형 가장 아래쪽에 있는 y좌표

    int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

    printf("%d\n", answer);
}

int main()  // 입력값 받아 검증
{
    int t;// t번 테스트 진행
    scanf("%d", &t);

    for (int i = 0; i < t; i++) test_case();

    return 0;
}