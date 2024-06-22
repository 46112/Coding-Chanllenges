#include <cstdio>
#include <iostream>

using namespace std;

/*

<정주행>
읽은 만화의 회차가 중간의 빠짐없이 연속적인 수열인지 판별하는 문제이다
예를 들어 2 3 4 5 6 7와 같은 경우는 연속된 회차라고 볼 수 있지만, 
1 3 4 5 6 7 와 같은 경우는 연속된 회차라고 볼 수 없다

총 읽은 회차 n이 주어지기 때문에 주어진 에피소드 번호 리스트에서 최대값과 최소값을 찾아내어 
max - min + 1 = n인지 판별하면 된다
연속적인 수열이라면 min <= x <= max 사이의 가능한 정수의 개수는 max-min+1이기 때문이다

*/

bool isConsecutive(int data[], int n) {
    int max_data = data[0];
    int min_data = data[0];

    // data[0]으로 초기화했으므로 1부터 시작
    for (int i = 1; i < n; i++)
    {
        // 최대값 찾기
        if (max_data < data[i]) max_data = data[i];
        
        // 최소값 찾기
        if (min_data > data[i]) min_data = data[i];
    }
    
    // 연속된 수열 검증
    if (max_data - min_data + 1 == n) return true;
    else return false;
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
    
    bool result = isConsecutive(data, n);

    if (result) printf("YES");
    else printf("NO");
    
    delete[] data;
    return 0;
}
