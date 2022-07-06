class Foo {
    int state;
    mutex mtx;
    condition_variable cv;
public:
    Foo() {
        state = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        state = 1;
        lck.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while(state != 1){
            cv.wait(lck);
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        state = 2;
        lck.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while (state != 2) { 
            cv.wait(lck);
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
        state = 3;
        lck.unlock();
        cv.notify_all();
    }
};
