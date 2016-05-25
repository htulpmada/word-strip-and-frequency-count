// main.cpp : main project file.
//written by adam pluth
//cs 101 
//9/3/2015
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int search(string words, string word1){
	string word2=" "+word1+" ";
	int count=0;
	string::size_type start=0;
	while((start = words.find(word2,start))!=string::npos){count++;start += word2.length();}
	return count;}

int main (int argc, char** argv) {
    ifstream fin;
    string line;
	string word = " ";
	int wordcount=0;
	int uwordcount=0;
	if (argc<2){cout << "sorry you need to enter a file as command line argument"; return 0;}
	fin.open(argv[1]);
    if (fin!=NULL){
		while (!fin.eof()){
				fin >> line;
				int x = line.size();
				string Line= string(line);
				for (int i=0; i < x ;i++){//parse threw letters
					Line[i]= tolower(Line[i]);//maybe after(as elif)
					if(isdigit(Line[i])){continue;}
					if(!isalpha(Line[i])){Line.erase(i--,1);x=Line.size();}}
				if(Line==""||Line=="\n"){/*wordcount--;*/continue;}
				if(word.find(" " + Line + " ")==std::string::npos){word += Line + " ";wordcount++;uwordcount++;}
				else if(word.find(" " + Line + " ")!=std::string::npos){word += Line + " ";/*cout<<Line*/;wordcount++;}}

			cout<<"word count:"<<wordcount<<std::endl;
			cout<<"unique word count:"<<uwordcount<<std::endl;
			fin.close();
			while(!cin.eof()){string tofind;cout << "Please enter a word:";cin>>tofind;cout << "The word "<< tofind << " appears " << search(word ,tofind)<< " times in the document"<<std::endl<<std::endl;}}
    else {cout<<"Cannot read from input.txt";}
    return 0;}