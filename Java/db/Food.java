package db;

public class Food {
    String F_name;
    Float F_price;
    public Food(String F_name, Float F_price) {
        this.F_name = F_name;
        this.F_price = F_price;
    }
    public String getF_name() {
        return F_name;
    }
    public void setF_name(String F_name) {
        this.F_name= F_name;
    }
    public float getF_price() {
        return F_price;
    }
    public void setF_price(Float F_price) {
        this.F_price= F_price;
    }
}
