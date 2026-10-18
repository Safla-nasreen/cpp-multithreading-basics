#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cv;
bool orderReady = false;

void cook() {
    unique_lock<mutex> lock(m);
    cout<<"Cook waiting for an order...\n";
    while(!orderReady){
        cv.wait(lock);
    }
    cout<<"Cook : got the order, cooking now!\n";
}

void waiter() {
    this_thread::sleep_for(chrono::seconds(2));
    {
        lock_guard<mutex> lock(m);
        orderReady = true;
        cout<<"Waiter order placed!\n";
    }
    cv.notify_one();
}

int main() {
    thread t1(cook);
    thread t2(waiter);

    t1.join();
    t2.join();
    
    cout<<"Kitchen closed!!\n";
    return 0;
}