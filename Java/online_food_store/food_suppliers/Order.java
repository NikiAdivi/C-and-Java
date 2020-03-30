package food_suppliers;


public class Order
{
  private static int i=1;
  private String food_item;
  private int units;
  private int order_no;

  public Order(String food,int unit)
  {
    food_item=food;
    units=unit;
    order_no=i;
    i++;
  }

  public String get_food_item()
  {
    return food_item;
  }

  public int get_units()
  {
    return units;
  }

  public int get_order_no()
  {
    return order_no;
  }

}
