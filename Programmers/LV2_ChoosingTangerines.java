import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import error.IncorrectSolutionException;

public class LV2_ChoosingTangerines {
    public static void main(String args[]){

        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                int k = Integer.parseInt(parts[0].trim()); // 첫번째 파라미터 int형
                
                String arrayString = parts[1].substring(1, parts[1].length()-1);
                String[] arrayParts = arrayString.split(",");
                int[] tangerine = new int[arrayParts.length]; // 두번째 파라미터 int배열
                for (int i=0; i<arrayParts.length; i++) {
                    tangerine[i] = Integer.parseInt(arrayParts[i].trim());
                }

                Integer result = Integer.parseInt(parts[2].trim()); // 세번째 파라미터 int형
                
                Integer myAnswer = solution(k, tangerine);
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


    public static int solution(int k, int[] tangerine) {
        Map<Integer, Integer> tangerineDoc = new HashMap<>();

        for (int t : tangerine) { // Map에 크기에 따른 귤 정보들을 저장
            if (!tangerineDoc.containsKey(t)) {
                tangerineDoc.put(t, 1);
                continue;
            }

            tangerineDoc.put(t, tangerineDoc.get(t) + 1);
        }

        // Value에 대해 내림차순으로 Map 정렬
        List<Integer> keyset = new ArrayList<>(tangerineDoc.keySet());
        keyset.sort((o1, o2) -> tangerineDoc.get(o2).compareTo(tangerineDoc.get(o1)));

        // 결과 찾기
        int type = 0;
        int currentCount = 0;

        for (Integer tangerineKey : keyset) {
            if (currentCount >= k) break;
            currentCount += tangerineDoc.get(tangerineKey);
            type += 1;
        }

        return type;
    }
}


/*

경화는 과수원에서 귤을 수확했습니다. 경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매하려고 합니다. 
그런데 수확한 귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화하고 싶습니다.

예를 들어, 경화가 수확한 귤 8개의 크기가 [1, 3, 2, 5, 4, 5, 2, 3] 이라고 합시다. 
경화가 귤 6개를 판매하고 싶다면, 크기가 1, 4인 귤을 제외한 여섯 개의 귤을 상자에 담으면, 
귤의 크기의 종류가 2, 3, 5로 총 3가지가 되며 이때가 서로 다른 종류가 최소일 때입니다.

경화가 한 상자에 담으려는 귤의 개수 k와 귤의 크기를 담은 배열 tangerine이 매개변수로 주어집니다. 
경화가 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

기본적으로 많은 것 부터 담으면 됨
맵에 개수 세기
맵 정렬
큰 것부터 담아서 더 커지는 순간 break


 */