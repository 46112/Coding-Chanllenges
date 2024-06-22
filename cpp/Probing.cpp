#include <cstdio>
#include <vector>

using namespace std;

/*

<Probing>
추첨권 번호 분배 문제
m은 항상 n이하이다
추첨 번호는 각 회원번호의 나머지, 사용되고 있으면 1씩 더해가면서 찾아낸다

*/

class TicketTable {
public:
    vector<bool> used;
    int length;

    TicketTable(int length) {// 0~n-1 인덱스까지 false로 초기화
        this->length = length;
        this->used.assign(length, false);
    }

    int findEmptyIndexByUserId(int userId) {
        int ticket_number = userId % length;//초기 티켓번호는 회원번호를 n으로 나눈 나머지
        while (isUsed(ticket_number) == true)// 사용되지 않는 index 찾을때까지 반복
        {
            ticket_number++;
            ticket_number = ticket_number % length;// 1씩 증가하다가 n넘어가면 0부터 시작
        }
        return ticket_number;
    }

    bool isUsed(int ticketIndex) {// 해당 ticket번호가 사용되었는지 확인
        return used[ticketIndex];
    }

    void setUsed(int index, bool status) { // 사용된 행운권 번호 마킹
        used[index] = status; // 사용되고 있으면 true, 아니면 false
    }
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
    vector<int> tickets;
    TicketTable table = TicketTable(n);

    for (int i = 0; i < m; i++)
    {
        int ticket_number = table.findEmptyIndexByUserId(ids[i]);
        table.setUsed(ticket_number, true);//사용되었음을 마킹
        tickets.push_back(ticket_number);
    }
    return tickets;
}

int main()  // 입력값 받아 검증
{
    int n,m; // n은 행운권 개수, m은 입장한 회원 명수
    scanf("%d%d", &n, &m);

    vector<int> ids(m);// 회원번호 리스트
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &ids[i]);
    }

    vector<int> tickets = getTicketNumbers(n, m, ids);
    for (int i = 0; i < tickets.size(); i++)
    {
        printf("%d\n", tickets[i]);//입장한 회원들의 행운권 번호 출력
    }
}
