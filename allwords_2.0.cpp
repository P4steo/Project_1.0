#include <iostream>
#include <string>
#include <vector>
#include <fstream> //odczyt danych z pliku
#include <sstream> //odczyt
#include <unistd.h> //sleep

struct Words{
	std::string wordst, wordnd;
	Words(std::string word1, std::string word2) {
		wordst = word1;
		wordnd = word2;
	}
	Words(){}
};

void Main_Menu(){
	std::cout<<"---\e[91mAll\e[0m\e[92mWords\e[0m---\n";
	std::cout<<"\e[47m                               \e[0m\n";
	std::cout<<"\e[31;1m  -------MAIN MENU-------\e[0m\n";
	std::cout<<"\e[93m 1.  <Open database> \n";
	std::cout<<" 2.  <Create new database>\n";
	std::cout<<" 3.        <Exit>\e[0m \n ";
}

//void Errors{}

int main(){
	std::string insert,nameoffile;
	int option;
	while (true) {
		system("clear");
		Main_Menu();
		std::cout<<"\e[3mType option: \e[0m";
		//Errors(option);
		std::cin>>option;
		system("clear");

		std::vector <Words> database; //case 1 (open)
		std::vector <Words> newdatabase; //case 2 (create)
		std::fstream dane;

		switch (option){
			case 3: {
				std::cout<<"\e[32mSee You Later!\e0m\n";
				usleep(100000);
				for (int i=0; i<8; i++) {
					for (int j=0; j<=i; j++) {
						std::cout<<" \n";
					}
				std::cout<<"\e[94mAllWords by P4steo\e[0m\n";
				usleep(100000);
				system("clear");
				return 0;
			} //case 3 nawias

			case 1: {
				std::cout<<"\e[91mType \"Exit\" to back to Main Menu: \e[0m"<<std::endl;
				std::cout<<"\e[3mInsert name of file, which content You want to use: \e[0m";
				std::cin>>insert;
				if (insert == "Exit"){
					break;
				}
				nameoffile = insert + ".txt";
				dane.open(nameoffile, std::ios::in);

				if (!dane.good()){
					std::cout<<"\e[96mFile did not open\e[0m\n";
					usleep(1000000);
					system("clear");
					std::cout<<"\e[91mType \"Exit\" to back to Main Menu: \e[0m"<<std::endl;
					std::cin>>insert;
					break;
				}
				if (dane.eof())
					std::cout<<"\e[96mFile is empty\e[0m\n";

				std::string line;

				while (std::getline(dane, line)) {
					std::string buf;
					std::stringstream ss(line);
					std::string s1, s2;

					ss >> s1;
					ss >> s2;
					database.push_back(Words(s1, s2));
				}

				for (int i=0; i<database.size(); ++i) {
					std::cout<<"\e[[33m"<<database[i].wordst<<" - "<<database[i].wordnd<<"\e[0m\n"; //kolor myslnika
				}
				usleep(1000000);

				int optswitch;
				std::cout<<"\e[31;1m---MENU---\e[0m\n";
				std::cout<<"\e[93m 1. <Learn>\n";
				std::cout<<" 2. <Back to Main Menu>\e[0m\n";
				std::cout<<"\e[3mType option: \e[0m";
				std::cin>>optswitch;

				while (optswitch>2 || optswitch<1) {
					std::cout<<"\e[96mError - invalid number\e[0m\n";
					std::cout<<"\n";
					std::cout<<"\e[3mType a correct option: \e[0m";
					std::cin>>optswitch;
				}

				switch (optswitch) {
					case 1: {
						std::string word;
						std::vector <int> mistakestab; //tablica blednych odpowiedzi (indexy)
						int lp=0;
						system("clear");

						for (int k=0; k<database.size(); ++k) {
							std::cout<<database[k].wordnd<<" - ";
							std::cin>>word;
							if (word==database[k].wordst) {
								std::cout<<"\e[92mCorrect!\e[0m\n";
								usleep(1000000);
								system("clear");
							}
							else {
								std::cout<<"\e[91mWrong!\e[0m";
								usleep(1000000);
								system("clear");
								std::cout<<"\e[33m"<<database[k].wordst<<"\e[0m"<<std::endl;
								usleep(1000000);
								system("clear");
								mistakestab.push_back(k);
							}
						}

						while (mistakestab.size()>0) {
							int lp=0;
							for (auto element : mistakestab) {
								std::cout<<database[element].wordnd<<" - ";
								std::cin>>word;
								if (word==database[element].wordst) {
									std::cout<<"\e[92mCorrect!\e[0m\n";
									usleep(1000000);
									system("clear");
									mistakestab.erase(mistakestab.begin()+(lp));
								}
								else {
									std::cout<<"\e[91mWrong!\e[0m\n";
									usleep(1000000);
									std::cout<<"\e[33m"<<database[element].wordst<<"\e[0m"<<std::endl;
									usleep(1000000);
									system("clear");
								}
								lp++;
							} //for
						} //while

						std::cout<<"\e[92mAll Words passed\e[0m\n";
						usleep(1000000);
						break;
					} //case 1 w case 1

					case 2: {
						usleep (10000);
						break;
					} // case 2 w case 1

				} //switch w case 1

				case 2: {
					system("clear");
					std::string word1, word2;
					int case2opt;
					std::cout<<"\e[31;1m---MENU---\e[0m\n";
					std::cout<<"\e[93m 1. <New database>\n";
					std::cout<<" 2. <Edit database>\n";
					std::cout<<" 3. <Exit>\e[0m\n";
				} //case 2
	                        case 3: {
        	                        std::cout<<"\e[32mSee You Later!\e0m\n";
                	                usleep(100000);
                        	        for (int i=0; i<8; i++) {
                                	        for (int j=0; j<=i; j++) {
                                        	        std::cout<<" \n";
                                        	}

                                		std::cout<<"\e[94mAllWords by P4steo\e[0m\n";
                               	 		usleep(100000);
                                		system("clear");
					}
                                	return 0;
                        	} //case 3 nawias

			}//switch głowny
		}//while true
	}//int main

