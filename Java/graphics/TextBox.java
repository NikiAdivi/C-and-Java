import java.util.*;

class TextBox extends Widget implements KeyboardWatcher
{
  TextBox(int iwidth,int iheight,int ipos_x,int ipos_y)
  {
    super(iwidth,iheight,ipos_x,ipos_y);
  }

  private String text="";

  @Override
  public void onKbdEvent(char x)
  {
    text=text+x;
    System.out.println(this.gettext());
  }

  String gettext()
  {
    return text;
  }

  @Override
  public TextBox getWidget()
  {
    return this;
  }

}
