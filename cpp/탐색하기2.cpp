#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/*

<탐색하기 2>
소속 학교 데이터 n개를 받아서 첫번째 AJOU부터 마지막 AJOU까지 번호를 구하여라
번호는 index+1, 즉 1부터 n까지 부여된다.

*/

void printIndexes(string school[], int n)
{
    int first = -1;
    int last = -1;

    for (int i = 0; i < n; i++)
    {
        if (school[i] == "AJOU")
        {
            if (first == -1) first = i; // first는 한 번만 수정해야 한다.
            last = i;
        }  
    }
    printf("%d %d\n", ++first, ++last); // 번호는 index에 1을 더해야한다.
}

int main()  // 입력값 받아 검증
{
    int n;
    char buff[11];
    string* school;

    scanf("%d", &n);
    school = new string[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", buff);
        school[i] = buff;
    }
    
    printIndexes(school, n);
    delete[] school;
    return 0;
}
