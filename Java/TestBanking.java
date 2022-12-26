/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:52:06
 * @FilePath: \\Git_Regan\\Java\\TestBanking.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
import java.util.*;

class Account {
    double balance;

    public double getBalance() {
        return balance;
    }

    public Account(double balance) {
        this.balance = balance;
    }

    public boolean deposit(double amount) {
        balance += amount;
        return true;
    }

    public boolean withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else
            return false;
    }
}

class Customer {
    String name;
    ArrayList accounts = new ArrayList();

    public Customer(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public Account getAccount(int index) {
        return (Account) (accounts.get(index - 1));
    }

    public ArrayList getAllAccount() {
        return accounts;
    }
}

class Bank {
    private HashMap customers;
    private int custNum;

    public Bank() {
        customers = new HashMap();
        custNum = 0;
    }

    public void addCustomer(Customer customer) {
        customers.put(new Integer(custNum + 1), customer);
        custNum++;
    }

    public Customer getCustomer(int index) {
        if (index >= 1 && index <= custNum)
            return (Customer) (customers.get(new Integer(index)));
        else
            return null;
    }

    public HashMap getAllCustomer() {
        return customers;
    }

    public int getCustomerNum() {
        return custNum;
    }
}

class SavingAccount extends Account {
    private double rate;

    public SavingAccount(double balance, double rate) {
        super(balance);
        this.rate = rate;
    }
}

class CheckingAccount extends Account {
    private double overdraft;

    public CheckingAccount(double balance, double overdraft) {
        super(balance);
        this.overdraft = overdraft;
    }

    public CheckingAccount(double balance) {
        this(balance, 0.0);
    }

    public boolean withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else if (amount <= balance + overdraft) {
            overdraft -= (amount - balance);
            balance = 0;
            return true;
        } else
            return false;
    }

    public double getOverdraft() {
        return overdraft;
    }
}

public class TestBanking {
    public static void main(String args[]) {
        Bank bank = new Bank();
        bank.addCustomer(new Customer("小明"));
        bank.addCustomer(new Customer("小张"));
        Customer cust1 = bank.getCustomer(1);
        Customer cust2 = bank.getCustomer(2);
        cust1.addAccount(new SavingAccount(10000.0, 2.1));
        cust1.addAccount(new CheckingAccount(10000.0, 10000.0));
        cust2.addAccount(new CheckingAccount(10000.0, 5000.0));
        Account acc1 = cust1.getAccount(1);
        System.out.println(cust1.getName() + "的1号账户余额是\t" + acc1.getBalance());
        acc1.deposit(1000.0);
        System.out.println(cust1.getName() + "的1号账户余额是\t" + acc1.getBalance());
        acc1.withdraw(20000.0);
        System.out.println(cust1.getName() + "的1号账户余额是\t" + acc1.getBalance());
        acc1.withdraw(10000.0);
        System.out.println(cust1.getName() + "的1号账户余额是\t" + acc1.getBalance());
        CheckingAccount acc2 = (CheckingAccount) cust1.getAccount(2);
        System.out.println(cust1.getName() + "的2号账户余额是\t" + acc2.getBalance() + "\t透支金额是:\t" + acc2.getOverdraft());
        acc2.deposit(1000.0);
        System.out.println(cust1.getName() + "的2号账户余额是\t" + acc2.getBalance() + "\t透支金额是:\t" + acc2.getOverdraft());
        acc2.withdraw(20000.0);
        System.out.println(cust1.getName() + "的2号账户余额是\t" + acc2.getBalance() + "\t透支金额是:\t" + acc2.getOverdraft());
        acc2.withdraw(3000.0);
        System.out.println(cust1.getName() + "的2号账户余额是\t" + acc2.getBalance() + "\t透支金额是:\t" + acc2.getOverdraft());
        acc2.withdraw(10000.0);
        System.out.println(cust2.getName() + "的2号账户余额是\t" + acc2.getBalance() + "\t透支金额是:\t" + acc2.getOverdraft());
        CheckingAccount acc3 = (CheckingAccount) cust2.getAccount(1);
        System.out.println(cust2.getName() + "的账户余额是\t" + acc3.getBalance() + "\t透支金额是:\t" + acc3.getOverdraft());
        acc3.deposit(1000.0);
        System.out.println(cust2.getName() + "的账户余额是\t" + acc3.getBalance() + "\t透支金额是:\t" + acc3.getOverdraft());
        acc3.withdraw(20000.0);
        System.out.println(cust2.getName() + "的账户余额是\t" + acc3.getBalance() + "\t透支金额是:\t" + acc3.getOverdraft());
        acc3.withdraw(3000.0);
        System.out.println(cust2.getName() + "的账户余额是\t" + acc3.getBalance() + "\t透支金额是:\t" + acc3.getOverdraft());
        acc3.withdraw(10000.0);
        System.out.println(cust2.getName() + "的账户余额是\t" + acc3.getBalance() + "\t透支金额是:\t" + acc3.getOverdraft());
    }
}