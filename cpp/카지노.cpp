#include <cstdio>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

/*

<카지노>
N명이 게임 참가
각자에게 1부터 10사이 숫자 5개 주어짐
이 중 3개의 합을 구한 후 일의 자리 수가 가장 큰 사람이 승리(5개 중 3개를 조합해서 일의 자리가 가장 큰 경우를 골라야함)

*/

int calculateDigitSum(int a, int b, int c) { // 3개의 수를 합쳐서 1의 자리 추출
    int sum = (a + b + c);
    return sum % 10;
}

int findBestCombinationSum(vector<int> cards) { // 5개의 카드 중 가장 승리할 확률이 높은 최고의 패 3개를 선택한 결과 일의 자리 수를 리턴하는 함수
    int max_sum = -1; // 최대 일의 자리 수 초기화

    // 세 장의 카드를 선택하여 합의 일의 자리 수 계산
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                int digitSum = calculateDigitSum(cards[i], cards[j], cards[k]);
                max_sum = max(max_sum, digitSum); // 최대 일의 자리 수 갱신
            }
        }
    }

    return max_sum;
}

int main()  // 입력값 받아 검증
{
    int N;
    cin >> N;

    // 입력값 플레이어 수와 각 플레이어의 패를 받음
    vector<vector<int>> cards(N + 1, vector<int>(5));// 플레이어 번호에 대응되기 위해서 N+1크기로 선언
    for (int player = 1; player <= N; player++) {
        for (int card = 0; card < 5; card++)
        {
            cin >> cards[player][card];
        }
    }

    time_t start, finish;
    double duration;
    start = time(NULL);//시간 측정 시작 - 초 단위 출력을 위해 time사용

    // 플레이어들의 패를 비교해서 승리한 플레이어를 리턴한다
    int winning_player = 0;//승리한 플레이어의 번호
    int max_sum = 0;//승리한 플레이어의 카드 합
    for (int player_num = 1; player_num <= N; player_num++)
    {
        int cur_player_card_sum = findBestCombinationSum(cards[player_num]);//해당 플레이어의 최고의 패
        if(max_sum <= cur_player_card_sum) {// 같을 경우 플레이어 번호가 큰 쪽이 승리하므로 같을 경우를 포함해서 조건문을 건다
            winning_player = player_num;
            max_sum = cur_player_card_sum;
        }
    }

    finish = time(NULL);// 시간 측정 끝
    duration = (double) (finish - start);

    cout << winning_player << endl;
    cout << "실행시간: " << duration << "초" << endl;
    return 0;
}
