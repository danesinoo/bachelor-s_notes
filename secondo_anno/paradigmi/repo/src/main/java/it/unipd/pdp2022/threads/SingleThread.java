package it.unipd.pdp2022.threads;

import static java.lang.System.out;

public class SingleThread {

  public static void main(String[] args) {
    Thread a = new ThreadSupplier().get();

    out.println("Starting Single Thread");
    a.start();
    out.println("Done starting.");
  }
}
