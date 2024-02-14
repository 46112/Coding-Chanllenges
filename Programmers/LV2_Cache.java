import java.io.File;
import java.io.FileNotFoundException;

import java.util.LinkedList;
import java.util.Objects;
import java.util.Queue;
import java.util.Scanner;

import error.IncorrectSolutionException;

public class LV2_Cache {
    public static void main(String[] args) {
        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");

                Integer cacheSize = Integer.parseInt(parts[0].trim());
                String[] cities = parts[1].substring(1, parts[1].length()-1).split(",");
                
                Integer result = Integer.parseInt(parts[2].trim());
                
                Integer myAnswer = solution(cacheSize, cities);
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

    public static int solution(int cacheSize, String[] cities) {
        Queue<String> cacheMem = new LinkedList<>();
        int cacheHitCount = 0;
        int cacheMissCount = 0;

        for (String city : cities) {
            if (Objects.equals(cacheSize, 0)) return cities.length*5;
            if (cacheMem.remove(city.toLowerCase())) {//cache hit -> 삭제 후 다시 넣어줌
                cacheHitCount++;
                cacheMem.add(city.toLowerCase());
            }
            else {//cache miss -> LRU알고리즘
                cacheMissCount++;
                if (cacheMem.size() >= cacheSize) {
                    cacheMem.poll();
                    cacheMem.add(city.toLowerCase());
                }
                else cacheMem.add(city.toLowerCase());
            }
        }
        int answer = cacheHitCount*1 + cacheMissCount*5;
        return answer;
    }
}
