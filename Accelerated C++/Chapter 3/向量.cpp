#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::setprecision;
using std::cout;
using std::string;
using std::endl;
using std::streamsize;
using std::vector;

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

    //向量解法计算中位数
    double x;
    std::vector<double> homework;

    while (cin >> x)
    {
        homework.push_back(x);    
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0){
        cout << endl << "You must enter your grades."
                     << "Please try again." << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());

    vec_sz mid = size/2;
    double median;
    median = (size % 2 == 0) ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

    //输出结果
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;

    return 0;
    
}

