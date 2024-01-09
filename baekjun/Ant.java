import java.util.Scanner;

public class Ant {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int W = sc.nextInt();
        final int H = sc.nextInt();
        int p = sc.nextInt();
        int q = sc.nextInt();
        int T = sc.nextInt();
        sc.close();

        int currentX = (p+T) % (2*W);
        if (currentX > W) {
            currentX = 2*W - currentX;
        }

        int currentY = (q+T) % (2*H);
        if (currentY > H) {
            currentY = 2*H - currentY;
        }

        System.out.println(currentX + " " + currentY);
    }
}
