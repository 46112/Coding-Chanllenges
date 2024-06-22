#include <cstdio>
#include <iostream>

using namespace std;

/*

<소수의 판별>
해당 숫자가 소수인지 판별
1과 N으로는 당연히 나누어 떨어짐 -> 그 외의 약수가 존재하면 소수가 아님
2부터 N-1까지 비교하면 된다
하지만 약수는 다른 약수의 존재를 확인시켜준다
예를 들어 2가 N으로 나누어 떨어진 다는 것은 2랑 곱해서 N이 되는 N/2가 약수로 존재한다는 것이다

따라서 2부터 루트 N까지만 비교하면 된다
다만 9와 같이 root N이 정수인 경우가 있을 수 있으므로 i제곱 = N이 되는 경우를 포함해서 반복문을 돌린다


*/

bool isPrime(int N)
{
    if (N == 1) return false;

    for (int i = 2; i*i <= N; i++)
    {
        if (N % i == 0) return false;
    }
    return true;
}

void testcase(int caseIndex)
{
    // 소수인지 판별하고자 하는 수를 입력받음
    int n;
    scanf("%d", &n);

    // isPrime함수 호출하여 소수여부 판별
    bool result = isPrime(n);
    printf("Case #%d\n", caseIndex);
    if (result)
    {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main()  // 입력값 받아 검증
{
    // 테스트 케이스 개수 받아서 testcase함수 호출
    int caseSize;
    scanf("%d", &caseSize);
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
    {
        testcase(caseIndex);
    }
    return 0;
}
