#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
<괄호문자열>
'('와 ')'으로만 구성된 문자열이 주어졌을 때 올바른 괄호 문자열로 구성되었는지 구하여라
올바른 괄호문자열은
1. 열린 괄호가 먼저 나오고 닫힌 괄호가 나와야한다
2. 둘의 개수가 같아 한 쌍을 이루어야 한다

닫힌 괄호는 열려있는 괄호 중에서 가장 가까운(최근에 나온) 괄호를 닫으므로, stack자료구조를 사용한다
*/

class Parenthesis {
public:
    bool type;
    int index;

    Parenthesis(int index, bool type) {
        this -> index = index;
        this -> type = type;
    }

    Parenthesis(int index, char c) {
        this -> index = index;
        if (c == '(')
        {
            this -> type = true;
        } else {//해당 문자열은 괄호로만 구성되어있기에 '('가 아니면 ')'이다
            this -> type = false;
        }
    }
};

// 실제로 유효한 괄호문자열인지 판별하는 함수
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
    stack<Parenthesis> myStack;

    for (int i = 0; i < parentheses.size(); i++)
    {
        if (parentheses[i].type) myStack.push(parentheses[i]);//만약 열린 괄호일 경우에는 스택에 집어넣는다
        else {// 만약 닫힌 괄호일 경우에는
            if (myStack.empty()) return false; //스택이 비어있을 경우, 열린 괄호 이전에 닫힌 괄호가 나왔으므로 유효하지 않는 케이스이다
            else { // 스택에 열린괄호가 차있을 경우 한 쌍을 이루었으므로 pop한다
                myStack.pop();
            }
        }
    }
    
    if (!myStack.empty()) return false;// 만약 반복문이 끝나고도, stack에 무언가가 남아있다면 열린 괄호 개수가 닫힌 괄호 개수보다 많은 것이다
    
    return true;
}

// 테스트 진행 함수
void process(int caseIndex) {
    string str;
    cin >> str;

    vector<Parenthesis> parentheses;
    for (int i = 0; i < str.length(); i++)
    {
        parentheses.push_back(Parenthesis(i, str[i]));// 두번째 생성자를 사용했으므로, str[i]가 '('이면 type이 true, 아닐 경우에는 false이다.
    }

    bool isValid = isValidParentheses(parentheses);

    if (isValid) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int caseSize;
    cin >> caseSize; // 테스트 케이스 개수
    
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
    {
        process(caseIndex);
    }
    
    return 0;
}
