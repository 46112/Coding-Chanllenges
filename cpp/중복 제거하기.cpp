#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
<중복 제거하기>
입력들이 주어지고, 각 입력들을 판별하는 프로그램
이미 앞서 등장한 숫자의 경우 'DUPLICATED' 출력
처음 등장한 숫자는 'OK' 출력

*/

int main()
{
    int N;// N개의 입력
    cin >> N;

    set<int> integers;
    for (int i = 0; i < N; i++)
    {
        int X;// 각 입력 값
        cin >> X;

        set<int>::iterator iter;
        iter = integers.find(X);// X값이 set에서 찾을 수 없으면 end 이터레이터 반환, 찾을 수 있으면 해당 이터레이터 반환
        if (iter != integers.end())
        {
            cout << "DUPLICATED" << endl;// set에 있으면 중복되었음을 알려줌
        } else {// set에 없으면 set에 추가하고, OK출력
            integers.insert(X);
            cout << "OK" << endl;
        }
    }
}