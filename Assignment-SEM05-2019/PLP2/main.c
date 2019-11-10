/* File:   main.c
 * Author: DELL
 * Created on 9 November, 2019, 11:15 AM */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Samhitha R - 17ETCS002156
int main(int argc, char** argv) {
    int qty, i,c, choice,n;
    n = 1000000;
    float itemCost, totalCost, gstadd, gstsub, npriceadd, npricesub;
            float gst[] = {0, 5, 12, 18, 28};
    char itemName[20];
    float total = 0.0f;
    // printf("\t\tGST CALCULATOR\n");
    // printf("--------------------------------------------------\n");
    while(n--){
    // printf("Enter The Item Name:\t");
    // scanf("%s", &itemName);
    // itemName[0] = "";
    // printf("Enter The Item Cost:\t");
    // scanf("%f", &itemCost);
    itemCost = (float)(n %1000);
    // printf("Enter The Quantity:\t");
    // scanf("%d", &qty);
    qty = i % 5;
    totalCost = itemCost * qty;
    total += totalCost;
    // printf("--------------------------------------------------\n");
    // printf("Name\t\tPrice\t\tQty\tTotal\n");
    // printf("--------------------------------------------------\n");
    // printf("%s\t\t", itemName);
    // printf("%.2f\t\t%d\t%.2f\n", itemCost, qty, totalCost);
    // printf("------------------------------------------------------------------------\n");
    // printf("GST Slabs\tGST for Add\tCost+GST\tGST for Sub\tCost-GST\n");
    // printf("------------------------------------------------------------------------\n");
    for (i = 0; i < 5; i++)
    {
        gstadd = (totalCost * gst[i]) / 100;
        npriceadd = totalCost + gstadd;
        float part = 100 / (100 + gst[i]);
        gstsub = totalCost - (totalCost * part);
        npricesub = totalCost - gstsub;
        // printf("%.0f\t\t %.2f \t\t %.2f \t\t %.2f \t\t %.2f \n", gst[i], gstadd
        //         , npriceadd, gstsub, npricesub);
    }
    // printf("--------------------------------------------------------------------"
    //         "----\n");
    
    // printf("Enter 1 to add more items and any other number to exit");
    // scanf("%d",&c); 
}
printf("Total Price for %d items is %.10f\n", 1000000, total);
    return (EXIT_SUCCESS);
}

