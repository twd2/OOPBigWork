#include <cstring>
#include <sstream>
#include "Console.h"
void Console::Change_Memory_Strategy(){
	Out->Print(get_out_console[0]);
	std::string Temp;
	getline(std::cin, Temp);
	if (Temp.size() == 1 && Temp[0] >= '1' && Temp[0] <= '2'){
		Current_User->Change_Memory_Strategy_Number(Temp[0]-'0');
		switch (Temp[0]){
			case '1':
				{
					if (memory_strategy) delete memory_strategy;
					memory_strategy = new Memory_Strategy_Shanbay(Current_User, data);
				}
				break;
			case '2':
				{
					if (memory_strategy) delete memory_strategy;
					memory_strategy = new Memory_Strategy_Towords(Current_User, data);
				}
				break;
		}
	}
	else Out->Print(get_out_console[1]);
}
std::string Console::Get_Word(std::string Temp_Word){
	return data->Get_Chinese(Temp_Word);
}
void Console::Show_Search_History(){
	std::vector<std::string>History = Current_User->Get_Search_History();
	if (History.size() == 0) Out->Print(get_out_console[2]);
	else{
		std::stringstream ss; 
		ss << History.size();
		std::string Temp; Temp.clear();
		ss >> Temp;
		ss.clear(); ss.str("");
		Out->Print(get_out_console[3]+Temp+get_out_console[4]);
		for (int i = (int)History.size() - 1; i >= 0; --i) Out->Print(History[i]);
	}
}
void Console::Search(){
	while (1){
		for (int i = 5; i <= 9; ++i) Out->Print(get_out_console[i]);
		std::string Temp; std::string Temp_Word, Chinese;
		getline(std::cin, Temp);
		if (Temp.size() == 1){
			switch (Temp[0]){
				case '0':
					getline(std::cin, Temp); Temp_Word = Temp;
					Chinese = data->Get_Chinese(Temp_Word);
					if (Chinese == "") Out->Print(get_out_console[10]);
					else Out->Print(Chinese);
					Current_User->Add_History(Temp_Word);
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
void Console::Test(){
	while (1){
		Out->Print(get_out_console[11]);
		std::string Temp;
		getline(std::cin, Temp);
		if (Temp.size() == 1 && Temp[0] >= '1' && Temp[0] <= '3'){
			switch (Temp[0]){
				case '1':
					test_strategy = new Test_Strategy_TF(data);
					break;
				case '2':
					test_strategy = new Test_Strategy_Multi(data);
					break;
				case '3':
					return;
			}
			test_strategy->Init();
			int temp; std::string Temp_Word; int correct = 0;
			while (!test_strategy->End()){
				Out->Print(test_strategy->Get_Query(test_strategy->Get_Word()));
				Temp.clear(); getline(std::cin, Temp);
				while (!test_strategy->Check(Temp)){
					Temp.clear(); getline(std::cin, Temp);
				}
				Out->Print(test_strategy->Work(test_strategy->Test_Word(Temp)));
			}
			std::stringstream ss; ss << test_strategy->Get_Level(); Temp.clear(); ss >> Temp;
			Out->Print(get_out_console[45] + Temp);
		}
	}
}
void Console::NewWords(){
	if (newwords_strategy) delete newwords_strategy;
	newwords_strategy = new NewWords_Strategy2(Current_User, data);
	Out->Print(get_out_console[46]);
	std::string Temp_filename;
	getline(std::cin, Temp_filename);
	Out->Print(newwords_strategy->Run(Temp_filename));
}
void Console::Setup(){
	std::ifstream Fin;
	#ifdef _WIN32
		Fin.open("User_Windows.txt");
	#else
		Fin.open("User_linux.txt");
	#endif
	std::string get_in;
	while(getline(Fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	Fin.close();
	std::string temp_name;
	std::string temp_password;
	std::string flag;
	Out->Print(get_out_console[19]);
	Out->Print(get_out_console[20]);
	getline(std::cin, flag);
	while(!(flag.size() == 1 && (flag[0] == '1' || flag[0] == '2')))
	{
		Out->Print(get_out_console[21]);
		flag.clear(); 
		getline(std::cin, flag);
	}
	if(flag[0] == '1')   //register
	{
		std::string temp;
		std::string name;
		std::string password;
		std::ofstream fout;        //此处没有管mac, 需要改动 
		//#ifdef _WIN32
		//	fout.open("User\\account.txt", std::ios::app);
		//#else
			fout.open("User/account.txt", std::ios::app);
		//#endif
		Out->Print(get_out_console[22]);
		temp.clear();
		getline(std::cin, temp);
		name = temp;
		temp_name = name;
		fout<<temp<<std::endl;
		Out->Print(get_out_console[23]);
		password.clear();
		getline(std::cin, password);
		fout<<password<<std::endl;
		fout.close();
		std::string filename;
		//#ifdef _WIN32
		//	filename = "User\\";
		//#else
			filename = "User/";
		//#endif
		filename += name;
		filename += "MemorizedWords.txt";
		fout.open(filename);
		temp.clear();
		Out->Print(get_out_console[24]);
		temp.clear();
		getline(std::cin, temp);
		while(temp != password)
		{
			Out->Print(get_out_console[25]);
			temp.clear();
			getline(std::cin, temp);
		}
		
		Out->Print(get_out_console[26]);
		Out->Print(get_out_console[27]);
		Out->Print(get_out_console[28]);
		flag.clear();
		getline(std::cin, flag);
		while(!(flag.size() == 1 && flag[0] >= '1' && flag[0] <= '5'))
		{
			Out->Print(get_out_console[29]);
			flag.clear();
			getline(std::cin, flag);
		}
		char b1 = flag[0];
		
		Out->Print(get_out_console[30]);
		Out->Print(get_out_console[31]);
		Out->Print(get_out_console[32]);
		flag.clear();
		getline(std::cin, flag);
		while(!(flag.size() == 1 && flag[0] >= '1' && flag[0] <= '2'))
		{
			Out->Print(get_out_console[33]);
			flag.clear(); 
			getline(std::cin, flag);
		}
		fout<<flag[0]<<" "<<b1;
		for(int i = 1; i <= 16; i++)
			fout<<std::endl;
		fout.close();
		//#ifdef _WIN32
		//	filename = "User\\";
		//#else
			filename = "User/";
		//#endif
		filename += name;
		filename += "Examples.txt";
		fout.open(filename);
		fout.close();
	}
	else if(flag[0] == '2')   //login
	{
		std::string file_temp_name;
		std::string file_temp_password;
		std::ifstream fin;
		int p = 0, found = 0;
		do
		{
			p = 0;
			found = 0;
			Out->Print(get_out_console[34]);
			temp_name.clear();
			getline(std::cin, temp_name);
			Out->Print(get_out_console[35]);
			temp_password.clear();
			getline(std::cin, temp_password);
			//#ifdef _WIN32
			//	fin.open("User\\account.txt", std::ios::app);
			//#else
				fin.open("User/account.txt");
			//#endif
			while(getline(fin, file_temp_name))
			{
				file_temp_name;
				if(p % 2 == 1)       //password line
				{
					p++;
					file_temp_name.clear();
					continue;
				}
				else         //user nameline
				{
					p++;
					if(file_temp_name == temp_name)
					{;
						getline(fin, file_temp_password);
						found = 1;
						break;
					}
				}
			}
			if(found != 0 && (file_temp_password == temp_password))
			{
				Out->Print(get_out_console[36]);
				break;
			}
			else
			{
				Out->Print(get_out_console[37]);
				fin.close();
			}
		}while(found == 0 || file_temp_password != temp_password);
	}
	Current_User = new User(data, temp_name);
	//分割线 
	switch (Current_User->Get_Memory_Strategy()){
		case 1:
			memory_strategy = new Memory_Strategy_Shanbay(Current_User, data);
			break;
		case 2:
			memory_strategy = new Memory_Strategy_Towords(Current_User, data);
			break;
	}
}
Console::Console(Database *temp_data, Output *temp_out):data(temp_data), Current_User(NULL), newwords_strategy(NULL), test_strategy(NULL), Out(temp_out)
{
	std::ifstream fin;
	#ifdef _WIN32
		fin.open("Console_Windows.txt");
	#else
		fin.open("Console_linux.txt");
	#endif
	std::string get_in;
	while(getline(fin, get_in))
	{
		get_out_console.push_back(get_in);
		get_in.clear();
	}
	fin.close();
}
void Console::Memory(){
	Out->Print(get_out_console[38]);
	std::string temp_input;
	temp_input.clear();
	int flag = 0;
	do
	{
		flag = 0;
		getline(std::cin, temp_input);
		for(int i = 0; i < temp_input.size(); i++)
			if(temp_input[i] < '0' || temp_input[i] > '9')
			{
				Out->Print(get_out_console[39]);
				flag = 1;
				temp_input.clear();
				break;
			}
	}while(flag != 0);
	int Word_Num = 0;
	for(int i = 0; i < temp_input.size(); i++)
		Word_Num += (temp_input[i] - '0') * pow(10, temp_input.size() - i - 1);
	memory_strategy->Init(Word_Num);	
	while(memory_strategy->Exist())
	{
		Out->Print(memory_strategy->Get_Query());      //获得题目 
		temp_input.clear();
		getline(std::cin, temp_input);
		while (!memory_strategy->Check(temp_input)){
			Out->Print(get_out_console[42]);
			temp_input.clear(); getline(std::cin, temp_input);
		}
		Out->Print(memory_strategy->Work(temp_input));
		Out->Print(get_out_console[43]);         //是否希望加入例句 
		temp_input.clear();
		getline(std::cin, temp_input);
		while(!(temp_input.size() == 1 && (temp_input[0] == 'Y' || temp_input[0] == 'N')))
		{
			Out->Print(get_out_console[42]);
			temp_input.clear();
			getline(std::cin, temp_input);
		}
		if(temp_input[0] == 'Y')
		{
			temp_input.clear();
			Out->Print(get_out_console[44]);
			getline(std::cin, temp_input);
			data->Add_Example(memory_strategy->First_Word(), temp_input);
			Current_User->Add_Example(memory_strategy->First_Word(), temp_input);
		}
		memory_strategy->After_Factory();
	}
	memory_strategy->Run();
	std::stringstream ss; ss << memory_strategy->Recited_Times; std::string A; A.clear(); ss >> A;
	Out->Print(get_out_console[40] + A + get_out_console[41]);
}
void Console::Run(){
	while (1){
		for (int i = 12; i <= 18; ++i) Out->Print(get_out_console[i]);
		std::string Temp;
		getline(std::cin, Temp);
		if (Temp.size() == 1 && Temp[0] >= '1' && Temp[0] <= '6'){
			switch (Temp[0]){
				case '1': Memory(); break;
				case '2': Search(); break;
				case '3': Test(); break;
				case '4': NewWords(); break;
				case '5': Change_Memory_Strategy(); break;
				case '6': return;
			}
		}
	}
}
