#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*

<탐색하기 3>
n개의 데이터의 평균값을 구하고, 그 평균값에 가장 가까운 수의 번호와 값을 출력해야한다.
번호는 index값 + 1이다, 즉 1부터 n까지 부여된다.
만약 평균치에 가장 가까운 수가 2개 이상이면 번호가 앞선 수를 우선으로 한다.

*/

// 평균을 구하는 함수
double average(int data[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
    {
        sum += data[i];
    }

    return sum / size;
}

int findIndex(int data[], int n)
{
    double avg = average(data, n);

    // 첫번째 배열값을 이용해 초기값 세팅
    int index = 0;
    double min_diff = abs(avg - data[0]);

    // 두번째 배열값부터 순회
    for (int i = 1; i < n; i++)
    {
        double diff = abs(avg - data[i]);
        if (min_diff > diff) // 두 수의 차가 최소가 될 때 구하려는 index가 업데이트된다.
        {
            index = i;
            min_diff = diff;
        }
    }
    
    return index;
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

    int answer = findIndex(data, n);
    int value = data[answer];
    printf("%d %d\n", ++answer, value);
    
    delete[] data;
    return 0;
}
