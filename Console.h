#ifndef Console_H
#define Console_H
#include <iostream>
#include <vector>
#include <string>
class Console{
private:
//	vector<����> WordsList;
	User *Current_User;
	
	Console();
	void Login();
	void Regist();
public:
	void Run();
};
#endif
