#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

string readFile4( string filename )                                            // @lastchance: just add chars
{
   char c;
   ifstream file( filename );

   string s;
   file >> noskipws;           // needed to prevent loss of spaces and linefeeds
   while ( file >> c ) s += c;

   return s;
}

int main(int args,char* argc[])
{
    string filename="message.txt";
    string s;

    s=readFile4(filename);

    //cout<<s<<endl;



    
}