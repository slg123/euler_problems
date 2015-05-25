public class CollatzChain {
    public static void main(String[] args) {
        long end = 0;
        long tmp = 0;
        for (int i = 1000000; i > 0; i--) {
            long chain = 0;
            long n = i; 
            while (n != 1) {
                if (n%2 == 0 ){
                    n = n/2;
                    chain++;
                } else {
                    n = (n*3) + 1;
                    chain++; 
                }
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
