package food_suppliers;
//import order.*;
import java.util.*;
import java.io.*;

class Bakery
{
  private ArrayList<Order> orders=new ArrayList<Order>();

  void Addorder(Order i)
  {
    orders.add(i);
  }

  String toString(Order o)
  {
    return "Order "+o.get_order_no()+" "+o.get_food_item()+" "+o.get_units();
  }

  void print_orders()
  {
    Collections.sort(orders, new Comparator<Order>() {
    public int compare(Order lhs, Order rhs) {
        return (rhs.get_units()-lhs.get_units());
    }
  });

    for(int i=0;i<orders.size();i++)
    {
      System.out.println(toString(orders.get(i)));
    }
  }

}
