import java.util.*; 
import java.io.*; 
import java.math.*; 

public class Test {
    public static void main( String[] args ) {
        List<BigInteger> list = new ArrayList<BigInteger>();
        File file = new File("./bignums.txt");
        BufferedReader reader = null;

        try {
            reader = new BufferedReader(new FileReader(file)); 
            String text = null;

            while ((text = reader.readLine()) != null) {
                list.add(new BigInteger(text)); 
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace(); 
        } catch (IOException e) {
            e.printStackTrace(); 
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e) {
                System.out.println("Error.");
            }
        }
        BigInteger sum = BigInteger.valueOf(0);
        for (BigInteger n : list) {
            sum = sum.add(n);
        }

        String s = sum.toString(); 
        for (int i=0; i<10; i++) {
            char c = s.charAt(i);
            System.out.print(c); 
        }
        System.out.println(); 
    }
}
