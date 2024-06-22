#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

/*

<다양성>
가지고 있는 트와이스 앨범 종류 몇종류인지 파악
앨범 번호는 오름차순 정렬되어 있음

*/

int getElementTypeCount(int data[], int n)
{
    set<int> albumType; // set을 사용해 정렬되지 않은 경우에도 종류를 파악할 수 있도록 했습니다.
    for (int i = 0; i < n; i++)
    {
        albumType.insert(data[i]);
    }
    
    int typeCount = albumType.size();
    return typeCount;
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

    int answer = getElementTypeCount(data, n);

    printf("%d\n", answer);

    delete[] data;
    return 0;
}
