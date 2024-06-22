#include <cstdio>
#include <iostream>

using namespace std;

/*

<버블정렬>
버블 정렬은 마치 거품이 올라오는 것처럼 최소 혹은 최대값이 점점 올라오는 정렬입니다
앞 뒤로 비교해가며 더 큰 것 혹은 더 작은 것을 앞으로 뒤로 보내므로 한번 반복될 때마다 
어느 정도 전체적으로 정렬이 되는 효과가 있습니다.
이 경우 오름차순 정렬로 맨 마지막부터 자리가 확정됩니다.

*/

void bubbleSort(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // 배열의 index는 0부터 n-1까지이므로 j가 n-1이 되는 것을 허용하면 j+1이 n으로 배열 인덱스 범위를 벗어난다.
        for (int j = 0; j < n-1-i; j++) {
            if (data[j] > data[j+1])
            {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}


int main()  // 입력값 받아 검증
{
    int n;
    int* data;

    scanf("%d", &n);
    data = new int[n];

// 초기 배열 설정
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n);

// 정렬 후 배열 찍어 확인하기
    for (int i = 0; i < n; i++) {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", data[i]);
    }

    delete[] data;
    return 0;
}
