#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<string> split(const string& s){
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    //我们已经处理了在索引域[i,j)中的字符
    while (i != s.size()){
        //忽略前端空白
        while (i != s.size() && isspace(s[i]))
            i++;
        
        //找出下一个单词的终结点
        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            j++;
        
        //如果找到了一些非空白字符
        if (i != j){
            //从i开始复制s的j-i个字符
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return ret;
    
}


int main(){
    string s;
    while (std::getline(cin, s)){
        vector<string> v = split(s);

        for (vector<string>::size_type i = 0; i != v.size(); i++)
            cout << v[i] << endl;
    }
    return 0;
}