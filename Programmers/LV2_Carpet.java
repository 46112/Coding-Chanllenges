/*
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

입출력 예
brown	yellow	return
10	    2	    [4, 3]
8	    1	    [3, 3]
24	    24	    [8, 6]
*/

import java.util.Arrays;
import java.io.IOException;

public class LV2_Carpet {
    public static void main(String[] args) {
        int totalTest = 3;
        int successTest = 0;
        int failTest = 0;

// 1번 테스트
        if (test(10, 2, 4, 3)) successTest += 1;
        else failTest += 1;

// 2번 테스트
        if (test(8, 1, 3, 3)) successTest += 1;
        else failTest += 1;

// 3번 테스트
        if (test(24, 24, 8, 6)) successTest += 1;
        else failTest += 1;

        System.out.println("총 3개 중에 " + successTest + "개 성공 / " + failTest + "개 실패");
    }

    private static boolean test(int inputBrown, int inputYellow, int width, int height) {
        int[] answer = {width, height};
        int[] predict = null;

        try {
            predict = remindCarpetInfo(inputBrown, inputYellow);
        } catch (IOException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
        
        if (Arrays.equals(predict, answer))  {
            return true;
        } else {
            System.out.printf("갈색 테두리 타일이 %d개이고, 노란색 타일이 %d개일 때, 예상은 %d, %d였지만, 실제로는 %d, %d였다. \n"
            ,inputBrown, inputYellow, predict[0], predict[1], width, height);
            
            return false;
        }
    }

    private static int[] remindCarpetInfo(int brown, int yellow) throws IOException{
        int width;
        int height = 3;

        while (true) {
            width = (brown - 2*height + 4) / 2;

            if (width * height == (brown + yellow)) return new int[] {width, height};
            
            height++;
            if (width < height) throw new IOException("답을 찾을 수 없습니다. 입력값을 다시 확인해주세요.");
        }
    }
}
