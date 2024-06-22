#include <stdio.h>
#include <iostream>

using namespace std;

/*

n개의 정수로 이루어진 배열에서 m값의 위치(인덱스)를 구하는 프로그램
만약 찾지 못했다면 -1을 출력

*/

// n번만큼 순회하면서 인덱스를 찾으면 빠져나온다.
int findIndex(int data[], int n, int m)
{
    for (int idx = 0; idx < n; idx++)
    {
        if (data[idx] == m)
        {
            return idx;
        }
    }
    
    return -1; // for문을 다 돌고 난 후 값을 찾지 못했다면 -1 출력
}

int main()  // 입력값 받아 검증
{
    int n, m;
    int *data;

    scanf("%d %d", &n, &m);
    data = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }
    
    int answer = findIndex(data, n, m);
    printf("%d\n", answer);
    delete[] data;
    return 0;
}
