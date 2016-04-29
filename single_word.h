#ifndef single_word_H
#define single_word_H
#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
class single_word
{
	string word;       //english
	string chinese;
	int difficulty;
	vector<string> example;		//������� 
public:	
	string getword();        //��õ��� 
	string getchinese();		//��õ������� 
	int get_difficulty();		//����Ѷ� 
	void add_example(string temp_example);       //�������� 
	vector<string> get_example();                  //��øõ������� 
	single_word(const ifstream& fin);
	single_word() = default;
};
#endif
