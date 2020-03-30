import java.util.*;

class generics
{
  public <T extends Number> T hello(T a,T b)
  {
    return a+b;
  }
  public static void main(String[] args) {
    generics g=new generics();
    System.out.println(g.hello(3,4));
    System.out.println(g.hello(3.4,4.4));
  }
}
