/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rnumgen;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Student
 */
public class RNUMGEN {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Random rgen = new Random();
        
        Scanner input = new Scanner(System.in);
        
        System.out.println("RANDOMGEN");
        System.out.println("Enter your choice : ");
        System.out.println("1.Coin\t2.Dice\t3.Card");
        int choice = input.nextInt();
        switch(choice) {
            case 1: {
                System.out.println("How many times do you want to flip a coin ? : ");
                int N = input.nextInt();
                System.out.print("[ ");
                int count = 0;
                for (int i = 0 ; i < N ; i++) {
                    int val = rgen.nextInt(2);
                    if (val == 0)
                        count++;
                    System.out.print( val + ", ");
                }
                System.out.print("\b]");
                System.out.println("\nCOUNT 0 : " + count + " , 1 : " + (N-count) );
                break;
            }
            case 2: {
                int []count = new int[7];
                System.out.println("How many times do you want to roll a dice ? : ");
                int N = input.nextInt();
                System.out.print("[ ");
                for (int i = 0 ; i < N ; i++) {
                    int val = (rgen.nextInt(6)+1);
                    count[val]++;
                    System.out.print( val + ", ");
                }
                System.out.print("\b]\nCOUNTS: \n");
                System.out.print("[ ");
                int j = 0;
                for (int e : count) {
                    System.out.print(j + " : " + e + ", ");
                    j++;
                }
                System.out.print("\b]\nCOUNTS: \n");
                break;
            }
            case 3: {
                int []count = new int[53];
                System.out.println("How many card do you want ? : ");
                int N = input.nextInt();
                System.out.print("[ ");
                for (int i = 0 ; i < N ; i++) {
                    int val = (rgen.nextInt(52)+1);
                    count[val]++;
                    System.out.print( val + ", ");
                }
                System.out.print("\b]\nCOUNTS: \n");
                System.out.print("[ ");
                int j = 0;
                for (int e : count) {
                    System.out.print(j + " : " + e + ", ");
                    j++;
                }
                System.out.print("\b]\nCOUNTS: \n");
                break;
            }
        }
    }
    
}
