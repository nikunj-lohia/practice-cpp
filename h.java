

public class h{
    public static void main(String args[])
    {
        System.out.println("hi");
        System.out.println();
        audi a1 =new audi();
        a1.start();
    }
}
class audi extends car{
  void start(){
      System.out.println("hi");
  }
}
abstract class car{
    int price;
    abstract void start();
}
