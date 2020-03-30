class SavingsAccount
{
  private String name;
  private int interest_rate;
  private int balance;
  SavingsAccount(String iname,int iinterest_rate,int ibalance)
  {
    name=iname;
    interest_rate=iinterest_rate;
    balance=ibalance;
  }

  public int getBalance()
  {
    return balance;
  }

  public void deposit(int amount)
  {
    balance+=amount;
  }

  public void addInterest()
  {
    balance+=(balance*1*interest_rate/1200);
  }

  public void withdraw(int amount)
  {
    balance-=amount;
    if(balance<0)
      balance=0;
  }

  public String getName()
  {
    return name;
  }

  /*public static void main(String[] args)
  {
    SavingsAccount acc=new SavingsAccount("Newton",15,10000);
    acc.deposit(2000);
    acc.withdraw(10000);
    acc.addInterest();
    System.out.println("Account owned by "+acc.name+" has a balance of "+acc.balance);
  }*/
}
