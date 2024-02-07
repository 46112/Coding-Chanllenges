import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import error.IncorrectSolutionException;

public class LV2_Costume {
    public static void main(String[] args){
        String[][] case1_clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
        String[][] case2_clothes = {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}};

        int case1_answer = 5;
        int case2_answer = 3;

        int myAnswer1 = solution(case1_clothes);
        int myAnswer2 = solution(case2_clothes);

        if (Objects.equals(myAnswer1, case1_answer)) System.out.println("1번 케이스 통과!");
        else throw new IncorrectSolutionException(myAnswer1, case1_answer);
        if (Objects.equals(myAnswer2, case2_answer)) System.out.println("2번 케이스 통과!");
        else throw new IncorrectSolutionException(myAnswer2, case2_answer);
    }

    public static int solution(String[][] clothes) {
        Map<String, Integer> costumesByType = new HashMap<>();

        for (String[] clothe : clothes) {
            String clotheType = clothe[1];
            costumesByType.put(clotheType, costumesByType.getOrDefault(clotheType, 0)+1);
        }

        int answer = 1;
        for (Integer choices : costumesByType.values()) {
            choices++;
            answer*=choices;
        }
        return --answer;
    }

    /*
    eyewear가 1종류 headgear가 2종류있을 때,
    eyewear를 쓰던가(1가지) 안쓰던가(1가지) 2가지 케이스
    headgear를 쓰던가(2가지) 안쓰던가(1가지) 3가지 케이스
    총 2*3=6가지 케이스
    하지만 아무것도 안입는 경우는 존재하지 않으니, 6-1로 5가지 케이스가 정답
     */
}
