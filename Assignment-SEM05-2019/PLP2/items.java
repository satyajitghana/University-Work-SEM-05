/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package plpassigncorrect;
public class items {
    private String itemName;
    private Float iprice;
    private Float tprice;
    private Float gstadd;
    private Float gstsub;
    private Integer quantity;

    public items(String itemName, Float iprice, Integer quantity) {
        this.itemName = itemName;
        this.iprice = iprice;
        this.quantity = quantity; }
    public String getItemName() {
        return itemName; }
    public void setItemName(String itemName) {
        this.itemName = itemName;}
    public Float getTprice() {
        return tprice; }
    public void setTprice(Float tprice) {
        this.tprice = tprice; }
    public Float getIprice() {
        return iprice; }
     public void setIprice(Float iprice) {
        this.iprice = iprice; }
    public Integer getQuantity() {
        return quantity;}
    public void setQuantity(Integer quantity) {
        this.quantity = quantity;}
    public Float getGstadd() {
        return gstadd; }
    
    public void setGstadd(Float gstadd) {
        this.gstadd = gstadd; }
    public Float getGstsub() {
        return gstsub; }
     public void setGstsub(Float gstsub) {
        this.gstsub = gstsub;    }
    public void total() {
        this.tprice = quantity * iprice;  }
    public float calculateGstAdd(Float gst) {
        return this.gstadd = (tprice * gst) / 100;  }
  public float calculateGstSub(Float gst) {
        float part = 100 / (100 + gst);
        return this.gstadd = tprice - (tprice * part);  }}
