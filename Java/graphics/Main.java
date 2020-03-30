import java.util.*;

class Main
{
public static void main(String[] args)
  {
      Panel p=new Panel(600,800,0,0);
      TextBox t=new TextBox(400,200,100,300);
      Button b=new Button(200,100,250,100);

      p.addWidget(t,100,300);
      p.addWidget(b,250,100);

      p.addMouseWatcher(b);
      p.addKeyboardWatcher(t);

      Scanner sc=new Scanner(System.in);
      String mystring=sc.nextLine();
      String[] k=mystring.split(" ");

      int moveto_x=0;
      int moveto_y=0;

      while(!k[0].equals("End"))
      {
        if(k[0].equals("MoveTo"))
        {
          moveto_x=Integer.parseInt(k[1]);
          moveto_y=Integer.parseInt(k[2]);
          p.moveTo(moveto_x,moveto_y);
        }
        else if(k[0].equals("MouseClick"))
        {
          p.onClick(moveto_x,moveto_y);
        }
        else if(k[0].equals("KeyPressed"))
        {
          p.onKbdEvent(k[1].charAt(0));
        }

        mystring=sc.nextLine();
        k=mystring.split(" ");
      }

  }

}
