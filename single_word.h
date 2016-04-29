#ifndef Single_Word_H
#define Single_Word_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
class Single_Word
{
	string Word;       //english
	string Chinese;
	int Difficulty;
	vector<string> Example;		//������� 
public:	
	string Get_Word();        //��õ��� 
	string Get_Chinese();		//��õ������� 
	int Get_Difficulty();		//����Ѷ� 
	void Add_Example(string Temp_Example);       //�������� 
	vector<string> Get_Example();                  //��øõ������� 
	Single_Word(ifstream& fin);
	Single_Word() = default;
};
#endif
