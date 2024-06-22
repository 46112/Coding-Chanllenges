#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*

<선택정렬>
0~n-1를 순회하며 최소/최대값을 찾아 0번째를 확정한다.
1~n-1를 순회하며 최소/최대값을 찾아 1번째를 확정한다.
...

*/

// 오름차순 정렬이므로 최소값을 찾아낸다.
int getMinIndexInRange(int data[], int n, int begin)
{
    if (begin >= n-1) return begin;
    
    int min_value = data[begin];
    int min_index = begin;
    
    for (int i = begin+1; i < n; i++)
    {
        if (min_value > data[i])
        {
            min_value = data[i];
            min_index = i;
        }
    }
    
    return min_index;
}

void selectionSort(int data[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_index = getMinIndexInRange(data, n, i);
        // switch
        int temp = data[min_index];
        data[min_index] = data[i];
        data[i] = temp;
    }
}

int main()  // 입력값 받아 검증
{
    int n;
    int* data;

    scanf("%d", &n);
    data = new int[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    selectionSort(data, n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", data[i]);
    }
    
    delete[] data;
    return 0;
}
