#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include<map>
class User{
private:
	std::vector<std::string> Search_History;       //��ѯ��ʷ 
	int Difficulty_Of_User;				//�û����趨���Ѷ� 
	int Memory_Strategy;				//�û����趨�ļ������ 
	map<string, pair<int, int>> Memorized_Words_Times;
public:
	int Get_Difficulty();         //����û��趨�Ѷ� 
	int Get_Memory_Strategy();		//��ü������ 
	std::vector<std::string> Get_Search_History();     //��ò�ѯ��ʷ 
	pair<int, int> Get_Memorized_Times(std::string Temp_Word);
	void Add_Example(std::string Word, std::string Example);		//��������			
	void Clear_History();         //��ղ�ѯ��ʷ 
	void Add_History(std::string Word);        //�����ѯ��ʷ
	void Change_Memory_Strategy(int Wanted_Strategy);      //���Ĳ�ѯ��ʷ
	User();
};
#endif
