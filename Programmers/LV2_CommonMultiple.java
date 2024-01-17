import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import error.IncorrectSolutionException;

public class LV2_CommonMultiple {

    public static void main(String[] args) {

            try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                // 첫 번째 파라미터 (배열) 처리
                String arrayString = parts[0].substring(1, parts[0].length() - 1); // 대괄호 제거
                
                String[] arrayParts = arrayString.split(",");
                int[] arr = new int[arrayParts.length];
                for (int i = 0; i < arrayParts.length; i++) {
                    arr[i] = Integer.parseInt(arrayParts[i].trim());
                }

                int result = Integer.parseInt(parts[1].trim());
                int myAnswer = solution(arr);

                if(myAnswer!=result) {scanner.close(); throw new IncorrectSolutionException(myAnswer, result);}
            }
            scanner.close();
            System.out.println("통과!");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IncorrectSolutionException e) {
            System.err.println(e.getMessage());
        }
    }

    public static int solution(int[] arr) {

        if (arr.length<2) return arr[0];
        
        // 두 수의 공약수 찾기
        int gcd = findLargestCommonDivisor(arr[0], arr[1]);
        int result = (arr[0]/gcd) * (arr[1]/gcd) * gcd;

        for (int i=2; i<arr.length; i++) {
            gcd = findLargestCommonDivisor(result, arr[i]);
            result = (result/gcd) * (arr[i]/gcd) * gcd;
        }

        return result;
    }

    private static int findLargestCommonDivisor(int x, int y) {
        
        // 유클리드 호제법
        int r = x % y;
        
        while(r!=0) {
            x = y;
            y = r;
            r = x % y;
        }

        return y;
    }
}


/*


1. 문제 설명
- 두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다. 예를 들어 2와 7의 최소공배수는 14가 됩니다. 
정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다. 
n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

2. 제한 사항
- arr은 길이 1이상, 15이하인 배열입니다.
- arr의 원소는 100 이하인 자연수입니다.

[2,6,8,14] 168
[1,2,3] 6
14, 2, 7

7*1*2 = 14
2-1*7 = 14

두 수의 최대 공약수 구하기
나누어 서로서끼리 곱하기
그곳에 또 최대 공약수 곱하기 -> 두 수의 최소 공배수

 */