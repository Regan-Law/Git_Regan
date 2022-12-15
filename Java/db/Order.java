package db;

public class Order {
    String Co_id;
    String C_id;
    String C_name;
    String C_address;
    String C_pho;
    Float Total;
    String Food_name;
    Float Food_price;
    int Food_num;
    Food food;
    Customer customer;
    public Order(Float Total) {
        this.Total = Total;
    }
    public Order(String Co_id,String C_id, String C_name, String C_address, String C_pho,Float Total,Customer customer) {
        this.Co_id = Co_id;
        this.C_id = C_id;
        this.C_name = C_name;
        this.C_address = C_address;
        this.C_pho = C_pho;
        this.Total= Total;
        this.customer = customer;
    }
    public Order(String Food_name, Float Food_price,int Food_num,String Co_id,Food food) {
        this.Food_name = Food_name;
        this.Food_price = Food_price;
        this.Food_num = Food_num;
        this.Co_id = Co_id;
        this.food=food;
    }
    public String getCo_id() {
        return Co_id;
    }
    public void setCo_id(String Co_id) {
        this.Co_id = Co_id;
    }
    public String getC_id() {
        return C_id;
    }
    public void setC_id(String C_id) {
        this.C_id = C_id;
    }
    public String getC_name() {
        return C_name;
    }
    public void setC_name(String C_name) {
        this.C_name = C_name;
    }
    public String getC_address() {
        return C_address;
    }
    public void setC_address(String C_address) {
        this.C_address = C_address;
    }
    public String getC_pho() {
        return C_pho;
    }
    public void setC_pho(String C_address) {
        this.C_address= C_address;
    }
    public Float getTotal() {
        return Total;
    }
    public void setTotal(Float Total) {
        this.Total= Total;
    }
    public Customer getcustomer() {
        return customer;
    }
    public void setcustomer(Customer customer) {
        this.customer= customer;
    }
    public String getFood_name() {
        return this.Food_name;
    }
    public void setFood_name(String food_name) {
        this.Food_name = food_name;
    }
    public Float getFood_price() {
        return Food_price;
    }
    public void setFood_price(Float food_price) {
        this.Food_price = food_price;
    }
    public int getFood_num() {
        return Food_num;
    }
    public void setFood_num(int food_num) {
        this.Food_num = food_num;
    }
    public Food getfood() {
        return food;
    }
    public void setfood(Food food) {
        this.food = food;
    }
}
