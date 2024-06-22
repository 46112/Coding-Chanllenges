#include <cstdio>
#include <iostream>

using namespace std;

/*

<도토리 키재기>
매 달 생일 해당 달이 생일인 도토리들 중 키가 가장 큰 도토리 키 출력

*/

int getMaximumHeight(int height[], int month[], int n, int m)
{
    for (int i = n-1; i >= 0; i--)
    {
        if(month[i] == m)
        {
            return height[i];
        }
    }
    return -1;
}

int main()  // 입력값 받아 검증
{
    int n, m;
    int* height;
    int* month;

    scanf("%d", &n);
    height = new int[n];
    month = new int[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &month[i]);
    }
    
    scanf("%d", &m);

    int answer = getMaximumHeight(height, month, n, m);

    printf("%d\n", answer);

    delete[] height;
    delete[] month;
    return 0;
}
