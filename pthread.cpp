#include<iostream>
#include<thread>

void sayHello(){
    std::cout<<"Hello from new thread\n";
}

int main(){
    std::thread t(sayHello);
    t.join();
    std::cout<<"Main finished\n";
    return 0;
}