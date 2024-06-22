#include <cstdio>
#include <vector>

using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;

/*

<스도쿠보드>
주어진 스도쿠보드(1부터 81 순서대로 작성됨)에서 인덱스를 보고,
행, 열, 그룹을 알아내서 출력해라
인덱스 = (행번호-1) * MAX_COL + 열번호
그룹번호 = ((행번호-1) // 3) * 3 + ((열번호-1) // 3 + 1)

*/

class SudokuBoard {
public:
    int getRowByIndex(int index) {// index를 보고 row 추출
        int quotient = (index-1) / MAX_COL;// MAX_COL으로 나누었을 때 1번줄, 2번줄 명확히하기 위해 index-1를 사용
        return quotient + 1;//몫은 0부터 시작하므로 row을 추출하기 위해서는 1을 더함
    }

    int getColByIndex(int index) {// index를 보고 column 추출
        int rest = (index-1) % MAX_COL; // 마찬가지로 index-1에 대해 나머지 연산
        return rest + 1;
    }

    int getGroupByIndex(int index) {// index를 보고 group 추출
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        return getGroupByPosition(r, c);
    }

    int getGroupByPosition(int row, int column) {// 실질적인 group추출 함수
        int r_quotient = (row - 1) / 3;// 그룹은 가로세로 3개씩 포함하고 있으므로 3으로 나누어 그룹을 알아낸다
        int c_quotient = (column - 1) / 3;
        return r_quotient * 3 + c_quotient + 1;
    }

    int getIndexByPosition(int row, int column) {
        return (row - 1) * MAX_COL + column;
    }
};

void process(int caseIndex)
{
    int index;
    scanf("%d", &index);

    SudokuBoard board = SudokuBoard();

    int row = board.getRowByIndex(index);
    int col = board.getColByIndex(index);
    int group = board.getGroupByIndex(index);

    // 해당 케이스 row, col, group 출력
    printf("Case #%d:\n", caseIndex);
    printf("%d %d %d\n", row, col, group);
}

int main()  // 입력값 받아 검증
{
    int caseSize;
    scanf("%d", &caseSize);

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex)
    {
        // 각 케이스 별 row, col, group 출력
        process(caseIndex);
    }
}
