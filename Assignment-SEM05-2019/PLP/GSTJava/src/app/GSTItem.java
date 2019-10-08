package app;

/**
 * GSTItem
 */
public class GSTItem {
    private int item_id;
    private int gst_slab_id;
    private double price;

    GSTItem(int item_id, int gst_slab_id, double price) {
        this.item_id = item_id;
        this.gst_slab_id = gst_slab_id;
        this.price = price;
    }

    public static float slab_tax[] = { 0.0f, 0.05f, 0.12f, 0.18f, 0.28f };

    public double get_mrp() {
        return this.price + slab_tax[this.gst_slab_id] * this.price;
    }
}