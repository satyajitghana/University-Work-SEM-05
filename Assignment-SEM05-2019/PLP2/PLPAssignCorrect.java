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
        Integer i, N;
        Integer[] qty = new Integer[100];
        Float[] itemCost = new Float[100],
                gstadd = new Float[100],
                gstsub = new Float[100],
                npriceadd = new Float[100],
                npricesub = new Float[100];
        Float[] gst = new Float[]{0f, 5f, 12f, 18f, 28f};
        String[] itemName = new String[100];
        Scanner s = new Scanner(System.in);
        System.out.print("\t\tGST CALCULATOR\n");
        System.out.print("Enter The No. of Item:\t");
        N = s.nextInt();
        items[] item = new items[N];
        for (i = 0; i < N; i++) {
            System.out.print("--------------------------------------------------\n");
            System.out.print("Enter The Item Name:\t");
            itemName[i] = s.next();
            System.out.print("Enter The Item Cost:\t");
            itemCost[i] = s.nextFloat();
            System.out.print("Enter The Quantity:\t");
            qty[i] = s.nextInt();
            item[i] = new items(itemName[i], itemCost[i], qty[i]);
            System.out.print("--------------------------------------------------\n");
            System.out.print("Name\t\tPrice\t\tQty\tTotal\n");
            item[i].total();
            System.out.print("--------------------------------------------------\n");
            System.out.format("%s\t\t%.2f\t\t%d\t%.2f\n", item[i].getItemName(), item[i].getIprice(), item[i].getQuantity(), item[i].getTprice());
            System.out.print("------------------------------------------------------------------------\n");
            System.out.print("GST Slabs\tGST for Add\tCost+GST\tGST for Sub\tCost-GST\n");
            System.out.print("------------------------------------------------------------------------\n");
            for (int j = 0; j < 5; j++) {
                gstadd[i] = item[i].calculateGstAdd(gst[j]);
                npriceadd[i] = item[i].getTprice() + gstadd[i];
                gstsub[i] = item[i].calculateGstSub(gst[j]);
                npricesub[i] = item[i].getTprice() - gstsub[i];
                System.out.format("%.0f%s\t\t %.2f \t\t %.2f \t\t %.2f \t\t %.2f \n", gst[j], "%", gstadd[i],
                        npriceadd[i], gstsub[i], npricesub[i]);
            }
            System.out.print("------------------------------------------------------------------------\n\n\n");
        }
    }
    
}
