#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

std::mutex knife;
std::mutex board;

void cook1(){
    std::lock_guard<std::mutex> a(knife);
    std::cout<<"Cook 1 has knife, waiting for the board\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> b(board);
    std::cout<<"Cook 1 is cutting\n";
}

void cook2(){
    std::lock_guard<std::mutex> a(knife);
    std::cout<<"Cook 2 has board, waiting for the knife\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> b(board);
    std::cout<<"Cook 2 is cutting\n";
}

int main(){
    std::thread t1(cook1);
    std::thread t2(cook2);

    t1.join();
    t2.join();

    std::cout<<"kitchen closed\n";
    return 0;
}