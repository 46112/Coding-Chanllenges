import java.util.HashMap;
import java.util.Map;

public class LV2_Fibonacci {
    public static void main(String[] args){
        System.out.println(solution(3)); // expected: 2
        System.out.println(5); // expected: 5
    }

    private static int solution(int n){
        previousCalc.put(0, 0);
        previousCalc.put(1, 1);

        return fibonacci(n)%1234567;
    }
    static Map<Integer, Integer> previousCalc = new HashMap<Integer,Integer>();

    private static int fibonacci(int n){

        if (previousCalc.containsKey(n)) return previousCalc.get(n);
        else {
            Integer result = (fibonacci(n-1) + fibonacci(n-2))%1234567;
            if (!previousCalc.containsKey(result)) {
                previousCalc.put(n, result);
            }
            return result;
        }
    }
}
