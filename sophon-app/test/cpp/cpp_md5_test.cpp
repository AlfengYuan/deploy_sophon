//
// Created by yyf on 24-1-4.
//

#include "md5.h"
#include <iostream>

using namespace std;
#define FileDirName "base64_jpg_test.cpp"

void PrintMD5(const string &str, MD5 &md5) {
    cout << "MD5(\"" << str << "\") = " << md5.toString() << endl;
}

int main() {
    MD5 md5;
    md5.update("");
    PrintMD5("", md5);
    md5.update("a");
    PrintMD5("a", md5);
    md5.update("bc");
    PrintMD5("abc", md5);
    md5.update("defghijklmnopqrstuvwxyz");
    PrintMD5("abcdefghijklmnopqrstuvwxyz", md5);
    md5.reset();
    md5.update("message digest");
    PrintMD5("message digest", md5);
    md5.reset();

    //打开二进制文件（例如常见的二进制文件  .so,.dll,.exe,.bin ）
    ifstream in(FileDirName, ios::binary);
    if (!in) {
        return 0;
    }
    md5.reset();
    md5.update(in);
    std::string str = md5.toString();
    PrintMD5(FileDirName, md5);
    return 0;
}