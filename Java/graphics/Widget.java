class Widget
{
  private int width,height,pos_x,pos_y;

  Widget(int iwidth,int iheight,int ipos_x,int ipos_y)
  {
    width=iwidth;
    height=iheight;
    pos_x=ipos_x;
    pos_y=ipos_y;
  }

  public int get_width()
  {
    return width;
  }

  public int get_height()
  {
    return height;
  }

  public int getpos_x()
  {
    return pos_x;
  }

  public int getpos_y()
  {
    return pos_y;
  }
}

interface MouseWatcher
{
  public void OnEnter();
  public void OnExit();
  public void moveTo(int x,int y);
  public void onClick(int x,int y);
  public Widget getWidget();
}

interface KeyboardWatcher
{
  public void onKbdEvent(char x);
  public Widget getWidget();
}
