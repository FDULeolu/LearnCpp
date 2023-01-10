//与Student_info相关的函数的源文件
#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(Student_info& x, Student_info& y){
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s){
    //读入并存储学生的姓名以及期中、期末考试成绩
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}

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
