#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
<직사각형>
1번 ~ N번 사각형이 주어짐
x축 위에 나란히 사각형을 배치할 것
기본적으로 번호순으로 배치
윗둘레가 가장 긴 경우가 되도록 사각형을 돌려가며 배치

기본적으로 번호의 순서는 정해져있으므로 해당 도형에 대해서 눕히거나, 세우거나 두가지 조치를 취할 수 있다

*/


void printLongestUpperPerimeter(int N)
{
    vector<int> short_sides(N);
    vector<int> long_sides(N);

    for (int i = 0; i < N; i++) // N개의 직사각형들의 짧은 변, 긴 변들을 입력받음
    {
        cin >> short_sides[i] >> long_sides[i];
    }

    time_t start, finish;
    double duration;
    start = time(NULL); // 시간 측정 시작

    if (N == 1)// 직사각형이 1개면 맨 윗쪽 선분만 고려하기 때문에 무조건 눕혀야 한다
    {
        cout << long_sides[0] << endl;
        finish = time(NULL);// 시간 측정 끝
        duration = (double) (finish - start);
        cout << "실행시간: " << duration << "초" << endl;
        return;
    }
    

    int total_length = 0;// 윗둘레
    int current_height = 0;// 현재 도형의 높이
    vector<bool> isLaying(N); // 해당 인덱스의 도형이 누워있는지 확인
    int index = 0;
    while (index < N)
    {
        if (index == 0)
        {
            total_length += long_sides[index];// 첫번째 직사각형을 눕혔을 때
            current_height = short_sides[index];
            isLaying[index] = true;
            index++;
            continue;
        }
        
        int case_erect = abs(long_sides[index] - current_height) + short_sides[index];//해당 직사각형을 세웠을 때 윗둘레 증감값
        int case_lay_down = abs(current_height - short_sides[index]) + long_sides[index];//해당 직사각형을 눕혔을 때 윗둘레 증감값

        if (case_erect > case_lay_down)// 해당 직사각형을 세웠을 때 이득이면 세운다
        {
            total_length += case_erect;
            current_height = long_sides[index];
            isLaying[index] = false;
        } else if(case_erect < case_lay_down) {// 해당 직사각형을 눕혔을 때 이득이면 눕힌다
            total_length += case_lay_down;
            current_height = short_sides[index];
            isLaying[index] = true;
        } else {// 두 케이스 증감값이 동일할 경우에는 앞선 케이스를 고려해 앞선 케이스가 서있으면 눕히고, 누워있으면 세운다
            if (isLaying[index - 1])
            {
                total_length += case_erect;
                current_height = long_sides[index];
                isLaying[index] = false;
            } else {
                total_length += case_lay_down;
                current_height = short_sides[index];
                isLaying[index] = true;
            }
        }
        index++;
    }
    cout << total_length << endl;

    finish = time(NULL);// 시간 측정 끝
    duration = (double) (finish - start);
    cout << "실행시간: " << duration << "초" << endl;
}

int main()
{
    int N;
    cin >> N; // 몇 개의 직사각형이 주어졌는지 입력받음
    printLongestUpperPerimeter(N); // 가장 긴 윗둘레 케이스 출력
    return 0;
}
