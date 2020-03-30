//import phone_service.*;
import java.util.*;
class Main
{
  public static void main(String[] args)
  {
    Network n=new Network();
    FeaturePhone p1=new FeaturePhone(12345,"TI");
    SmartPhone p2=new SmartPhone(23456,"Samsung","Mediatek");
    SmartPhone p3=new SmartPhone(13452,"Apple","Apple");
    p1.attach_to_network(n);
    p2.attach_to_network(n);
    p3.attach_to_network(n);
    System.out.println(p1.call(23456));
    System.out.println(p3.call(12345));
    n.hangup(23456);
    System.out.println(p3.call(12345));

  }
}
