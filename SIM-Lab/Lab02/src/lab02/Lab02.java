/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab02;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.OptionalDouble;
import java.util.Random;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 *
 * @author shadowleaf
 */
public class Lab02 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the Number of Requests : ");
        Integer N = input.nextInt();

        Random rand = new Random();
        
        // Taking it as input
//        List<Integer> IAT = new ArrayList<>();
//        List<Integer> ST = new ArrayList<>();
//        IAT.add(0);
//        ST.add(0);
//        
//        System.out.print("Enter IAT's : ");
//        for (int i = 0 ; i < N ; i++) {
//            IAT.add(input.nextInt());
//        }
//        
//        System.out.print("Enter ST's : ");
//        for (int i = 0 ; i < N ; i++) {
//            ST.add(input.nextInt());
//        }

        // Inter Arrival Times range from 1 - 8 mins
        List<Integer> IAT = IntStream.range(0, N + 1).mapToObj(i -> rand.nextInt(8) + 1).collect(Collectors.toList());
        // Service Time ranges from 1 - 6 mins
        List<Integer> ST = IntStream.range(0, N + 1).mapToObj(i -> rand.nextInt(6) + 1).collect(Collectors.toList());

        Map<String, List<Integer>> SIM_TAB = new HashMap<>();

        SIM_TAB.put("IAT", IAT);
        SIM_TAB.put("ST", ST);
        SIM_TAB.put("SS", new ArrayList<>(Collections.nCopies(N + 1, 0)));
        SIM_TAB.put("AT", new ArrayList<>(Collections.nCopies(N + 1, 0)));
        SIM_TAB.put("SE", new ArrayList<>(Collections.nCopies(N + 1, 0)));
        SIM_TAB.put("WAIT", new ArrayList<>(Collections.nCopies(N + 1, 0)));
        SIM_TAB.put("IDLE", new ArrayList<>(Collections.nCopies(N + 1, 0)));

        SIM_TAB.get("AT").set(0, 0);
        for (int i = 1; i <= N; i++) {
            SIM_TAB.get("AT").set(i, SIM_TAB.get("AT").get(i - 1) + SIM_TAB.get("IAT").get(i));
            if (SIM_TAB.get("AT").get(i) >= SIM_TAB.get("SE").get(i - 1)) {
                SIM_TAB.get("SS").set(i, SIM_TAB.get("AT").get(i));
            } else {
                SIM_TAB.get("SS").set(i, SIM_TAB.get("SE").get(i - 1));
            }

            SIM_TAB.get("SE").set(i, SIM_TAB.get("SS").get(i) + SIM_TAB.get("ST").get(i));
            
            SIM_TAB.get("WAIT").set(i, SIM_TAB.get("SS").get(i) - SIM_TAB.get("AT").get(i));
            
            SIM_TAB.get("IDLE").set(i, SIM_TAB.get("AT").get(i) - SIM_TAB.get("SE").get(i-1) >= 0 ? SIM_TAB.get("AT").get(i) - SIM_TAB.get("SE").get(i-1) : 0);
        }

        System.out.println("REQNO\tIAT\tAT\tSS\tSE\tST\tWAIT\tIDLE");
        for (int i = 1; i <= N; i++) {
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
        System.out.println("Average WAIT : " + avgWAIT.getAsDouble());
        System.out.println("Averate Service Time : " + avgService.getAsDouble());
        System.out.println("Averate IAT : " + avgIAT.getAsDouble());
    }

}
