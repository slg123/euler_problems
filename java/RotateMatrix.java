public class RotateMatrix {

    public static int[][] ar = {{  0,  1,  2,  3 },
                                {  4,  5,  6,  7 },
                                {  8,  9, 10, 11 },
                                { 12, 13, 14, 15 }};

    public static int[][] newar = new int[4][4];

    public static void main(String[] args) {
        display();
        rotate();
        display_new(); 
    }

    public static void display() {
        int i, j;
        for (i=0; i<=3; i++) {
            for (j=0; j<=3; j++) {
                System.out.print(ar[i][j] + " "); 
            }
            System.out.println(); 
        }
        System.out.println(); 
    }

    public static void display_new() {
        int i, j;
        for (i=0; i<=3; i++) {
            for (j=0; j<=3; j++) {
                System.out.print(newar[i][j] + " "); 
            }
            System.out.println(); 
        }
        System.out.println(); 
    }

    public static void rotate() {
        int i, j, s;
        for (i=0; i<=3; i++) {
            for (j=0, s=3; j<=3 && s>=0; j++, s--) {
                newar[i][j] = ar[s][i];
            }
        }
    }
}
