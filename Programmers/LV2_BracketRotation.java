import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import error.IncorrectSolutionException;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Stack;

public class LV2_BracketRotation {
    
    public static void main(String[] args) {
        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                String s = parts[0].trim();
                Integer result = Integer.parseInt(parts[1].trim());
                
                Integer myAnswer = solution(s);
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

    public static int solution(String s) {
        int stringLength = s.length();
        int total = 0;

        for(int x=0; x<stringLength; x++){
            String rotationString = s.substring(x, stringLength) + s.substring(0, x);
            if (checkValidationOfBracket(rotationString)) total++;
        }

        return total;
    }

    private static boolean checkValidationOfBracket(String bracketString) {
        Stack<String> bracketStack = new Stack<>();
        String[] brackets = bracketString.split("");
        Map<String, String> bracketPair = new HashMap<>();
        bracketPair.put(")", "(");
        bracketPair.put("}", "{");
        bracketPair.put("]", "[");

        for (String bracket : brackets) {
            if (Objects.equals(bracket, ")") || Objects.equals(bracket, "}") || Objects.equals(bracket, "]")) {
                if (bracketStack.isEmpty()) return false;

                if(Objects.equals(bracketStack.pop(), bracketPair.get(bracket))) continue;
                else return false;
            }
            bracketStack.push(bracket);
        }
        
        if (!bracketStack.isEmpty()) return false;

        return true;
    }
}

/*

1. 문제 설명
다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

(), [], {} 는 모두 올바른 괄호 문자열입니다.
만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 
예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 
예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.

대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 
이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

2. 제한사항
s의 길이는 1 이상 1,000 이하입니다.

3. 아이디어

s만큼 반복
    로테이션 -> subString 사용
    확인

올바른 괄호 문자열이란? 제대로 닫혀있어야 함 -> 스택 사용
[](){} ->
[    ]제거    (    )제거    {    }제거 -> 스택 비어있음 -> 올바른 괄호 문자열
 */
