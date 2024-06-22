#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <ctime>

using namespace std;

/*
<압축>
압축 코스트를 줄이는 방향으로 압축을 자유롭게 진행하고 싶음
첫번째 수와 앞에 수와 다른 수는 2bit코드 표에 따라 변환
앞에 수와 같은 수는 1(00)으로 변환

변환 비용은 = 전체 에러 + W * 변환코드의 길이

1 - "00"
86 - "01"
172 - "10"
256 - "11"

*/

int W;
int min_cost = INT_MAX;
string converted_code = "";

string convertToBitCode(vector<int>& converted_list) {// 변환한 수를 이진 코드로 변경하는 함수
    map<int, string> two_bit_code {{1, "00"}, {86, "01"}, {172, "10"}, {256, "11"}};
    
    string code = "";
    for (int i = 0; i < converted_list.size(); i++)
    {   
        int cur_num = converted_list[i];
        if (i == 0)// 맨 처음은 이진 코드표를 통해 변환
        {
            code += two_bit_code[cur_num];
            continue;
        }
        
        if (cur_num != converted_list[i - 1])// 앞의 수와 뒤의 수가 상이하면 1을 붙인 후에 이진 코드 변환
        {
            code += "1";
            code += two_bit_code[cur_num];
        } else {// 앞의 수와 뒤의 수가 동일하면 0을 붙임
            code += "0";
        }
    }
    
    return code;
}

int calculateTotalError(const vector<int>& initial_list, vector<int>& converted_list) {// 초기 리스트와 변환 리스트를 비교해서 오류의 양을 계산하는 함수
    if (initial_list.size() != converted_list.size()) // 변환 리스트는 초기 리스트와 1대 1 매칭이 되기에 둘의 길이가 다르면 오류
        return INT_MAX;
    
    int total_error = 0;
    for (int i = 0; i < initial_list.size(); i++)
    {
        total_error += abs(converted_list[i] - initial_list[i]);
    }
    
    return total_error;
}

int calculateConversionCost(int total_error, int code_length) {// 변환 비용을 계산하는 함수
    return total_error + W * code_length;
}

void findMinCost(int cur_idx, vector<int>& initial_list, vector<int>& converted_list) {// 실질적으로 최소 비용인 케이스를 계산하는 함수
    if (cur_idx >= initial_list.size())// 현재 인덱스가 리스트의 길이와 같아지는 순간 = 더 이상 변환할 초기 리스트의 요소가 없는 순간 = 비용 산정 가능
    {
        string bit_code = convertToBitCode(converted_list);
        int total_err = calculateTotalError(initial_list, converted_list);
        int cost = calculateConversionCost(total_err, bit_code.length());
        
        if (cost < min_cost)// 계산한 비용과 최소 비용을 비교해보고, 최소 비용인 순간에 한해 답으로 출력할 cost와 변환된 이진 코드를 갱신
        {
            min_cost = cost;
            converted_code = bit_code;
        }

        return;
    }
    
    const vector<int> levels = {1, 86, 172, 256};
    if (cur_idx == 0) {// 맨 처음 요소는 4가지 케이스로 분기 될 수 있음(사소한 오류는 무시하므로)
        for (int converted_num : levels) {
            vector<int> temp = {converted_num};
            temp.insert(temp.begin(), converted_list.begin(), converted_list.end());
            findMinCost(cur_idx + 1, initial_list, temp);// 다음 인덱스로 분기
        }
        return;
    }

    if (initial_list[cur_idx] == initial_list[cur_idx - 1]) {// 앞 뒤로 동일한 요소일 경우에는 이진코드 0으로 변환하기 위해 변환 리스트에는 1을 추가함
        vector<int> temp = {1};
        temp.insert(temp.begin(), converted_list.begin(), converted_list.end());
        findMinCost(cur_idx + 1, initial_list, temp);
    } else {// 동일하지 않을 경우에는 level 4가지 케이스로 분기
        for (int converted_num : levels) {
            vector<int> temp = {converted_num};
            temp.insert(temp.begin(), converted_list.begin(), converted_list.end());
            findMinCost(cur_idx + 1, initial_list, temp);
        }
    }
    
    return;
}

void compressImage(vector<int>& initial_list) {// 실제로 main에서 호출하는 함수
    vector<int> converted_list;

    findMinCost(0, initial_list, converted_list);
    cout << min_cost << endl;
    cout << converted_code << endl;
    return;
}

int main() {
    int N;
    cin >> N >> W;// 수열의 길이와 가중치를 입력받음

    vector<int> initial_list;
    for (int i = 0; i < N; i++)// 수열을 입력받음
    {
        int num;
        cin >> num;
        initial_list.push_back(num);// 초기 리스트
    }

    clock_t start = clock();// 시간 측정 시작
    compressImage(initial_list);
    clock_t end = clock();// 시간 측정 끝

    cout << "실행시간: " << double(end - start) / CLOCKS_PER_SEC << "초" << endl;

    return 0;
}