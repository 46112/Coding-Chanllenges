#include <stdio.h>
#include <iostream>

using namespace std;

/*

n는 놀이기구를 타려는 회원 수
p는 해당 놀이기구 탑승 제한 체중
q는 놀이기구가 버틸 수 있는 최대 하중

data에는 n명의 회원들 각각의 몸무게

구하고자 하는 것?
첫 줄 - 체중 제한 통과한 회원 수 & 제한 통과한 회원들의 몸무게 합
둘째 줄 - 모두가 탈 수 있는 지 boolean

*/

void solve(int data[], int n, int p, int q)
{
    // 체중 제한을 통과한 회원 수와 뭄무게 합 0으로 초기화
    int count = 0;
    int sum_of_weight = 0;

    // data 배열을 순회하며 모든 회원들의 몸무게를 확인한다.
    for (int i = 0; i < n; i++)
    {
        if (data[i] <= p) // 제한 체중 p를 넘지 않는다면 놀이기구를 탈 수 있다.
        {
            count++;
            sum_of_weight += data[i];
        }        
    }
    
    printf("%d %d\n", count, sum_of_weight);
    if (sum_of_weight <= q) printf("YES"); // 무게 합이 q를 넘지 않으면 함께 탑승할 수 있다.
    else printf("NO");
}

int main()  // 입력값 받아 검증
{
    int n, p, q;
    int *data;

    scanf("%d %d %d", &n, &p, &q);
    data = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }

    solve(data, n, p, q);
    return 0;
}
