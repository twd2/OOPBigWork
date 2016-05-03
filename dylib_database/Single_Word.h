#ifndef Single_Word_H
#define Single_Word_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
class Single_Word
{
	std::string Word;       //english
	std::string Chinese;
	int Difficulty;
	std::vector<std::string> Example;		//������� 
public:	
	std::string Get_Word();        //��õ��� 
	std::string Get_Chinese();		//��õ������� 
	int Get_Difficulty();		//����Ѷ� 
	void Add_Example(std::string Temp_Example);       //�������� 
	std::vector<std::string> Get_Example();                  //��øõ������� 
	Single_Word(std::string temp); 
	Single_Word() = default;
};
#endif
