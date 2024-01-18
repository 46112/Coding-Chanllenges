import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import error.IncorrectSolutionException;

public class LV2_LongJump {
    public static void main(String[] args) {

        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                int n = Integer.parseInt(parts[0].trim());
                long result = Long.parseLong(parts[1].trim());
                long myAnswer = solution(n);

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
    
    static Map<Integer, Long> funcResult = new HashMap<>();

    public static long solution(int n) {
        
        if (n<3) return (long)n;
        boolean hasPrevResult = funcResult.containsKey(n);
        
        if (hasPrevResult) return funcResult.get(n);
        
        long result = solution(n-1) + solution(n-2);
        funcResult.put(n, result);
        
        return result%1234567;
    }

    /*
    
    문제 설명
    효진이는 멀리 뛰기를 연습하고 있습니다. 효진이는 한번에 1칸, 또는 2칸을 뛸 수 있습니다. 칸이 총 4개 있을 때, 효진이는
    (1칸, 1칸, 1칸, 1칸)
    (1칸, 2칸, 1칸)
    (1칸, 1칸, 2칸)
    (2칸, 1칸, 1칸)
    (2칸, 2칸)
    의 5가지 방법으로 맨 끝 칸에 도달할 수 있습니다. 멀리뛰기에 사용될 칸의 수 n이 주어질 때, 효진이가 끝에 도달하는 방법이 몇 가지인지 알아내,
    여기에 1234567를 나눈 나머지를 리턴하는 함수, solution을 완성하세요. 예를 들어 4가 입력된다면, 5를 return하면 됩니다.

    제한 사항
    n은 1 이상, 2000 이하인 정수입니다.

    f(n) = f(n-1) + f(n-2)

     */
}
