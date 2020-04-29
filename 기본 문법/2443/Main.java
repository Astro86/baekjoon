import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n - 1; j++)
                System.out.print(' ');
            for (int j = 0; j < 2 * i + 1; j++)
                System.out.print('*');
            System.out.println();
        }

        sc.close();
    }
}