import java.util.*;
import food_suppliers.*;

class Mainclass
{
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    String mystring=sc.nextLine();
    //System.out.println(mystring);
    String[] inp_str=mystring.split(" ");
    //System.out.println(Integer.parseInt(inp_str[0]));
    Store store1=new Store(Integer.parseInt(inp_str[0]),Integer.parseInt(inp_str[1]));
    mystring=sc.nextLine();
    //System.out.println(mystring);
    inp_str=mystring.split(" ");
    while(!(inp_str[0].equals("End")))
    {
      Order ord=new Order(inp_str[0],Integer.parseInt(inp_str[1]));
      //System.out.println(ord.get_food_item());
      store1.Give_suppliers(ord);
      mystring=sc.nextLine();
      inp_str=mystring.split(" ");
    }
    store1.print_order();
  }
}
