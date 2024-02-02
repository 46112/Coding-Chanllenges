import java.util.Arrays;
import java.util.Objects;

import error.IncorrectSolutionException;

public class LV2_MatrixMultiple {
    public static void main(String[] args){
        int[][] case1_arr1 = {{1, 4}, {3, 2}, {4, 1}};
        int[][] case1_arr2 = {{3, 3}, {3, 3}};
        int[][] case1_answer = {{15, 15}, {15, 15}, {15, 15}};

        int[][] case2_arr1 = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}};
        int[][] case2_arr2 = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}};
        int[][] case2_answer = {{22, 22, 11}, {36, 28, 18}, {29, 20, 14}};

        int[][] myAnswer1 = solution(case1_arr1, case1_arr2);
        int[][] myAnswer2 = solution(case2_arr1, case2_arr2);

        if (Arrays.deepEquals(myAnswer1, case1_answer)) System.out.println("1번 케이스 통과!");
        else throw new IncorrectSolutionException(myAnswer1, case1_answer);
        if (Arrays.deepEquals(myAnswer2, case2_answer)) System.out.println("2번 케이스 통과!");
        else throw new IncorrectSolutionException(myAnswer2, case2_answer);
    }

    public static int[][] solution(int[][] arr1, int[][] arr2) {
        int row = arr1.length;
        int col = arr2[0].length;
        int arr2RowCount = arr2.length;

        if (!Objects.equals(arr1[0].length, arr2RowCount)) System.out.println("곱할 수 없는 배열들이 주어졌습니다.");

        int[][] answer = new int[row][col];
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                for(int k=0; k<arr2RowCount; k++) {
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        return answer;
    }
}