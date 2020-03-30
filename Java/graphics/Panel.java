import java.util.*;

class Panel extends Widget implements KeyboardWatcher,MouseWatcher
{
  Panel(int iwidth,int iheight,int ipos_x,int ipos_y)
  {
    super(iwidth,iheight,ipos_x,ipos_y);
  }
  ArrayList<Widget> widgets=new ArrayList<Widget>();
  ArrayList<KeyboardWatcher> kbdwatchers=new ArrayList<KeyboardWatcher>();
  ArrayList<MouseWatcher> mousewatchers=new ArrayList<MouseWatcher>();
  private int current_x=0;
  private int current_y=0;
  //private Widget current_widget;

  /*Widget search_in_widgets(Widget i)
  {
      for(Widget j:widgets)
      {
        if(i==j)
          return i;
      }
  }*/

  int lies_inside(int x,int y,Widget i)
  {
    if(i.getpos_x()<x && (i.getpos_x()+i.get_width())>x && i.getpos_y()<y && (i.getpos_y()+i.get_height())>y)
      return 1;
    else
      return 0;
  }

  @Override
  public void moveTo(int x,int y)
  {
    current_x=x;
    current_y=y;
  }

  @Override
  public void onClick(int x,int y)
  {
    for(MouseWatcher i:mousewatchers)
    {
    //  System.out.println(i.getWidget());
       if(lies_inside(x,y,i.getWidget())==1)
         i.onClick(x,y);
    }
  }

  @Override
  public void onKbdEvent(char x)
  {
    for(KeyboardWatcher i:kbdwatchers)
    {
      if(lies_inside(current_x,current_y,i.getWidget())==1)
        //System.out.println(i);
          i.onKbdEvent(x);
    }
  }

  public void OnEnter()
  {
    return;
  }

  public void OnExit()
  {
    return;
  }

  public Widget getWidget()
  {
    return this;
  }

  public void addMouseWatcher(MouseWatcher m)
  {
    mousewatchers.add(m);
  }
  public void addKeyboardWatcher(KeyboardWatcher w)
  {
    kbdwatchers.add(w);
  }

  public void addWidget(Widget w,int x,int y)
  {
    widgets.add(w);
  }




}
