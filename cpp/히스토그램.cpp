#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

/*
<히스토그램>
히스토그램 내부에서 가질 수 있는 가장 큰 직사각형의 넓이

*/

long long getLargestRectangleArea(const vector<int>& histograms, int n) {
    long long answer = 0;

    stack<int> s;// 오름차순을 만족하는 히스토그램들이 들어간다
    s.push(0);// while문은 두번 top을 조회한다 - 비어있는 부분에 대해 top조회를 방지하기 위해 0번 인덱스 추가

    for (int i = 1; i <= n + 1; i++)
    {
        while(!s.empty() && histograms[i] < histograms[s.top()]) {//비어있지 않고, 현재 확인 중인 히스토그램의 높이가 이전 히스토그램의 높이보다 작을 때
            int prev_part = s.top();//바로 이전 히스토그램의 인덱스 - 이는 직사각형의 왼쪽 부분 - 즉, 이 인덱스 부분의 높이가 직사각형의 높이가 된다
            s.pop();// 해당 높이가 쓰일 수 있는 최대를 구했으니 pop해서 빼낸다

            long long height = histograms[prev_part];
            long long width = abs(i - 1 - s.top());// 직사각형의 오른쪽 부분은 현재 확인 중인 히스토그램(i)바로 이전으로 정해져 있다 - 따라서 너비는 왼쪽과 같이 구할 수 있다
            long long area = height * width;
            answer = max(answer, area);
        }
        s.push(i);// 더 이상 해당 히스토그램보다 높이가 큰 히스토그램이 스택 안에 존재하지 않으면 push한다
    }
    
    return answer;
}

void process(int caseIndex) {
    int n;// 히스토그램 개수
    cin >> n;

    vector<int> histograms;// 1번 인덱스부터 n번 인덱스까지는 실제 입력받은 각 히스토그램의 높이를 나타냄
    histograms.push_back(0);// 0번 인덱스의 높이는 0

    for (int i = 1; i <= n; i++)// 1번 인덱스부터 n번 인덱스까지 높이 입력받음
    {
        int height;
        cin >> height;
        histograms.push_back(height);
    }

    histograms.push_back(0);// n+1번 인덱스의 높이는 0 - 높이는 자연수이다. 그러므로 0으로 두어야지 위의 get~~함수의 while문을 만족하지 않아, 답을 구할 때 포함되지 않는다.

    long long answer = getLargestRectangleArea(histograms, n);
    cout << answer << endl;
}

int main() {
    int caseSize;// 테스트 케이스 개수
    cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
    {
        process(caseIndex);
    }
}
