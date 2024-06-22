#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

/*

<페인트>
N개의 좌석은 모두 0번색으로 칠해져있다.
페인트 색은 0번부터 99번색까지 총 100 종류이다.
불규칙적으로 좌석들을 색칠한 뒤, 가장 많은 좌석을 칠한 색과, 가장 적은 좌석을 칠한 색을 찾아라.
단, 다른 색으로 덮어씌워져 결과적으로 아무런 좌석도 칠해져있지 않은 색은 제외한다.

*/

class Painting{
public:
    int left;
    int right;
    int color;

    Painting() {}

    Painting(int left, int right, int color) {
        this -> left = left;
        this -> right = right;
        this -> color = color;
    }
};

void fillFrequencyTable(int data[], int n, int table[]) {
    for (int i = 0; i < MAX_COLOR_NUMBER; i++) // 빈도수 카운트 테이블 0으로 초기화
    {
        table[i] = 0;
    }
    
    int color = 0;
    for (int i = 0; i < n; i++) // data[i]는 해당 좌석의 색상을 의미한다. 따라서 table[data[i]]으로 해당 색상의 빈도수를 나타낼 수 있다.
    {
        color = data[i];
        table[color] += 1;
    }
}

void solve(int n, int m, const Painting* paintings)
{
    // n개의 모든 좌석들은 처음에 0번 색상으로 칠해져있다
    int* seats = new int[n];
    for (int i = 0; i < n; i++)
    {
        seats[i] = 0;
    }

    // painting정보들을 가져와서, 페인트칠을 한다.
    for (int i = 0; i < m; i++)
    {
        const Painting &p = paintings[i];
        for (int j = p.left; j <= p.right; j++)// left부터 right좌석까지 color색으로 칠해라
        {
            seats[j] = p.color;
        }
    }

    // color_frequency_table은 현재 각 색상이 얼마만큼 칠해져있는지 확인시켜준다
    int *color_frequency_table = new int[MAX_COLOR_NUMBER];
    fillFrequencyTable(seats, n, color_frequency_table);

    // 가장 번호가 적은 0번 색상으로 초기화
    int minColor = 0;
    int maxColor = 0;

    for (int color = 0; color < MAX_COLOR_NUMBER; color++)
    {
        // 아무런 좌석도 칠하지못한 색은 고려하지 않는다
        if (color_frequency_table[color] == 0) continue;
        
        // 현재 최소 좌석 색상보다 더 적게 칠해진 색상이 있으면 최소 좌석 색상을 교체한다
        if (color_frequency_table[minColor] > color_frequency_table[color]) minColor = color;
        
        // 현재 최대 좌석 색상보다 더 많이 칠해진 색상이 있으면 최대 좌석 색상을 교체한다
        if (color_frequency_table[maxColor] < color_frequency_table[color]) maxColor = color;
    }
    
    printf("%d\n", maxColor);
    printf("%d\n", minColor);

    delete[] seats;
}

int main()  // 입력값 받아 검증
{
    int n, m;
    scanf("%d %d", &n, &m);

    Painting* paintings = new Painting[m];

    // 불규칙적인 페인트칠은 총 M번 진행됨
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &paintings[i].left);// left번 좌석부터
        scanf("%d", &paintings[i].right);// right번 좌석까지
        scanf("%d", &paintings[i].color);// color색으로 칠해주세요

        // 사용자 입력으로 주어지는 좌석은 1번부터 시작하기에 1씩 빼준다.
        paintings[i].left -= 1;
        paintings[i].right -= 1;
    }
    
    solve(n, m, paintings);

    return 0;
}
