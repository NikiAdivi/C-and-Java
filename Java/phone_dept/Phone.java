//package phone_service;
import java.util.*;

abstract public class Phone
{
  private int phone_no;
  private int activity;
  int connected_phone;
  Network net;

  Phone(int iphone_no)
  {
    phone_no=iphone_no;
  }

  public void attach_to_network(Network inet)
  {
    net=inet;
    net.add_phone(this);
  }

  public int get_no()
  {
    return phone_no;
  }

  abstract public String get_modem_mf();

  public String call(int number)
  {
    int response;
    response=net.call_request(number,this);
    if(response==1)
    {
      activity=1;
      connected_phone=number;
      return "Successful";
    }
    return "Not Successful";
  }

  public void hangup()
  {
    if(activity==1) //Valid hangup request
      {
        activity=0;
        net.hangup(connected_phone);
      }
  }

  public int get_activity_status()
  {
    return activity;
  }

  void receive_call(int number)
  {
    activity=1;
    connected_phone=number;
  }

}
