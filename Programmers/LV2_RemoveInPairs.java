import java.util.Stack;

public class LV2_RemoveInPairs {

    public static void main(String args[]) {
        System.out.println(removeDuplication("baabaa"));
    }

    private static int removeDuplication(String word) {

        Stack<Character> stack = new Stack<>();
        for (Character c : word.toCharArray()) {
            if (!stack.isEmpty() && stack.peek()==c) {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        return stack.isEmpty() ? 1 : 0;
    }
}
