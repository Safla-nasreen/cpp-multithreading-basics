#include<iostream>
#include<thread>
#include<string>

void cook(std::string dish, int count){
    std::cout<<"Cooking "<<count<<" "<<dish<<std::endl;
}

int main(){
    
    std::thread t1(cook, "dosa", 3);
    std::thread t2(cook, "idli", 5);

    t1.join();
    t2.join();

    std::cout<<"Kitchen closed\n";
    return 0;

}