#include<iostream>
#include<thread>
#include<mutex>

int count = 0;
std::mutex m;

void addPlates(){
    for(int i = 0; i < 1000000; i++){
        std::lock_guard<std::mutex> lock(m);
        count++;
    }
}

int main(){
    std::thread t1(addPlates);
    std::thread t2(addPlates);

    t1.join();
    t2.join();

    std::cout<<"Expected: 2000000\n";
    std::cout<<"got      :"<<count<<std::endl;
    return 0;
}