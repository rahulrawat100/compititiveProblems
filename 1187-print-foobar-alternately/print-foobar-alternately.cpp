volatile int S=1;
class FooBar {
private:
    int n;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	while(S<=0);
        	printFoo();
            S=S-1;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            while(S>0);
        	printBar();
            S=S+1;
        }
    }
};