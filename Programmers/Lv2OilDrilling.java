/* BFS 탐색
import java.util.Queue;
import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;

class OilDrilling{
    public static void main(String[] args) {
        int[][] land1 = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};
        int[][] land2 = {{1, 0, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}};

        System.out.println(solution(land1));  // 결과: 9
        System.out.println(solution(land2));  // 결과: 16
    }

    private static int solution(int[][] land) {
        int n = land.length;
        int m = land[0].length;
        int maxOil = 0;

        for (int col = 0; col < m; col++) {
            boolean[][] visited = new boolean[n][m]; // 다른 열 탐색 시에 방문 기록과 해당 열 석유량 초기화
            List<Integer> row_oils = new ArrayList<>();

            for (int row = 0; row < n; row++) {
                if (land[row][col] == 1) { // 석유가 존재할 경우에 BFS 탐색
                    Queue<int[]> queue = new LinkedList<>();
                    queue.offer(new int[]{row, col});
                    int oilAmount = 0;

                    while (!queue.isEmpty()) {
                        int[] current = queue.poll();
                        int currentRow = current[0];
                        int currentCol = current[1];

                        if (visited[currentRow][currentCol]) {
                            continue;
                        }
                        visited[currentRow][currentCol] = true;
                        oilAmount++;

                        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                        for (int[] dir : directions) {
                            int newRow = currentRow + dir[0];
                            int newCol = currentCol + dir[1];

                            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && land[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                                queue.offer(new int[]{newRow, newCol});
                            }
                        }
                    }
                    row_oils.add(oilAmount); // Q가 비워지면(더 이상 탐색할 곳이 없을 때) oilAmount를 추가
                }
            }
            maxOil = Math.max(maxOil, row_oils.stream().mapToInt(Integer::intValue).sum()); // 해당 열 탐색이 끝나면 석유량 비교
        }
        return maxOil;
    }
}
*/

/* DFS 탐색 
import java.util.List;
import java.util.ArrayList;

class OilDrilling{
    public static void main(String[] args) {
        int[][] land1 = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};
        int[][] land2 = {{1, 0, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}};

        System.out.println(solution(land1));  // 결과: 9
        System.out.println(solution(land2));  // 결과: 16
    }

    private static int solution(int[][] land) {
        int n = land.length;
        int m = land[0].length;
        int maxOil = 0;
        
        for (int col = 0; col < m; col++) {
            boolean[][] visited = new boolean[n][m];
            List<Integer> row_oils = new ArrayList<>();
            for (int row = 0; row < n; row++) {
                if (land[row][col] == 1) {
                    int oilAmount = dfs(land, row, col, visited);
                    row_oils.add(oilAmount);
                }
            }
            maxOil = Math.max(maxOil, row_oils.stream().mapToInt(Integer::intValue).sum());
        }
        return maxOil;
    }

    private static int dfs(int[][] land, int row, int col, boolean[][] visited) {
        int n = land.length;
        int m = land[0].length;

        if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || land[row][col] == 0) {
            return 0;
        }

        visited[row][col] = true;
        int oilAmount = 1; // 현재 위치의 석유량 추가

        // 사방 탐색
        oilAmount += dfs(land, row - 1, col, visited); // 상
        oilAmount += dfs(land, row + 1, col, visited); // 하
        oilAmount += dfs(land, row, col - 1, visited); // 좌
        oilAmount += dfs(land, row, col + 1, visited); // 우

        return oilAmount;
    }
}
*/

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

class OilDrilling {
    public static void main(String[] args) {
        int[][] land1 = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};
        int[][] land2 = {{1, 0, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}};

        System.out.println(solution(land1));  // 결과: 9
        System.out.println(solution(land2));  // 결과: 16
    }

    static int rSize, cSize;
    static int[][] fragments;
    static int fragmentIdx = 1;
    static Map<Integer, Integer> fragmentsInfo = new HashMap<>();
    static boolean[][] visited;
    static int[] dirR = {-1, 1, 0, 0};
    static int[] dirC = {0, 0, -1, 1};

    public static int solution(int[][] land) {
        int answer = 0;
        rSize = land.length;
        cSize = land[0].length;
        fragments = new int[rSize][cSize];
        visited = new boolean[rSize][cSize];

        for (int r = 0; r < rSize; r++) {
            for (int c = 0; c < cSize; c++) {
                if (visited[r][c] || land[r][c] == 0) {
                    continue;
                }

                bfs(land, r, c);
            }
        }

        for (int c = 0; c < cSize; c++) {
            Set<Integer> fragmentTypes = new HashSet<>();
            int tmpMaxAmount = 0;
            for (int r = 0; r < rSize; r++) {
                if (fragments[r][c] > 0) {
                    fragmentTypes.add(fragments[r][c]);
                }
            }

            for (Integer frg : fragmentTypes) {
                tmpMaxAmount += fragmentsInfo.get(frg);
            }

            answer = Math.max(answer, tmpMaxAmount);
        }

        return answer;
    }

    static void bfs(int[][] land, int r, int c) {
        visited[r][c] = true;
        fragments[r][c] = fragmentIdx;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r, c});
        int size = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            size++;

            for (int d = 0; d < 4; d++) {
                int nxtR = cur[0] + dirR[d];
                int nxtC = cur[1] + dirC[d];

                if (nxtR < 0 || nxtR >= rSize || nxtC < 0 || nxtC >= cSize || visited[nxtR][nxtC] || land[nxtR][nxtC] == 0) {
                    continue;
                }

                visited[nxtR][nxtC] = true;
                fragments[nxtR][nxtC] = fragmentIdx;
                q.add(new int[]{nxtR, nxtC});
            }
        }

        fragmentsInfo.put(fragmentIdx++, size);
    }
}