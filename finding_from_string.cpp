#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main (int args,char* argc[])
{
    string s1="0102030405060708";

    string s2="01";

    if(s1.find(s2)!=std::string::npos||s1.find("02")!=std::string::npos||s1.find("03")!=std::string::npos||s1.find("04")!=std::string::npos)
    {
        cout<<"Found Successfully\n";
    }
    

    return 0;

}