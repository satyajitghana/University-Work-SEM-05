/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atm_sim;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.OptionalDouble;
import java.util.Scanner;

/**
 *
 * @author shadowleaf
 */
public class ATM_SIM {
    


    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the total time to simulate for (minutes) : ");
        Integer T = input.nextInt();

        // seed the random number generator with the current system time in milli-seconds
        BromineRandom rand = new BromineRandom(System.currentTimeMillis());

        // map to store the simulation table
        Map<String, List<Integer>> SIM_TAB = new HashMap<>();
        
        List<Integer> IAT = new ArrayList<>();
        List<Integer> ST = new ArrayList<>();

        // initialize the simulation table
        SIM_TAB.put("IAT", IAT);
        SIM_TAB.put("ST", ST);
        SIM_TAB.put("SS", new ArrayList<>(Collections.nCopies(1, 0)));
        SIM_TAB.put("AT", new ArrayList<>(Collections.nCopies(1, 0)));
        SIM_TAB.put("SE", new ArrayList<>(Collections.nCopies(1, 0)));
        SIM_TAB.put("WAIT", new ArrayList<>(Collections.nCopies(1, 0)));
        SIM_TAB.put("IDLE", new ArrayList<>(Collections.nCopies(1, 0)));

        // start the simulatioin
        Integer SYS_CLOCK = 0;
        SIM_TAB.get("IAT").add(rand.nextInt(4)+1);
        SIM_TAB.get("ST").add(rand.nextInt(6)+1);
        
        SIM_TAB.get("AT").set(0, 0);
        for (int i = 1; SYS_CLOCK <= T ; i++) {
            // IAT b/w 1-4 mins
            SIM_TAB.get("IAT").add(rand.nextInt(4)+1);
            // ST b/w 1-6 mins
            SIM_TAB.get("ST").add(rand.nextInt(6)+1);
                        
            SIM_TAB.get("AT").add(SIM_TAB.get("AT").get(i - 1) + SIM_TAB.get("IAT").get(i));
            if (SIM_TAB.get("AT").get(i) >= SIM_TAB.get("SE").get(i - 1)) {
                SIM_TAB.get("SS").add(SIM_TAB.get("AT").get(i));
            } else {
                SIM_TAB.get("SS").add(SIM_TAB.get("SE").get(i - 1));
            }

            SIM_TAB.get("SE").add(SIM_TAB.get("SS").get(i) + SIM_TAB.get("ST").get(i));
            
            SIM_TAB.get("WAIT").add(SIM_TAB.get("SS").get(i) - SIM_TAB.get("AT").get(i));
            
            SIM_TAB.get("IDLE").add(SIM_TAB.get("AT").get(i) - SIM_TAB.get("SE").get(i-1) >= 0 ? SIM_TAB.get("AT").get(i) - SIM_TAB.get("SE").get(i-1) : 0);
            
            // set the sys_time
            SYS_CLOCK = SIM_TAB.get("SE").get(i) + SIM_TAB.get("ST").get(i);
                        
        }

        // Print the simulation table
        System.out.println("REQNO\tIAT\tAT\tSS\tSE\tST\tWAIT\tIDLE");
        for (int i = 1; i < SIM_TAB.get("IAT").size(); i++) {
            String out = i + "\t"
                    + SIM_TAB.get("IAT").get(i) + "\t"
                    + SIM_TAB.get("AT").get(i) + "\t"
                    + SIM_TAB.get("SS").get(i) + "\t"
                    + SIM_TAB.get("SE").get(i) + "\t"
                    + SIM_TAB.get("ST").get(i) + "\t"
                    + SIM_TAB.get("WAIT").get(i) + "\t"
                    + SIM_TAB.get("IDLE").get(i);
            System.out.println(out);
        }
        
        // Avg WAIT, Avg. Ser, Avg. IAT
        OptionalDouble avgWAIT = SIM_TAB.get("WAIT").stream().mapToDouble(a -> a).average();
        OptionalDouble avgService = SIM_TAB.get("ST").stream().mapToDouble(a -> a).average();
        OptionalDouble avgIAT = SIM_TAB.get("IAT").stream().mapToDouble(e -> e).average();
        System.out.println("Total Requests Processed : " + (SIM_TAB.get("IAT").size()-1));
        System.out.println("Average WAIT : " + avgWAIT.getAsDouble());
        System.out.println("Averate Service Time : " + avgService.getAsDouble());
        System.out.println("Averate IAT : " + avgIAT.getAsDouble());
    }
    
}
