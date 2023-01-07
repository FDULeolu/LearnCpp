#include <iostream>
#include <string>

using std::cin; using std::endl;
using std::cout; using std::string;

int main(){
    //请求用户输入姓名
    cout << "Plsease enter your first name:";

    //读入用户输入的姓名
    string name;
    cin >> name;

    //构造我们想要输出的信息
    const string greeting = "Hello," + name + "!";

    //围住问候语的空白个数
    const int pad = 1;

    //待输出的行数和列数
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2; 
    //string::size_type 可以用来定义字符串中的字符个数

    //输出一个空白行，把输入和输出分开
    cout << endl;

    //输出rows行
    for (int r = 0; r != rows; ++r){
        string::size_type c = 0;

        while (c != cols){
            if (r == pad + 1 && c == pad +1){
                cout << greeting;
                c += greeting.size();
            }
            else{
                if (r == 0 || r == rows-1 || c == 0 || c == cols-1)
                    cout << '*';
                else
                    cout << ' ';
                ++c;
            }
        }

        cout << endl;
    }
    
    return 0;
}