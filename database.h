#ifndef _Database_H
#define _Database_H
#include "Single_Word.h"
class Database     //�浥�ʵ����ݿ�
{
private:
	std::vector<Single_Word> Words;  //�洢����  
	Single_Word& Get_Single_Word(std::string Temp_Word);   //��øõ����������� 
	Database() = default;
public:
	Database(std::ifstream &fin);
	bool Exist(std::string Temp_Word);  //�õ����Ƿ���� 
	std::string Get_Chinese(std::string Temp_Word);		//��øõ�������  ��������ڷ��ؿմ� 
	int Get_Difficulty(std::string Temp_Word);		//��øõ����Ѷ�  ��������ڷ���0 
	std::vector<std::string> Get_Examples(std::string Temp_Word);     //��øõ��������vector
	void Add_Example(std::string Temp_Word, std::string Temp_Example);
};
#endif
