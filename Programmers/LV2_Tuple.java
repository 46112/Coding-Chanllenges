import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Stream;

import error.IncorrectSolutionException;

public class LV2_Tuple {
    public static void main(String[] args) {
        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                String s = parts[0];
                String[] stringOfResult = parts[1].substring(1, parts[1].length()-1).split(",");
                int[] result = Stream.of(stringOfResult).mapToInt(Integer::parseInt).toArray();
                
                int[] myAnswer = solution(s);
                if(!Arrays.equals(myAnswer, result)) {scanner.close(); throw new IncorrectSolutionException(myAnswer, result);}
            }
            scanner.close();
            System.out.println("통과!");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IncorrectSolutionException e) {
            System.out.println("땡!");
            System.err.println(e.getMessage());
        } catch (Exception e) {
            System.out.println(e.getMessage());
            System.out.println("예외 처리 똑바로 안해???");
        }
    }

    public static int[] solution(String s) {
        String[] tupleHints = s.substring(2,s.length()-2).split("\\},\\{");
        Arrays.sort(tupleHints, (String s1, String s2) -> s1.length() - s2.length());
        ArrayList<String> answer = new ArrayList<>();

        for (String hint : tupleHints) {
            String[] numbers = hint.split(",");
            for (String num : numbers) {
                if (!answer.contains(num)) answer.add(num);
            }
        }
        return Stream.of(answer.toArray(new String[answer.size()])).mapToInt(Integer::parseInt).toArray();        
    }

    /*
    
    {{1,2,3},{2,1},{1,2,4,3},{2}} [2,1,3,4]

    1,2,3},{2,1},{1,2,4,3},{2
    1,2,3 / 2,1 / 1,2,4,3 / 2
    2 / 2,1 / 1,2,3 / 1,2,4,3

    [2]
    [2,1]
    [2,1,3]
    [2,1,3,4]

     */
}
