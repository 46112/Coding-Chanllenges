#include <cstdio>
#include <iostream>

using namespace std;

/*

<픽셀수세기>
제 1사분면 안에 들어가는 픽셀 수의 4배가 정답이 된다
x의 제곱 더하기 y의 제곱이 R의 제곱보다 작으면 원 내부에 존재하는 좌표이다.
원가 겹치는 영역이 존재하면서 두개 이상의 변이 원의 외곽선과 교차하여도 원에 포함되는 픽셀로 취급한다.
따라서 y+1이 해당 x축의 픽셀 값이 된다.

*/

// 원 내부에 존재하는지 판별
bool isInside(long long x, long long y, long long R)
{
    if (x * x + y * y < R * R) return true;
    else return false;
}

void testcase(int caseIndex) {
    long long R;
    scanf("%lld", &R);

    long long sum = 0;
    long long y = R; // 원의 특성상 1사분면 내에서 height는 점점 내려갈 수 밖에 없으므로 for문 밖에서 선언해준다.
    for (long x = 0; x <= R; x++)
    {
        long long height = 0;
        for(; y >= 0; y--)
        {
            // 안에 존재하는 최대 y를 확인하면 height를 알 수 있으므로 break으로 빠져나간 뒤 처음의 for문을 돌려 다음 x값의 경우를 확인한다
            if (isInside(x, y, R)){
                height = y + 1;
                break;
            }
        }
        sum += height;
    }
    
    printf("#%d\n", caseIndex);
    printf("%lld\n", sum * 4);
}

int main()  // 입력값 받아 검증
{
    int caseSize; // 테스트 케이스의 수
    scanf("%d", &caseSize);

    // #1와 같이 1부터 시작하기 위해 caseIndex를 1부터 시작시켰다
    for (int caseIndex = 1; caseIndex < caseSize + 1; caseIndex += 1)
    {
        testcase(caseIndex);
    }
    return 0;
}
