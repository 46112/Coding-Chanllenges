import java.io.File;
import java.io.FileNotFoundException;
import java.util.Objects;
import java.util.Scanner;

import error.IncorrectSolutionException;

public class LV2_HIndex {
    
    public static void main(String[] args) {
        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                String paramString = parts[0].substring(1, parts[0].length()-1);
                String[] param = paramString.split(",");
                int[] citations = new int[param.length];
                for(int i=0; i<param.length; i++){
                    citations[i] = Integer.parseInt(param[i]);
                }

                int result = Integer.parseInt(parts[1]);

                int myAnswer = solution(citations);
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

    public static int solution(int[] citations) {
        int hIndex = 0;
        int n = citations.length;
        for(int h=1; h<n+1; h++) {
            int count = 0;

            for(int citation: citations){
                if (citation >= h) count++;
                if (count >= h) {
                    hIndex = h;
                    break;
                }
            }
        }
        return hIndex;
    }
}


/*

1. 문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 
어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 
위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

2. 제한사항
과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

3. 입출력 예
citations	        return
[3, 0, 6, 1, 5]	    3

4. 입출력 예 설명
이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 
그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

*/

/*
    H-index 값인 h를 구하는 것이 목표.
    과학자가 발표한 논문 n편 중에서, h번 이상 인용된 논문이 h편 이상 -> H-index = h의 최댓값
    citations = 인용 횟수를 담은 배열
    
    H-index = 0;
    for h in range(1,n+1): //1~n
        count = 0;
        isValid = false;

        for citation in citations:
            if(citation >= h):
                count++;
            if(count >= h):
                H-index = h;
                isValid = true;
                break;
        if(isValid):
            break;

*/