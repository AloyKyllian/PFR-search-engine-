package test.java;
import java.lang.Thread;
import com.sun.jna.Library;
import com.sun.jna.Native;

public class Main {

public interface MyLibrary extends Library {

  MyLibrary INSTANCE = (MyLibrary) Native.loadLibrary("../C/JNA.so", MyLibrary.class); 
  void passerLaMain();

  int getMain();

    public static void main(String[] args) {
        int Main=0;
        do{
                if(MyLibrary.INSTANCE.getMain() == 0 )
                {
                    System.out.println("On est en JAVA et on vas passer la main au c ");       
                    MyLibrary.INSTANCE.passerLaMain();
                    System.out.println("On est en JAVA et on a passe la main au c donc main doit etre a 1 ");   
                    System.out.println("main :  "+Main);
                } 
                else
                {  
                    System.out.println("JAVA na pas la main "); 
                    try{
                       Thread.sleep(2000); 
                    }
                    catch(InterruptedException e){
                        e.printStackTrace();
                    }
                    Main=MyLibrary.INSTANCE.getMain();
                    System.out.println("apres appel de getMain :  "+Main);
                }

        }while(true);
         
    }

}
}