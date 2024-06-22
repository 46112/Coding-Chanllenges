#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
<불안정 지역>
왼쪽부터 오른쪽까지 N개의 도시들이 차례로 위치해있음
각 도시들은 0부터 N-1까지 번호를 부여받음
지역적으로 이웃한 도시들 K개를 묶었을 때 최고소득 도시와 최저소득 도시간의 격차가 존재함
이 격차의 최대값을 구하는 문제

이중 for문을 이용해 문제를 해결하기에는 N이 20만까지로 너무 큼

*/

class City {
public:
    int index;
    int income;

    City(int index, int income) {
        this->index = index;
        this->income = income;
    }

    // operator을 재정의함으로서 City에 대한 대소비교는 income을 기준으로 이루어지게 됨
    bool operator < (const City& o) const {
        return this->income < o.income;
    }
    bool operator > (const City& o) const {
        return this->income > o.income;
    }
};

// 실질적으로 가장 큰 격차를 구하는 함수
int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
    int answer = 0;

    priority_queue<City, vector<City>, greater<City>> rangeMinimum;// 오름차순 저장 = top이 최저 소득 도시
    priority_queue<City> rangeMaximum;// 내림차순 저장 = top이 최다 소득 도시

    for (int i = 0; i < k-1; i++)
    {
        rangeMinimum.push(cities[i]);
        rangeMaximum.push(cities[i]);
    }
    
    for (int i = k-1; i < n; i++)
    {
        rangeMinimum.push(cities[i]);
        rangeMaximum.push(cities[i]);// 일단 k개의 도시를 집어넣고

        while(rangeMinimum.top().index < i-k+1) rangeMinimum.pop();// 그 안에서 최대, 최소값이 범위를 넘어가는 지 확인함 -> 큐 안에 k개 이상이 들어가도 상관 없음 -> 어차피 최대 최소 비교 전에 확인한 뒤 pop할 것이기 때문
        while(rangeMaximum.top().index < i-k+1) rangeMaximum.pop();// 앞에서부터 순서대로 k개 도시를 집어넣었으므로 앞부분의 index부터 빼준다

        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);// 큐를 이용해 최대 최소를 편하게 비교할 수 있다
    }

    return answer;
}

void process(int caseIndex) {
    int n, k;
    cin >> n >> k;
    vector<City> cities;

    for (int i = 0; i < n; i++)
    {
        int income;
        cin >> income;
        cities.push_back(City(i, income));// 각 도시별 소득을 입력받음
    }
    
    int answer = getMaximumRangeDifference(n, k, cities);

    cout << answer << endl;
}

int main() {
    int caseSize;// 테스트 케이스 개수
    cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
        process(caseIndex); // 각 테스트 케이스별로 실행
    }
}