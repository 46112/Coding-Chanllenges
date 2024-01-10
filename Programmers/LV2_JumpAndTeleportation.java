
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.lang.Math;
import error.IncorrectSolutionException;

public class LV2_JumpAndTeleportation {
    public static void main(String args[]){

        try {
            File file = new File("input.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                int N = scanner.nextInt();
                Integer result = scanner.nextInt();
                
                Integer myAnswer = solution(N);
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

    private static Integer solution(int N) {

        int batteryUsage = 0;
        int currentLocation = N; // 목적지부터 출발
        

        while (currentLocation!=0) {
            int halfLocation = Math.floorDiv(currentLocation, 2);
            int restDistance = Math.floorMod(currentLocation, 2);

            if (restDistance==0) currentLocation = halfLocation; // 2로 나누었을 때 남은 거리가 0 -> 짝수 -> 순간이동으로 한번에 도달가능
            else if (restDistance==1) { // 홀수N -> N-1까지는 한번에 도달가능, 1만큼 jump해야함.
                currentLocation = halfLocation;
                batteryUsage++;
            }
            else return -1;
        }

        return batteryUsage;
    }
}
