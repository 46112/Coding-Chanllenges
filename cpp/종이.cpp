#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

/*

<종이>
직사각형 종이가 있었는데, 종이가 정확히 반으로 갈라져 직각 삼각형 2개가 되었다.
이 직각 삼각형에서 사용할 수 있는 정사각형(1X1)의 개수를 구해라
-> 2차원 좌표에 두어서 방정식으로 해결해보자

|
|____  y = (H/W) * x
|   /|
|  / |
| /  |
|/___|__________

*/

int findSquaresInTriangle(int w, int h) { // 직각삼각형 내에 존재하는 정사각형의 개수를 구하는 함수
    // 만약 맨 위의 그림처럼 직사각형을 반으로 나누는 대각선을 방정식으로 표현한다면 y=(H/W)x가 될 수 있을 것이다
    // 이 경우 정사각형을 만들때 만들어 질 수 있는 정사각형의 개수는 왼쪽에 의존적이다(기울기가 양수이므로 왼쪽이 더 작기 때문)
    // 따라서 1일 때의 높이의 정수(y값을 버림해서 만들 수 있다) + 2일때 높이 + ... + w-1일때 높이까지가 정답이 된다
    // (왼쪽의 높이가 0일때는 기울기가 아무리 높아도 정사각형을 만들 수 없다)

    if (w <= 1 || h <= 1) return 0; // 두 변중 하나라도 1이 되는 순간, 반으로 잘랐을 때 건질 수 있는 정사각형은 존재하지 않는다
    
    int numbers_of_sqaure = 0;
    for (int left = 1; left < w; left++)
    {
        double y = (h * left) / w;
        int left_height = (int) y;
        numbers_of_sqaure += left_height;
    }

    return numbers_of_sqaure;
}

int main()  // 입력값 받아 검증
{
    int W, H;
    cin >> W;
    cin >> H;

    time_t start, finish;
    double duration;
    start = time(NULL);//시간 측정 시작 - 초 단위 출력을 위해 time사용

    int half = findSquaresInTriangle(W, H);
    int numbers_of_sqaure = half * 2;

    finish = time(NULL);// 시간 측정 끝
    duration = (double) (finish - start);

    cout << numbers_of_sqaure << endl;
    cout << "실행시간: " << duration << "초" << endl;
    return 0;
}