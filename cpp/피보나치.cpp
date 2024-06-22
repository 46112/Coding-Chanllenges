#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;

/*

<피보나치>
N은 1부터 100만까지의 수이다.
N번째 피보나치 수를 구해라
단, 마지막 8자리 숫자만을 출력해라 -> 1억으로 나눈 나머지

*/

vector<int> makeFibonacciTable(int n)
{
    const int MOD = 100000000;

    // 인덱스 의미부여를 위해 100만1만큼 크기 선언
    vector<int> ret(n + 1);
    ret[1] = 0;
    ret[2] = 1;

    // 피보나치 수열은 앞의 둘을 더한 수가 그 다음 수이다.
    // 1억으로 나눈 나머지는 문제 추가 조건이다.
    // 1억으로 나누어도 1억 이상의 수가 그 아래 8자리 수끼리 더하는 것에 아무런 영향을 주지 못한다
    for (int i = 3; i <= n; i++)
    {
        ret[i] = (ret[i-2] + ret[i-1]) % MOD;
    }

    return ret;
}

int getFibo(int n)
{
    // 전역으로 선언된 피보나치 수열 테이블에서 n번째 피보나치 수를 return
    return FIBONACCI_TABLE[n];
}

int main()  // 입력값 받아 검증
{
    // 10만번째까지 피보나치 수열 테이블 생성
    FIBONACCI_TABLE = makeFibonacciTable(MAX_N);

    // 사용자 입력으로 받은 테스트 케이스 수
    int case_size;
    scanf("%d", &case_size);

    for (int case_index = 0; case_index < case_size; ++case_index)
    {
        // n번째 피보나치 수 요청
        int n;
        scanf("%d", &n);

        int answer = getFibo(n);
        printf("%d\n", answer);
    }

    // 테이블 정리
    FIBONACCI_TABLE.clear();
    
    return 0;
}
