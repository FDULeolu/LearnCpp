//编写一个函数来从输入流读单词，把读到的单词存储在一个向量中，利用这个函数编写一个程序来计算输入的单词的数目和每个单词出现的次数
#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::istream;
using std::endl;

struct word_dic
{
    string word;
    int number;
};

//读入输入的单词流
istream& read_words(istream& in, vector<string>& word_list){
    if (in){
        in.clear();

        string word;
        while (in >> word){
            word_list.push_back(word);
        }

        in.clear();
    }
    return in;
}

//计算某单词出现的次数
int count(vector<string>& word_list, string word){
    int word_number=0;

    for (int i=0; i < word_list.size(); i++){

        if (word_list[i] == word){
            word_number++;
        }
    }
    return word_number;
}

//将该单词出现的次数更新到word_dic中
int update(string word, vector<word_dic>& word_book, int number){
    for (int i=0; i< word_book.size(); i++){
        if (word_book[i].word == word)
            return 0;
    }

    word_dic word_info;
    word_info.word = word;
    word_info.number = number;

    word_book.push_back(word_info);
    
    return 1;
}

int main(){
    vector<string> word_list;
    vector<word_dic> word_dic;

    read_words(cin, word_list);
    cout << word_list.size();
    cout << endl;

    for (int i=0; i<word_list.size(); i++){
        update(word_list[i], word_dic, count(word_list, word_list[i]));
    }

    for (int i=0; i < word_dic.size(); i++){
        cout << std::setw(10) << word_dic[i].word << " " << word_dic[i].number << endl;
    }

    return 0;
}

