#include <cstdio>
#include <iostream>

using namespace std;

/*

<오름차순인가?>
오름차순으로 정렬되었는가 판별

*/

bool isOrdered(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (data[i-1] > data[i]) // 앞에 친구가 더 키가 크면 오름차순 정렬되지 않았다.
        {
            return false;
        }
    }
    return true;
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

    bool result = isOrdered(data, n);

    if (result)
    {
        printf("YES");
    }
    else{
        printf("NO");
    }

    delete[] data;
    return 0;
}
