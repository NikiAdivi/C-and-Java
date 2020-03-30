//package phone_service;
import java.util.*;

public class Network
{

  private ArrayList<Phone> phones_in_network=new ArrayList<Phone>();

  void add_phone(Phone p)
  {
    phones_in_network.add(p);
  }

  int call_request(int number,Phone ph)
  {
    for(int i=0;i<phones_in_network.size();i++)
    {
      if(((phones_in_network.get(i)).get_no()==number) &&  ((phones_in_network.get(i)).get_activity_status()==0))
      {
        (phones_in_network.get(i)).receive_call(ph.get_no());
        return 1;
      }
    }
    return 0;
  }


  void hangup(int number)
  {
    for(int i=0;i<phones_in_network.size();i++)
    {
      if(((phones_in_network.get(i)).get_no()==number))
      {
        (phones_in_network.get(i)).hangup();
      }
    }
  }


}
