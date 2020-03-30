class Button extends Widget implements MouseWatcher
{
  Button(int iwidth,int iheight,int ipos_x,int ipos_y)
  {
    super(iwidth,iheight,ipos_x,ipos_y);
  }

  public void OnEnter()
  {
    return;
  }

  public void OnExit()
  {
    return;
  }

  public void moveTo(int x,int y)
  {
    return; //Move eherever within the widget, doesnt update the functionalities
  }

  public void onClick(int x,int y)
  {
    System.out.println("Selected point: "+(x-this.getpos_x())+" "+(y-this.getpos_y()));
  }

  public Button getWidget()
  {
    return this;
  }

}
