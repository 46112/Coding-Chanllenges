import java.lang.RuntimeException;

public class IncorrectSolutionException extends RuntimeException {
    private Object userSolution;
    private Object correctSolution;

    public IncorrectSolutionException(Object userSolution, Object correctSolution) {
        super("Incorrect solution: Expected " + correctSolution + ", but got " + userSolution);
        this.userSolution = userSolution;
        this.correctSolution = correctSolution;
    }

    public Object getUserSolution() {
        return userSolution;
    }

    public Object getCorrectSolution() {
        return correctSolution;
    }
}
