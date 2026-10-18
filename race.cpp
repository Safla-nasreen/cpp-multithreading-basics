#include<iostream>
#include<thread>

int count = 0;

void addPlates(){
    for(int i = 0; i < 1000000; i++){
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