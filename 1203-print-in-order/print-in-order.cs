using System.Threading;
public class Foo {
    Semaphore s = new Semaphore(0, 1);
    Semaphore t = new Semaphore(0, 1);
    public Foo() {
        
    }

    public void First(Action printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        s.Release();
    }

    public void Second(Action printSecond) {
        s.WaitOne();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        t.Release();
    }

    public void Third(Action printThird) {
        t.WaitOne();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
}