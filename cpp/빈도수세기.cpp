#include <cstdio>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

/*
<빈도수 세기>
입력으로 들어온 수를 다음 형식으로 처리해서 출력한다
현재까지 입력된 숫자의 종류의 수, 이번에 등장한 수가 지금까지 나온 횟수

*/

int main() {
    int N;
    scanf("%d", &N);// 입력으로 주어질 수를 구함

    map<int, int> frequencyMap;// 수(int)가 등장한 횟수(int)

    for (int i = 0; i < N; i++) {
        int X;// 이번에 입력될 수
        scanf("%d", &X);
        frequencyMap[X]++;// 기본값은 0으로 초기화되고 1을 더해 1이 될것이고, 기존에 나온적이 있어 map의 key값이 존재한다면 해당 값을 1더한다
        printf("%d %d\n", frequencyMap.size(), frequencyMap[X]);// map의 size는 key의 개수, key에 대응되는 value값은 해당 수가 나온 횟수를 의미한다
    }
}