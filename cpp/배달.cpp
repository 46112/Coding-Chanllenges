#include <cstdio>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

/*
<배달>
소포에는 고유하지 않는 라벨 번호 1~N가 붙음
용봉이가 배송한 소포 번호는 A시퀀스에 저장됨 - N개 공간 차지
-> 공간 절약을 위해 앞 소포 번호와의 차이를 D시퀀스에 저장함 - N-1개 공간 차지
D시퀀스를 A시퀀스로 복구하는 프로그램 작성

최소 최대가 1부터 N사이를 만족하는지 알아보고, 이를 만족하는 초기값이 여러개 혹은 없으면 
복구 불가능함

*/

bool isPossible(int min, int max, int n)// 복구한 A시퀀스의 최소, 최대가 1과 N사이를 만족하는지 판별하는 함수
{
    return (1 <= min && max <= n);
}

void restoreSequence(int n, vector<int>& D)
{
    int A1 = 0;// 첫번째 초기값 = A1
    int temp = A1;// 초기값에 더할 값 - 초기값을 0으로 가정한 상태
    int max_value = temp;// 복구했을 때 A시퀀스의 최대값
    int min_value = temp;// 복구했을 때 A시퀀스의 최소값

    for (auto &d : D)// 최소 최대 찾기
    {
        // 앞의 번호 = 이전 번호 + d
        temp += d;
        if (temp > max_value) max_value = temp;
        else min_value = temp;
    }
    
    // 조건을 만족하는 초기값이 몇개인지 찾는 과정
    int count = 0;
    for (int init_value = 1; init_value <= n; init_value++)// 초기값 번호는 1부터 N까지 가능
    {
        // 기존 최소, 최대는 초기값을 0으로 가정한 상태이므로 추가적으로 제대로된 초기값을 더해줘야함
        int min = init_value + min_value;
        int max = init_value + max_value;
        if (isPossible(min, max, n))
        {
            count++;
            A1 = init_value;
        }
        
        if (count > 1)// 조건을 만족하는 초기값이 여러개이면 고유한 배열로 복구 불가능함
        {
            cout << -1 << endl;
            return;
        }
    }
    
    if (count != 1)// 조건을 만족하는 초기값이 없으면 복구 불가능함
    {
        cout << -1 << endl;
        return;
    }

    vector<int> A;// 복구 배열
    A.push_back(A1);
    int prev = A1;
    for (auto &d : D)// 복구 과정
    {
        int next = prev + d;
        A.push_back(next);
        prev = next;
    }

    // 복구한 배열 출력
    for (int i = 0; i < n; i++) {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    return;
}


int main()
{
    int n;// 소포 개수
    cin >> n;

    vector<int> D;// D시퀀스 입력받음
    for (int i = 1; i <= n-1; i++)
    {
        int diff;
        cin >> diff;
        D.push_back(diff);
    }

    clock_t start = clock();// 시간 측정 시작
    restoreSequence(n, D);// D -> A 복구
    cout << endl;
    clock_t end = clock();// 시간 측정 끝

    cout << "실행시간: " << double(end - start) / CLOCKS_PER_SEC << "초" << endl;
    return 0;
}
