#include <iostream>
#include <string>
#include <cstring>
#include "Console.h"
void Console::ChangeReciteStrategy(){
	std::cout << "Which memory strategy do you want? 1.Shanbay mode 2.Towords mode" << std::endl;
	char Temp[200];
	std::cin.getline(Temp, 200);
	if (strlen(Temp) == 1 && Temp[0] >= '1' && Temp[0] <= '2') Current_User->Change_Memory_Strategy(Temp[0]-'0');
	else std::cout << "No such strategy." << std::endl;
}
std::string Console::Get_Word(std::string Temp_Word){
	return data->Get_Chinese(Temp_Word);
}
void Console::Show_Search_History(){
	std::vector<std::string>History = Current_User->Get_Search_History();
	if (History.size() == 0) std::cout << "No search history yet." << std::endl;
	else{
		cout << "Last " << History.size() << " search history:" << std::endl;
		for (int i = 0; i < (int)History.size(); ++i) std::cout << History[i] << std::endl;
	}
}
void Console::Search(){
	while (1){
		std::cout << "What do you want to do? 0.Search Word 1. Get Search History 2.Clear Search History 3.Exit"
		<< std::endl;
		char Temp[200]; string Temp_Word, Chinese;
		std::cin.getline(Temp, 200);
		if (strlen(Temp) == 1){
			switch (Temp[0]){
				case '0':
					std::cin >> Temp_Word;
					Chinese = data->Get_Chinese(Temp_Word);
					if (Chinese == "") std::cout << "No such Word." << std::endl;
					else std::cout << Chinese << endl;
					break;
				case '1':
					Show_Search_History();
					break;
				case '2':
					Current_User->Clear_History();
					break;
				case '3':
					return;
			}
		}
	}
}
Console::Console(){
	//���뵥�ʿ�
	//ѡ���½/ע��
}
void Console::Run(){
	while (1){
		//���������Ϣ
		// if (recite) recitestrategy->recite();
	}
}
void Console::SearchWords(){
	//ѡ����/��ѯ��ʷ/�����ʷ 
	//���뵥��
	//����GetWord
	//�����ʷ��Ϣ 
}
