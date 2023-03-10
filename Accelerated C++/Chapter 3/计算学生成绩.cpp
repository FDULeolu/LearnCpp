#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::setprecision;
using std::cout;
using std::string;
using std::endl;
using std::streamsize;

int main(){
    //请求输入并读入学生姓名
    cout << "Please enter your first name:";
    string name;
    cin >> name;
    cout << "Hello," + name + '!' << endl;

    //请求输入并读入期中和期末成绩
    cout << "Please enter your midterm and final exam grades:";
    double midterm, final;
    cin >> midterm >> final;

    //请求输入家庭作业成绩
    cout << "Enter all your homework grades, "
            "followed by end-of-file:";
    
    //到目前为止，读到的家庭作业成绩的个数及总和
    int count = 0;
    double sum = 0;

    //把家庭作业成绩读到变量x中
    double x;

    while (cin >> x){
        count++;
        sum += x;
    }

    //输出结果
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;

    return 0;

}

