class NumExpress {

    public static void main(String[] args) {
        System.out.println(solution(15));
    }

    public static int solution(int n) {
        int answer = 1; // n 자기 자신 포함하고 시작
        int start = 1; // 시작 포인터
        int end = 1; // 끝 포인터
        int sum = 1; // 현재 합

        // sum은 start부터 end까지의 합
        while (start <= n / 2) {
            if (sum == n) {
                answer++;
                sum -= start;
                start++;
            } else if (sum > n) {
                sum -= start;
                start++;
            } else {
                end++;
                sum += end;
            }
        }
        return answer;
    }
}