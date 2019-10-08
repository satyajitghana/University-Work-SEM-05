package app;

import java.util.ArrayList;

public class App {

    public static int MAX_ITEMS = 100000;

    public static void main(String[] args) throws Exception {
        // testing
        ArrayList<GSTItem> list = new ArrayList<>();

        /**
         * A Single loop of 100000 objects, sequential access
         */
        for (int i = 0; i < MAX_ITEMS; i++) {
            int item_id = i;
            int gst_slab_id = i % 5;
            double price = 1000.5f;

            GSTItem item = new GSTItem(item_id, gst_slab_id, price);

            list.add(item);
        }

        double total_amt = 0.0f;

        // calculate the GST'ed price
        for (int i = 0; i < MAX_ITEMS; i++) {
            GSTItem item = list.get(i);
            total_amt += item.get_mrp();
        }

        System.out.printf("TOTAL_ITEMS : %d\nTOTAL_AMOUNT : %.10f\n", MAX_ITEMS, total_amt);
    }
}