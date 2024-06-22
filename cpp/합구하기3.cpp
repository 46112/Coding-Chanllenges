#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*

<합 구하기 3>
1부터 end까지 합을 구하는데, end를 1부터 n까지 해서 총 합을 구해야한다. 

*/

int getRangeSumFromOneToEnd(int end)
{
    int sum = 0;
    for (int i = 1; i <= end; i++)
    {
        sum += i;
    }
    
    return sum;
}

long long getAnswer(int N)
{
    long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += getRangeSumFromOneToEnd(i);
    }
    
    return sum;
}

int main()  // 입력값 받아 검증
{
    int n;
    scanf("%d", &n);

    long long answer = getAnswer(n);

    printf("%lld\n", answer);
    
    return 0;
}
