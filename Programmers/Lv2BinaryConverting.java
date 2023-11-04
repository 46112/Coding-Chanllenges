class Solution {
    public static void main(String[] args)
    {
        String binaryString = "0111010";
        String goal = "1";

        int tryCount = 0;
        int zeroCount = 0;

        while (!binaryString.equals(goal)) {
            int initalLength = binaryString.length();

            String removeZero = binaryString.replaceAll("0", "");
            int decimal = removeZero.length();

            zeroCount += (initalLength - decimal);

            binaryString = Integer.toBinaryString(decimal);
            tryCount += 1;
        }

        int[] answer = {tryCount, zeroCount};
        System.out.println(answer);
    }
}