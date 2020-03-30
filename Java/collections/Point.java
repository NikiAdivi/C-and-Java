class Point
{
  public static int  method1(int a,int b){
    return a/b;

}

  public static void main(String[] args) {
    int a=5;
    int b=0;
    try{
    int k=method1(a,b);
  }
  catch(ArithmeticException e)
{
  System.err.println(e.getMessage());
}
}
}
