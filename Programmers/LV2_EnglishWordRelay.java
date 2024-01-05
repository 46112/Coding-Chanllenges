// n은 사람 수, words는 끝말잇기 게임 내용 속기
// return [가장 먼저 탈락하는 사람의 번호, 그 사람의 몇번째 차례에 탈락했는가]

import java.util.Arrays;
import java.util.HashMap;

public class LV2_EnglishWordRelay {
    public static void main(String[] args) {
        final int totalTest = 3;
        int successTest = 0;

// case 1
        int n1 = 3;
        String[] words1 = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
        int[] answer1 = {3, 3};

        if (test(gameSummary(n1, words1), answer1)) successTest += 1;


// case 2
        int n2 = 5;
        String[] words2 = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
        int[] answer2 = {0, 0};

        if (test(gameSummary(n2, words2), answer2)) successTest += 1;

// case 3
        int n3 = 2;
        String[] words3 = {"hello", "one", "even", "never", "now", "world", "draw"};
        int[] answer3 = {1, 3};

        if (test(gameSummary(n3, words3), answer3)) successTest += 1;

        System.out.printf("total: %d, success: %d", totalTest, successTest);
    }

    private static boolean test(int[] solve, int[] answer) {

        if (Arrays.equals(solve, answer)) {
            return true;
        }

        System.out.println("expected: " + Arrays.toString(solve) + ", but real: " + Arrays.toString(answer));
        return false;
    }

    private static int[] gameSummary(int num, String[] game) {

        HashMap<String, Integer> memory = new HashMap<>();
        int numOfChallenge = 0;
        
        for(int i=0; i<game.length; i++) {

            // check duplication            
            if (memory.containsKey(game[i])) {
                numOfChallenge = i+1;
                break;
            } else {
                memory.put(game[i], null);
            }

            // check rule violation
            if (i>0) {
                char prev = game[i-1].charAt(game[i-1].length()-1);
                char curr = game[i].charAt(0);
                if(prev != curr) {
                    numOfChallenge = i+1;
                    break;
                }
            }
        }

        if (numOfChallenge == 0) {
            return new int[] {0,0};
        }

        int lastPerson = numOfChallenge % num;

        int order = (numOfChallenge / num) + 1;

        if (lastPerson==0) {
            lastPerson = num;
            order -= 1;
        }       
        
        return new int[] {lastPerson, order};
    }


}
