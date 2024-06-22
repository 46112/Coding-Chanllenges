#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

/*

<응모>
팬사인회 응모, 사람들은 각자의 시리얼 넘버를 가지고 응모를 해야한다.
그런데 중복 응모를 한 사람들이 존재함 -> 중복 응모한 사람들은 전부 탈락
중복 아닌 사람들로만 구성해서 오름차순 정렬한 리스트를 반환해라.

*/

void fillFrequencyTable(const vector<int> &data, int n, vector<int> &table) {
    // vector 테이블 내의 내용을 전부 지우고, 크기를 100001로 재구성한 다음, 0으로 초기화한다.
    // 실제로 사용되는 크기는 십만이지만, 인덱스에 의미를 부여하기 위해 100001만큼 사이즈 재설정
    table.clear();
    table.resize(MAX_SERIAL_NUMBER + 1, 0);

    // data[i]는 사람들이 응모한 시리얼 넘버를 의미한다
    // table[serial_number]는 해당 시리얼 넘버의 빈도수를 의미한다
    for (int i = 0; i < n; i++)
    {
        int serial_number = data[i];
        table[serial_number] += 1;
    }
}

vector<int> getUniqueElements(const vector<int> &data, int n) {
    vector<int> ret;

    // 시리얼 넘버별 빈도수 테이블 설정
    vector<int> serial_number_frequency_table;
    fillFrequencyTable(data, n, serial_number_frequency_table);

    // 실제 의미가 있는 인덱스는 시리얼 넘버의 범위인 1부터 10만까지이다
    for (int i = 1; i <= MAX_SERIAL_NUMBER; i++)
    {
        // 1부터 확인하다가 딱 1번만 응모한 번호가 있으면
        if (serial_number_frequency_table[i] == 1)
        {
            // ret 벡터에 집어넣는다
            ret.push_back(i);
        }
    }
    
    // 1부터 확인하며 집어넣었으므로 오름차순 정렬은 이미 돼있다.
    return ret;
}

int main()  // 입력값 받아 검증
{
    int n;
    scanf("%d", &n);

    // 사람들이 응모한 시리얼 넘버 데이터
    vector<int> data = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data[i]);
    }

    // answer는 중복 응모한 시리얼 넘버를 제거하고 오름차순 정렬된 데이터
    const vector<int> answer = getUniqueElements(data, n);
    
    // answer 내용물 출력
    for (int i = 0; i < answer.size(); i++)
    {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", answer[i]);
    }
    
    return 0;
}
