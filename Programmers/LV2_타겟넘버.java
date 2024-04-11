class 타겟넘버 {
    public static int solution(int[] numbers, int target) {
        class DFS {
            int answer = 0;

            void search(int currentSum, int currentDepth) {
                if (currentDepth == numbers.length) {
                    if (currentSum == target) answer++;
                    return;
                }
                search(currentSum + numbers[currentDepth], currentDepth + 1);
                search(currentSum - numbers[currentDepth], currentDepth + 1);
            }
        }

        // 내부 DFS 객체 생성 및 호출
        DFS dfs = new DFS();
        dfs.search(0, 0);

        // 내부 DFS 객체의 answer 값 반환
        return dfs.answer;
    }

    public static void main(String[] args) {
        int[] firstTestCaseNumbers = {1,1,1,1,1};
        int firstTestCaseTarget = 3;
        int firstTestCaseSysAnswer = 5;
        int firstTestCaseUserAnswer = solution(firstTestCaseNumbers, firstTestCaseTarget);
        validate(firstTestCaseSysAnswer, firstTestCaseUserAnswer);

        int[] secondTestCaseNumbers = {4,1,2,1};
        int secondTestCaseTarget = 4;
        int secondTestCaseSysAnswer = 2;
        int secondTestCaseUserAnswer = solution(secondTestCaseNumbers, secondTestCaseTarget);
        validate(secondTestCaseSysAnswer, secondTestCaseUserAnswer);
    }

    private static void validate(int sysAnswer, int userAnswer) {
        boolean passOrNot = (sysAnswer == userAnswer);
        
        if (passOrNot) System.out.println("통과!");
        else {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("실패! : ").append(userAnswer + "이 아닌 ").append(sysAnswer + "입니다 :)");
            System.out.println(stringBuilder.toString());
        }
    }
}