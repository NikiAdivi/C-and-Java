//package phone_service;

public class FeaturePhone extends Phone
{
  private String modem_mf;

  FeaturePhone(int iphone_no,String imodem_mf)
  {
    super(iphone_no);
    modem_mf=imodem_mf;
  }

  public String get_modem_mf()
  {
    return modem_mf;
  }
}
