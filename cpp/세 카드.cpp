#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
<세 카드>
복권 제도 - 매 주 당첨 번호(m개) 정해짐
수많은 카드(n개) 중 세 번 뽑음
세 자연수 더한 수가 당첨 번호와 일치하면 당첨된 것

카드들 리스트가 주어졌을 때 그 카드들로 당첨번호들을 만들어 낼 수 있는지 
자동 판별해주는 프로그램 작성

*/

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
    vector<int> possibleTargets;

    sort(cards, cards + n); // 이진탐색을 위해 정렬

    for (int i = 0; i < m; i++)
    {
        int target = targets[i];// cards조합으로 가능한지 알고 싶은 수
        bool is_possible = false;
        for (int j = 0; j < n; j++)
        {
            int first_pick = cards[j]; // 맨 처음 뽑은 카드
            for (int k = 0; k <= j; k++)
            {
                int second_pick = cards[k]; // 두 번째로 뽑은 카드
                int expected_third = target - (first_pick + second_pick); // 첫번째와 두번째 수를 뽑고 나면 target을 만들기 위해 뽑아야 하는 수가 정해진다

                if (expected_third < 1) continue; // 그 수가 1미만이라면 search할 필요가 없다
                if (binary_search(cards, cards + n, expected_third)) // 이진탐색 결과 cards에 예측값이 존재하면 target은 cards로 조합될 수 있는 수이다
                {
                    is_possible = true;
                    break;
                }
            }
            if (is_possible) break; // 이미 target이 만들어 질 수 있음을 확인했으면 해당 target에 대해서 더 이상의 탐색은 무의미하다
        }
        if (is_possible) possibleTargets.push_back(target);
    }
    return possibleTargets;
}

int main()  // 입력값 받아 검증
{
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int* cards = new int[n];
    int* targets = new int[m];

    for (int i = 0; i < n; i++) { // 사용자가 뽑은 카드들
        scanf("%d", &cards[i]);
    }

    for (int i = 0; i < m; i++) { // 이번주 당첨 번호들
        scanf("%d", &targets[i]);
    }

    vector<int> answers = getPossibleTargets(n, m, cards, targets);

    if (answers.size() == 0)
    {
        printf("NO");// 뽑은 카드들을 조합해서 당첨번호를 만들 수 없으면 NO
    } else {
        for (int i = 0; i < answers.size(); i++)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%d", answers[i]);// 만들 수 있으면 가능한 당첨번호들의 리스트 출력
        }
    }
    delete[] cards;
    delete[] targets;

    return 0;
}