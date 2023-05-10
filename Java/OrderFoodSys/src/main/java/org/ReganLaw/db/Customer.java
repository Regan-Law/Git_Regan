package org.ReganLaw.db;

public class Customer{
    String C_id;
    String C_name;
    String C_passwd;
    String C_address;
    String C_pho;

    public Customer(String C_id,String C_name,String C_passwd,String C_address,String C_pho){
        this.C_id=C_id;
        this.C_name=C_name;
        this.C_passwd=C_passwd;
        this.C_address=C_address;
        this.C_pho=C_pho;
    }

    public String getC_id(){
        return C_id;
    }

    public void setC_id(String C_id){
        this.C_id=C_id;
    }

    public String getC_name(){
        return C_name;
    }

    public void setC_name(String C_name){
        this.C_name=C_name;
    }

    public String getC_passwd(){
        return C_passwd;
    }

    public void setC_passwd(String C_passwd){
        this.C_passwd=C_passwd;
    }

    public String getC_address(){
        return C_address;
    }

    public void setC_address(String C_address){
        this.C_address=C_address;
    }

    public String getC_phone(){
        return C_pho;
    }

    public void setC_phone(String C_pho){
        this.C_pho=C_pho;
    }
}