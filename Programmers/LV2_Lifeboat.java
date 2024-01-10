import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import error.IncorrectSolutionException;

public class LV2_Lifeboat {
    public static void main(String[] args) {

        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                // 첫 번째 파라미터 (배열) 처리
                String arrayString = parts[0].substring(1, parts[0].length() - 1); // 대괄호 제거
                System.out.println(arrayString);
                
                String[] arrayParts = arrayString.split(",");
                int[] people = new int[arrayParts.length];
                for (int i = 0; i < arrayParts.length; i++) {
                    people[i] = Integer.parseInt(arrayParts[i].trim());
                }

                // 두 번째와 세 번째 파라미터 (정수) 처리
                int limit = Integer.parseInt(parts[1].trim());
                int result = Integer.parseInt(parts[2].trim());

                
                int myAnswer = solution(people, limit);
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

    private static int solution(int[] people, int limit) {

        Arrays.sort(people);

        int count = 0;
        int light_w_idx = 0;
        int heavy_w_idx = people.length-1;

        while (light_w_idx <= heavy_w_idx) {
            int sum_weight = people[light_w_idx] + people[heavy_w_idx];
            if (sum_weight <= limit) {light_w_idx++; heavy_w_idx--;}
            else heavy_w_idx--;
            count++;
        }

        return count;
    }
}



/*

무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 
2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 
모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

* 제한사항
1. 무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.
2. 각 사람의 몸무게는 40kg 이상 240kg 이하입니다.
3. 구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.
4. 구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.

* 입출력 예
people	            limit	    return
[70, 50, 80, 50]	100	        3
[70, 80, 50]	    100	        3

 */

/*

구명보트 스펙: 제한 인원 2명, 무게제한(limit) 존재
목적 : 구명보트 왕복 횟수를 최소화시키며 사람들을 구출
구명보트는 항상 한 사람씩은 태울 수 있도록 나옴

정렬
50, 50, 70, 80
50, 70, 80



 */