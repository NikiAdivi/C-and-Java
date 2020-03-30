
package food_suppliers;
//import order.*;

public class Store
{
  private int bakery_no=0;
  private int diary_no=0;
  private int bakery_count;
  private int diary_count;

  private Bakery[] b;
  private Diary[] d;


  public Store(int bakery_cnt,int diary_cnt)
  {
    diary_count=diary_cnt;
    bakery_count=bakery_cnt;
    b=new Bakery[bakery_count];
    for(int i=0;i<bakery_count;i++)
    {
      b[i]=new Bakery();
    }
    d=new Diary[diary_count];
    for(int i=0;i<diary_count;i++)
    {
      d[i]=new Diary();
    }
  }


  //Write addbakeries and add_diaries functions to initialise objectsa

  public void Give_suppliers(Order o)
  {
    if((o.get_food_item().equals("Milk")) || (o.get_food_item().equals("Butter")))
    {
      //System.out.println("Came into diary!");
      d[diary_no++].Addorder(o);
      diary_no=diary_no%diary_count;
    }
    else
    {
      //System.out.println("Came into bakery!");
      b[bakery_no++].Addorder(o);
      bakery_no=bakery_no%bakery_count;
    }
  }

  public void print_order()
  {
    for(int i=1;i<=bakery_count;i++)
    {
      System.out.println("Bakery "+i);
      b[i-1].print_orders();
      System.out.println("");
    }
    for(int i=1;i<=diary_count;i++)
    {
      System.out.println("Diary "+i);
      d[i-1].print_orders();
      System.out.println("");
    }
  }

}
