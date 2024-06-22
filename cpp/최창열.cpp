#include <cstdio>
#include <iostream>

using namespace std;

/*

<문제해결프로젝트 프로젝트 1>
시침은 12시간에 1바퀴, 분침은 1시간에 1바퀴
따라서 둘의 이동거리 차이는 12배이다.

또한 12시가 되면, 둘은 0도에서 마주한다.
즉, 06시와 18시, 다음날 06시 모두 시계 모양의 차이는 존재하지 않는다.
예시 입력처럼 시침이 180도만큼 이동했을 경우, 06시라고 가정해도 아무런 문제가 없다.

시침이 180도만큼 이동했을 때, 분침은 180*12인 2160도만큼 이동해야한다.
시계의 침은 360도를 주기로 원래 자리로 돌아온다.
따라서 2160은 360으로 나누어 떨어지므로 0도 자리에 존재해야한다.
예시로 주어진 분침은 각도가 0이므로 시계는 고장나지 않았다.

*/

bool isOperating(int hourHand, int minuteHand)
{
    if ((hourHand * 12) % 360 == minuteHand)
        return true; // 시침의 12배만큼 이동한 각도에 분침이 존재해야한다.

    return false;
}


int main()  // 입력값 받아 검증
{
    int hourHand, minuteHand;
    scanf("%d %d", &hourHand, &minuteHand);
    
    if (isOperating(hourHand, minuteHand))
        printf("O");
    else
        printf("X");
    
    return 0;
}
