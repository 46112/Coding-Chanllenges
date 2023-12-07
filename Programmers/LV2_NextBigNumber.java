public class LV2_NextBigNumber {
    public static void main(String[] args) {
        System.out.println(solution(78)); //83
        System.out.println(solution(15)); //23
    }
    
    private static int solution(int n) {

        int initCount = countBinaryOne(n);

        while (true) {
            int modifiedCount = countBinaryOne(++n);
            if (modifiedCount == initCount) break;
        }

        return n;
    }

    private static int countBinaryOne(int n) {
        // Long oneCount = Integer.toBinaryString(n).chars().filter(c -> c=='1').count();
        // return oneCount.intValue();
        return Integer.bitCount(n);
    }
}