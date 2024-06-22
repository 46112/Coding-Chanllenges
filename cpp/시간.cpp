#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
<시간>
공대생 - 인문대생 1:1 약속잡음
대기시간 = |약속시간(A) - 도착시간(B) + 약속조정시간(T)|
공대생들이 인문대생들을 최대한 덜 기다리게 하는 T값의 개수를 구해라
공대생들은 T값을 공유한다

a-b는 결국 상수
공대생 수가 홀수일 때는 절대값 그래프가 가운데 한 점에서 최소가 된다
공대생 수가 짝수일 때는 절대값 그래프가 가운데 구간에서 최소가 된다

|t+1| -> t = -1일 때 최소
|t-1| + |t+3| -> t = [-3, 1]일 때 최소
|t-3| + |t+5| + |t-4| -> t = 3일 때 최소

*/

void printTCount(int N)
{
    vector<int> appointment_times(N);
    vector<int> arrival_times(N);

    for (int i = 0; i < N; i++)// A, B값들 입력받음
    {
        cin >> appointment_times[i] >> arrival_times[i];
    }

    time_t start, finish;
    double duration;
    start = time(NULL);// 시간 측정 시작 - 초 단위 출력을 위해 time사용
    
    vector<int> t_sections(N);// 식이 0이되게 하는 t들 
    for (int i = 0; i < N; i++)
    {
        t_sections[i] = arrival_times[i] - appointment_times[i];// t + a-b에서 t=(b-a)가 되어야 0이 된다
    }

    sort(t_sections.begin(), t_sections.end());// N은 최대 50이므로 정렬에 큰 리소스는 소요되지 않는다. 또한 정렬이 되어야 가운데 구간을 얻기 쉬워진다.

    int count = 0;
    if (N % 2 == 0)// N이 짝수일 때 0 ~ N-1 중에서 가운데 인덱스는 [N/2-1, N/2]이다
    {
        int s_index = N/2 - 1;
        int begin = t_sections[s_index];
        int end = t_sections[s_index + 1];
        if (begin == end) count = 1;// 가운데의 b-a값이 동일한 경우 ex) 10 11과 13 14
        else count = end - begin + 1;
    } else {// N이 홀수일 때 0 ~ N-1 중에서 가운데 인덱스는 (N-1)/2이다
        count = 1;
    }
    cout << count << endl;

    finish = time(NULL);// 시간 측정 끝
    duration = (double) (finish - start);
    cout << "실행시간: " << duration << "초" << endl;
}

int main() 
{
    int N;
    cin >> N;
    printTCount(N);// 가장 덜 기다리게 하는 케이스 t의 개수 출력
    return 0;
}