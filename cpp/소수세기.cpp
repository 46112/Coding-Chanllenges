#include <cstdio>
#include <vector>

using namespace std;

/*

<소수세기>
소수의 개수를 출력해라

*/

class Sieve {
public:
    int maximumValue;
    vector<bool> isPrime;
    Sieve(int maximumValue) {
        this->maximumValue = maximumValue;
        this->isPrime.assign(maximumValue + 1, true);// 1~maximumValue까지 의미부여를 위해 maximumValue+1만큼 element넣어줌, 2~maximumvalue까지 모두 소수라고 체크true
        this->fillSieve();// Sieve 객체 생성될 때 fillSieve메서드 호출됨
    }
    
    bool isPrimeNumber(int num) const {
        return this->isPrime[num];//소수 여부
    }
    void fillSieve() {// 아르키메데스 체 구성
        isPrime[0] = false;
        isPrime[1] = false;//0과 1은 소수가 아니다

        for (int num = 2; num <= maximumValue; num++)
        {
            if (isPrime[num] == false) continue;//소수가 아니면 패스
            else {// m이 소수라면 m의 제곱부터 N까지 범위에 있는 m의 배수들은 모두 소수가 아니다
                for (long long multi_num = (long long) num * num; multi_num <= maximumValue; multi_num += num)
                {
                    int index = (int) multi_num;
                    isPrime[index] = false;
                }
            }
        }
    }
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
    vector<int> primes;//리턴할 소수 리스트

    for (int num = from; num <= to; num++)
    {
        if (sieve.isPrimeNumber(num))// 이미 sieve는 소수 판별을 끝낸 상태이므로 isPrimeNumber로 소수 확인후 리스트에 넣기만 하면 된다
        {
            primes.push_back(num);
        }
    }
    return primes;
}

void process(int caseIndex, const Sieve& sieve) {
    int L, R;
    scanf("%d%d", &L, &R);

    // 소수 목록 가져오기
    vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

    printf("Case #%d:\n", caseIndex);
    printf("%d\n", (int)allPrimeNumbers.size());
}

int main()  // 입력값 받아 검증
{
    const int MAX_VALUE = 1000000;
    Sieve sieve = Sieve(MAX_VALUE);// Sieve객체 생성

    int caseSize;
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
    {
        process(caseIndex, sieve);// 각 케이스별 
    }
}
