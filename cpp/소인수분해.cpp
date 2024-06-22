#include <cstdio>
#include <vector>

using namespace std;

/*

<소인수분해>
자연수를 소인수분해한 결과 출력

*/

vector<long long> factorize(long n) {// 소인수분해한 결과 리스트
    vector<long long> factors;

    for (int i = 2; i * i <= n; i++)// n을 나눌 수 있는 인수일 경우 root N까지만 고려해도 된다 - 그 이상 소수는 어차피 마지막에 남는다
    {
        while (n % i == 0)//나누어 떨어질 때
        {
            factors.push_back(i); //소인수 목록에 추가
            n = n / i;//나누고 i로 더이상 안 나누어 떨어질 때까지 반복
        }
    }
    
    if (n > 1)
    {
        factors.push_back(n);// 루트 n까지 찾은 인수로 나누었는데 1을 넘긴다 -> 해당수도 소인수이다
    }
    return factors;
}

void process(int caseIndex) {
    long long n;
    scanf("%lld", &n);

    vector<long long> factors = factorize(n);

    printf("#%d:\n", caseIndex);
    for (int i = 0; i < factors.size(); i++)
    {
        if (i > 0) printf(" ");//인수들 출력할 때 빈칸으로 띄워서 구분
        printf("%lld", factors[i]);
    }
    printf("\n");
}

int main()  // 입력값 받아 검증
{
    int caseSize;
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
    {
        process(caseIndex);// 각 케이스별 소인수분해 결과 출력
    }
}
