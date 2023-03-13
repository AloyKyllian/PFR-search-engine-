package test.java;

import com.sun.jna.Library;
import com.sun.jna.Native;


public interface MyLibrary extends Library {

  MyLibrary INSTANCE = (MyLibrary) Native.loadLibrary("mylibrary", MyLibrary.class); 
  void passerLaMain();

  int getMain();
}