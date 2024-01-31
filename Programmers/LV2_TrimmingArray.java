import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

import error.IncorrectSolutionException;

public class LV2_TrimmingArray {
    public static void main(String[] args) {
        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                int n = Integer.parseInt(parts[0].trim());
                int left = Integer.parseInt(parts[1]);
                int right = Integer.parseInt(parts[2]);
                
                String resultString = parts[3].substring(1, parts[3].length()-1);
                String[] results = resultString.split(",");
                int[] result = new int[results.length];
                for(int i=0; i<result.length; i++){
                    result[i] = Integer.parseInt(results[i]);
                }

                int[] myAnswer = solution(n, left, right);
                if(!Objects.equals(myAnswer, result)) {scanner.close(); throw new IncorrectSolutionException(myAnswer, result);}
            }
            scanner.close();
            System.out.println("통과!");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IncorrectSolutionException e) {
            System.err.println(e.getMessage());
        }
    }

    public static int[] solution(int n, long left, long right) {
        int answerLen = (int)(right-left+1);
        int[] answer = new int[answerLen];

        for(int i=0; i<answerLen; i++) {
            long currentIndex = left+i;
            int rowIndex = (int) Math.floorDiv(currentIndex, n);
            int colIndex = Math.floorMod(currentIndex, n);
            
            if (colIndex<rowIndex) answer[i] = rowIndex+1;
            else answer[i] = colIndex+1;
        }

        return answer;
    }
}


/*

정수 n, left, right가 주어집니다. 다음 과정을 거쳐서 1차원 배열을 만들고자 합니다.

1. n행 n열 크기의 비어있는 2차원 배열을 만듭니다.
2. i = 1, 2, 3, ..., n에 대해서, 다음 과정을 반복합니다.
3. 1행 1열부터 i행 i열까지의 영역 내의 모든 빈 칸을 숫자 i로 채웁니다.
4. 1행, 2행, ..., n행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만듭니다.
5. 새로운 1차원 배열을 arr이라 할 때, arr[left], arr[left+1], ..., arr[right]만 남기고 나머지는 지웁니다.

정수 n, left, right가 매개변수로 주어집니다. 주어진 과정대로 만들어진 1차원 배열을 return 하도록 solution 함수를 완성해주세요.

2+0
2/3 = 0행
2%3 = 2열

2+1
3/3 = 1행
3%3 = 0열
원래라면 col+1
col<row -> row+1

 */