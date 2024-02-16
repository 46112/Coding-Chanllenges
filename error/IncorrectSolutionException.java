package error;

import java.lang.RuntimeException;
import java.util.Arrays;

public class IncorrectSolutionException extends RuntimeException {
    private Object userSolution;
    private Object correctSolution;

    public IncorrectSolutionException(Object userSolution, Object correctSolution) {
        super("Incorrect solution: Expected " + toString(correctSolution) + ", but got " + toString(userSolution));
        this.userSolution = userSolution;
        this.correctSolution = correctSolution;
    }

    public Object getUserSolution() {
        return userSolution;
    }

    public Object getCorrectSolution() {
        return correctSolution;
    }

    private static String toString(Object obj) {
        if (obj == null) {
            return "null";
        } else if (obj instanceof int[]) {
            return Arrays.toString((int[]) obj);
        } else if (obj.getClass().isArray()) {
            return Arrays.deepToString((Object[]) obj);
        } else {
            return obj.toString();
        }
    }
}
