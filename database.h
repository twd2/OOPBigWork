#ifndef _Database_H
#define _Database_H
#include "Single_Word.h"
class Database     //�浥�ʵ����ݿ�
{
private:
	vector<Single_Word> Words;  //�洢����  
	Single_Word Get_Single_Word(string Temp_Word);   //��øõ����������� 
	Database(ifstream &fin);
	Database() = default;
public:
	bool Exist(string Temp_Word);  //�õ����Ƿ���� 
	string Get_Chinese(string Temp_Word);		//��øõ�������  ��������ڷ��ؿմ� 
	int Get_Difficulty(string Temp_Word);		//��øõ����Ѷ�  ��������ڷ���0 
	vector<string> Get_Examples(string Temp_Word);     //��øõ��������vector
	void Add_Example(string Temp_Word, string Temp_Example);
};
#endif
