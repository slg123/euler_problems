import java.util.*;

public class Gravitation {

    public static final HashMap<String, Double> planet_SolarDistance = new HashMap<String, Double>(); 
    public static final HashMap<String, Double> planet_Mass = new HashMap<String, Double>(); 

    public static void main(String[] args) {

        planet_SolarDistance.put("Mercury", 57.9);
        planet_SolarDistance.put("Venus", 108.2);
        planet_SolarDistance.put("Earth", 149.6);
        planet_SolarDistance.put("Mars", 227.9);
        planet_SolarDistance.put("Jupiter", 778.6);
        planet_SolarDistance.put("Saturn", 1433.5);
        planet_SolarDistance.put("Uranus", 2872.5);
        planet_SolarDistance.put("Neptune", 4495.1);
        planet_SolarDistance.put("Pluto", 5906.4);

        planet_Mass.put("Mercury", 0.33);
        planet_Mass.put("Venus", 4.87);
        planet_Mass.put("Earth", 5.97);
        planet_Mass.put("Mars", 0.642);
        planet_Mass.put("Jupiter", 1898.0);
        planet_Mass.put("Saturn", 568.0);
        planet_Mass.put("Uranus", 86.8);
        planet_Mass.put("Neptune", 102.0);
        planet_Mass.put("Pluto", 0.0146);

        double gEarth = getGravity("Earth"); 
        System.out.println("\nEarth gravity: " + gEarth + "\n"); 

        for (String key : planet_Mass.keySet()) {
            double g = getGravity(key);
            System.out.println(key + " gravity = " + g); 
        }

        printMap(planet_Mass); 

    }

    public static final void printMap(Map mp) {
        Iterator it = mp.entrySet().iterator(); 
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry)it.next();
            System.out.println(pair.getKey() + " = " + pair.getValue());
            it.remove();
        }
    }

    public static double getGravity(String planet) {
        double G = 6.67300E-11;  // Gravitational constant
        double M = 1988500.0;    // Mass of the Sun
        double d = planet_SolarDistance.get(planet); 
        double m = planet_Mass.get(planet); 
        return (G * (M * m)) / (d * d);
    }
}


