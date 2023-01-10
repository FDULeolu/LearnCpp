#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>

using std::cin;
using std::setprecision;
using std::cout;
using std::string;
using std::endl;
using std::streamsize;
using std::vector;
using std::domain_error;
using std::istream;

//根据期中考试、期末考试以及家庭作业成绩来计算总成绩
double grade(double midterm, double final, double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//计算一个vector<double>类型的变量的中值
double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size==0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

//根据期中、期末考试成绩和保存家庭作业的向量来计算学生的总成绩
double grade(double midterm, double final, const vector<double>& hw){
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

//读一个输入流，把家庭作业成绩读进一个vector<double>类型的向量中
istream& read_hw(istream& in, vector<double>& hw){
    if (in){
        //清除原先内容
        hw.clear();

        //读家庭作业成绩
        double x;
        while (in >> x)
            hw.push_back(x);

        //清除流以使输入动作对下一个学生有效
        in.clear();
    }
    return in;
}

int main(){

    //请求输入学生姓名
    cout << "Please enter your first name:";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    //请求并读入期中和期末考试成绩
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    //请求用户输入家庭作业成绩
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    vector<double> homework;

    //读入家庭作业成绩
    read_hw(cin, homework);

    //如果可以的话，计算生成总成绩
    try{
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    }   catch (domain_error){
        cout << endl << "You must enter your grades. "
                     << "Please try again." << endl;
        return 1;
    }

    return 0;
}