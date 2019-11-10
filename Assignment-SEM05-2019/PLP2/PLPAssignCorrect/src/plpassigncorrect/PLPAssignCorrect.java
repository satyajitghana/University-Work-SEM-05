/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package plpassigncorrect;
import java.util.*;
/* @author DELL */ //Samhitha R
public class PLPAssignCorrect {
    public static void main(String[] args) {
        Integer i, N= 1000000;
        Integer[] qty = new Integer[N];
        Float[] itemCost = new Float[N],
                gstadd = new Float[N],
                gstsub = new Float[N],
                npriceadd = new Float[N],
                npricesub = new Float[N];
        Float[] gst = new Float[]{0f, 5f, 12f, 18f, 28f};
        String[] itemName = new String[N];
        Scanner s = new Scanner(System.in);
        System.out.print("\t\tGST CALCULATOR\n");
        // System.out.print("Enter The No. of Item:\t");
        // N = s.nextInt();
        // N = 1000000;
        items[] item = new items[N];
        Float total = 0.0f;
        for (i = 0; i < N; i++) {
            // System.out.print("--------------------------------------------------\n");
            // System.out.print("Enter The Item Name:\t");
            // itemName[i] = s.next();
            itemName[i] = "";
            // System.out.print("Enter The Item Cost:\t");
            // itemCost[i] = s.nextFloat();
            itemCost[i] = (float)(i % 1000);
            // System.out.print("Enter The Quantity:\t");
            // qty[i] = s.nextInt();
            qty[i] = i%5;
            item[i] = new items(itemName[i], itemCost[i], qty[i]);
            // System.out.print("--------------------------------------------------\n");
            // System.out.print("Name\t\tPrice\t\tQty\tTotal\n");
            item[i].total();
            // System.out.print("--------------------------------------------------\n");
            // System.out.format("%s\t\t%.2f\t\t%d\t%.2f\n", item[i].getItemName(), item[i].getIprice(), item[i].getQuantity(), item[i].getTprice());
            // System.out.print("------------------------------------------------------------------------\n");
            // System.out.print("GST Slabs\tGST for Add\tCost+GST\tGST for Sub\tCost-GST\n");
            // System.out.print("------------------------------------------------------------------------\n");
            for (int j = 0; j < 5; j++) {
                gstadd[i] = item[i].calculateGstAdd(gst[j]);
                npriceadd[i] = item[i].getTprice() + gstadd[i];
                gstsub[i] = item[i].calculateGstSub(gst[j]);
                npricesub[i] = item[i].getTprice() - gstsub[i];
                // System.out.format("%.0f%s\t\t %.2f \t\t %.2f \t\t %.2f \t\t %.2f \n", gst[j], "%", gstadd[i],
                //         npriceadd[i], gstsub[i], npricesub[i]);
            }
            // System.out.print("------------------------------------------------------------------------\n\n\n");
            total += npricesub[i];
        }
        System.out.printf("Total Price of %d items : %.10f\n", N, total);
    }
    
}
