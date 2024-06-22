#include <cstdio>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

/*
<시장 추천하기>
해당 시의 모든 시민들은 잠정적인 시장 후보
모든 유권자들은 시장을 한 사람 뽑을 수 있음
가장 많은 표를 획득한 사람들을 출력하는 문제

*/

int main() {
    int N;
    cin >> N;// N명의 유권자 - N개의 투표용지

    map<string, int> frequencyMap;// 개표 현황

    int maxFrequency = 0;// 최다 득표수

    for (int i = 0; i < N; i++) {
        string st;// 투표용지에 적힌 후보자 이름
        cin >> st;
        frequencyMap[st]++;// 개표 현황 업데이트

        int k = frequencyMap[st];
        if (k > maxFrequency) {// 최다 득표수 업데이트
            maxFrequency = k;
        }
    }

    cout << maxFrequency << endl;

    map<string, int>::iterator it;
    for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
        if (it -> second == maxFrequency) {// value값, 즉 후보자 별 득표수를 비교해서 최다 득표 수와 같은(시장으로 선출된) 사람의
            printf("%s ", it -> first.c_str());// key값, 후보자 이름을 구한다
        }
    }
}