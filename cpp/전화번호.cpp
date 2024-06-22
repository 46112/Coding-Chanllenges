#include <cstdio>
#include <iostream>

using namespace std;
const int MAX_TABLE_LENGTH = 10000;

/*

<전화번호>
0000 ~ 9999 총 1만가지의 뒷자리 조합중에서 사람들이 가장 많이 사용하는 뒷자리 조합을 찾아라.
10000크기의 배열을 선언했을 때, 배열의 인덱스를 뒷자리로 간주할 수 있음 (0~9999)

*/

void fillFrequencyTable(int data[], int n, int table[]) {
    for (int i = 0; i < MAX_TABLE_LENGTH; i++) // 빈도수 카운트 테이블 0으로 초기화
    {
        table[i] = 0;
    }
    
    int temp = 0;
    for (int i = 0; i < n; i++) // data[i]는 1357와 같이 전화번호 끝 4자리를 의미한다. 따라서 table[data[i]]으로 해당 전화번호의 빈도수를 나타낼 수 있다.
    {
        temp = data[i];
        table[temp] += 1;
    }
}

int getFrequentNumber(int data[], int n) {
    // 빈도수 테이블을 선언하고, fillFrequencyTable함수를 통해 안의 빈도수 count를 채워준다.
    int *frequency_table = new int[MAX_TABLE_LENGTH];
    fillFrequencyTable(data, n, frequency_table);

    // frequent_number는 가장 많이 등장한 번호, max_frequency는 가장 많이 등장한 번호가 얼마나 많이 등장했는지를 나타낸다.
    int frequent_number = 0;
    int max_frequency = -1;
    for (int i = 0; i < MAX_TABLE_LENGTH; i++)
    {
        if (max_frequency < frequency_table[i]) // 최대 빈도수와 같을 때는 그 역시 가장 많이 등장한 번호 중에서 하나이지만, 사전순으로 빠른 숫자를 출력하라고 지시했으므로, 고려하지 않는다.
        {
            frequent_number = i;
            max_frequency = frequency_table[i];
        }
    }
    
    return frequent_number;
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
    // getFrequentNumber는 가장 빈도수가 많은 전화번호 뒷자리를 반환한다.
    int answer = getFrequentNumber(data, n);

    // 이를 4자리 정수로 출력한다.
    printf("%04d", answer);
    
    delete[] data;
    return 0;
}
