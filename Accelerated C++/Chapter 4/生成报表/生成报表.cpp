#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::setprecision;
using std::cout;
using std::sort;
using std::domain_error;
using std::streamsize;
using std::endl;
using std::string;
using std::max;
using std::vector;

int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    //读并存储所有记录，然后找出最常姓名的长度
    while (read(cin, record)){
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    //按字母顺序排列学生记录
    sort(students.begin(), students.end(), compare);

    //输出姓名和成绩
    for (std::vector<Student_info>::size_type i = 0; i != students.size(); i++){
        //输出姓名，把姓名填充到maxlen+1个字符长度
        cout << std::setw(maxlen+1) << students[i].name;

        //计算并输出成绩
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);       
        }
        catch(domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
    
}