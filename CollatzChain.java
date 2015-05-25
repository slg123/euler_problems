public class CollatzChain {
    public static void main(String[] args) {
        long end = 0;
        long tmp = 0;
        for (int i = 1000001; i > 2; i--) {
            long chain = 0;
            long n = i; 
            while (n != 1) {
                n = n%2==0 ? n/2 : n*3+1; 
                chain++;
            }
            if (chain > tmp) {
                tmp = chain; 
                end = i;
            }
        }
        System.out.println(end); 
        System.out.println(tmp); 
    }
}
