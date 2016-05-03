#ifndef CONSOLE_H
#define CONSOLE_H
#include <Database.h>
#include <fstream>
#include <User.h>
#include <Memory_Strategy.h>
#include <Memory_Strategy_Shanbay.h>
#include <Memory_Strategy_Towords.h>
#include <NewWords_Strategy.h>
#include <NewWords_Strategy1.h>
#include <Test_Strategy.h>
#include <Test_Strategy_TF.h>
#include <Test_Strategy_Multi.h>
class Console{
private:
	Database *data;
	User *Current_User;
	Memory_Strategy *memory_strategy;       //������� 1��ʾ�ȱ�ģʽ��2��ʾ�ٴ�նģʽ 
	NewWords_Strategy *newwords_strategy;		//����ͳ�ƽ��Ͳ���
	Test_Strategy *test_strategy;       //���ߵ��ʲ��Բ��� 1.�ж��⣬2.ѡ���� 
	std::vector<std::string> get_out_console;       //���ı��л����� 
	
	void Change_Memory_Strategy();
	
	std::string Get_Word(std::string Temp_Word);      //��õ�������
	void Show_Search_History();     //��ʾ��ѯ��ʷ
	void Search();   //��search�У������û�Ҫ���������ʾ��ѯ��ʷ���ǲ鵥�� 
	void Test();	//ѡ�����ģʽ������ 1.�ж��� 2.ѡ����  
	void NewWords();
	
public:
	void Run();
	Console(Database *temp_data, User *temp_user); 
	Console() = default;
};
#endif
