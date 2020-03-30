//package phone_service;
public class SmartPhone extends Phone
{
  private String modem_mf;
  private String cpu_mf;

  SmartPhone(int iphone_no,String icpu_mf,String imodem_mf)
  {
    super(iphone_no);
    modem_mf=imodem_mf;
    cpu_mf=icpu_mf;
  }

  public String get_modem_mf()
  {
    return modem_mf;
  }

  public String get_cpu_mf()
  {
    return cpu_mf;
  }
}
