import java.util.*;

class Bank
{

    public SavingsAccount addAccount(String name,int interest_rate,int balance)
    {
      SavingsAccount ac=new SavingsAccount(name,interest_rate,balance);
      return ac;
    }

    public void printAccounts(SavingsAccount[] accounts,int length)
    {
      for(int i=0;i<length;i++)
      {
        accounts[i].addInterest();
        System.out.println("Owner: "+accounts[i].getName()+" Balance: "+accounts[i].getBalance());
      }
    }

    public static void main(String[] args)
    {
      Bank b=new Bank();
      SavingsAccount[] accounts=new SavingsAccount[10];
      Scanner sc=new Scanner(System.in);
      String myString=sc.nextLine();
      //System.out.println(myString);
      String[] arr_str=myString.split(" ");
      String op=arr_str[0];

      int i=0;

      while(!op.equals("X"))
      {
        if(op.equals("N"))
        {
          //System.out.println("Came in!");
          SavingsAccount acc=b.addAccount(arr_str[1],Integer.parseInt(arr_str[2]),Integer.parseInt(arr_str[3]));
          accounts[i++]=acc;
        }
        if(op.equals("W"))
          accounts[i-1].withdraw(Integer.parseInt(arr_str[1]));
        if(op.equals("D"))
          accounts[i-1].deposit(Integer.parseInt(arr_str[1]));

        myString=sc.nextLine();
        arr_str=myString.split(" ");
        op=arr_str[0];
      }
      b.printAccounts(accounts,i);
    }


}
