#ifndef _database_H
#define _database_H
#include"single_word.h"
class database     //�浥�ʵ����ݿ�
{
	vector<single_word> words;  //�洢����  
	single_word get_single_word(string temp_word);   //��øõ����������� 
	database(const ifstream &fin);
	database() = default;
public:
	bool exist(string temp_word);  //�õ����Ƿ���� 
	string chinese(string temp_word);		//��øõ������� 
	int difficulty(string temp_word);		//��øõ����Ѷ� 
	vector<string> get_examples(string temp_word);     //��øõ��������vector
	void add_example(string temp_word, string temp_example);
};
#endif 
