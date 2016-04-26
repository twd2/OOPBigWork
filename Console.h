#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <vector>
#include <string>
class Console{
private:
//	vector<����> *WordsList;
	User *Current_User;
	ReciteStrategy *recite_strategy;//Console������Ԫ 
	NewWordsStrategy *newwords_strategy;//Console������Ԫ 
	Console();
	void Login();
	void Regist();
	int GetWord(string query);
	void ChangeReciteStrategy();
	void SearchWords();
	void TestWords();
public:
	void Run();
};
#endif
