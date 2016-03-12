public class Trapezoidal {

    public static int max_in = 501;
    public static double vmin = 0.0;
    public static double vmax = 1.0;
    public static double ME = 2.7182818284590453454E0;

    public static void main(String[] args) {

        double result;

        int i;
        for (i=3; i<= max_in; i+=2) {
            result = trapez(i, vmin, vmax);
            System.out.printf("%d\t%e\t\n", i, Math.abs(result-1+1/ME)); 
        } 

    }
    
    public static double f(double x) {
        return Math.exp(-x); 
    }

    public static double trapez(int no, double min, double max) {
        int n;
        double interval;
        double sum = 0.0;
        double x;

        interval = ((max-min) / (no-1));
        for (n=2; n<no; n++) {
            x = interval * (n-1);
            sum += f(x)*interval;
        }
        sum += 0.5 * (f(min) + f(max)) * interval;

        return sum;
    }
}
