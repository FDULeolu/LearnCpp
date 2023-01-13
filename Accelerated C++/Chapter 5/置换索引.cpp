//设计和实现一个程序来产生一个置换索引。在一个置换索引中，每一个短语都是这个短语的每一个单词作为索引的。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <list>

using namespace std;

typedef string::size_type str_sz;

struct Rotation
{
    vector<string>::size_type first;
    vector<string> words;
};

//分割字符串
vector<string> split(const string& s){
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size()){
        //忽略前段空白
        while(i != s.size() && isspace(s[i])){
            i++;
        }

        //找出下一个单词的终结点
        string_size j = i;
        while (j != s.size() && !isspace(s[j])){
            j++;
        }

        if(i != j){
            ret.push_back(s.substr(i, j - i));
            i = j;
        }

    }
    return ret;
}

//单行文本轮转
vector<Rotation> rotate_line(const string& line){
    vector<Rotation> rotations;
    vector<string> words = split(line);

    //每次将vector中的一个单词旋转到最后一个
    for (vector<Rotation>::size_type i = 0; i != words.size(); ++i){
        Rotation rot = {words.size() - i, words};
        rotations.push_back(rot);
        rotate(words.begin(), words.begin()+1, words.end());
    }
    return rotations;
}

//多行文本轮转
vector<Rotation> rotate_lines(const vector<string>& lines){
    vector<Rotation> rotations;
    for (vector<string>::size_type i = 0; i != lines.size(); ++i){
        vector<Rotation> new_rotations = rotate_line(lines[i]);
        rotations.insert(rotations.end(), new_rotations.begin(), new_rotations.end());
    }
    return rotations;
}

//转换为小写字母
string to_low_case(const string& date){
    string str = date;
    std::transform(date.begin(), date.end(), str.begin(), ::tolower);
    return str;
}

//整个字符串数组转换为小写字母
vector<string> lowcase(const vector<string>& date){
    vector<string> vect;
    for (vector<string>::const_iterator it = date.begin(); it != date.end(); ++it){
        vect.push_back(to_low_case(*it));
    }
    return vect;
}

//按字母大小排序
bool compare(const Rotation& x,const Rotation& y){
    return lowcase(x.words) < lowcase(y.words);
}

void print_rotations(vector<Rotation> rotations){
    vector<string> first_halves;
    vector<string> second_halves;
    string::size_type max_first_halves_width = 0;

    for (vector<Rotation>::size_type i = 0; i != rotations.size(); ++i){
        Rotation rot = rotations[i];
        string first_half, second_half;

        for (vector<string>::size_type j =rot.first; j < rot.words.size(); ++j){
            first_half += rot.words[j] + " ";
        }

        first_halves.push_back(first_half);

        if(first_half.size() > max_first_halves_width){
            max_first_halves_width = first_half.size();
        }

        for (vector<string>::size_type j = 0; j < rot.first; ++j){
            second_half += rot.words[j] + " ";
        }

        second_halves.push_back(second_half);
    }

    cout << endl;
    
    for (vector<string>::size_type i = 0; i != first_halves.size(); ++i){
        cout << setw(max_first_halves_width)
            << first_halves[i]
            << "\t"
            << second_halves[i]
            <<endl;
    }
}

//读入每一行输入的句子
vector<string> read_lines(){
    vector<string> lines;
    string line;
    while(getline(cin, line)){
        lines.push_back(line);
    }
    return lines;
}

int main(){
    vector<string> lines = read_lines();
    vector<Rotation> rotations = rotate_lines(lines);
    sort(rotations.begin(), rotations.end(), compare);
    print_rotations(rotations);
    return 0;
}
