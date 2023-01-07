#include <iostream>
#include <string>

int main(){
    //请某人输入其姓名
    std::cout << "Plsease enter your first name:";

    //读姓名
    std::string name;   //定义变量name
    std::cin >> name;   //把姓名读进name

    //输出问候语
    std::cout << "Hello," << name << "!" << std::endl;
    return 0;
}