#include <iostream>
#include <string>
#include <vector>
#include <fstream> //odczyt danych z pliku
#include <sstream> //odczyt
#include <unistd.h> //sleeep
#include <random> //random

struct Words{
	std::string wordst, wordnd;
	Words(std::string word1, std::string word2) {
		wordst = word1;
		wordnd = word2;
	}
	Words(){}
};

bool Isnumber(int x) {
	return (x<9 | x>0);
}


int main(){
	std::string insert, nameoffile;
	int option;
	while (true) {
	system("clear");
	std::cout<<"---\e[91mAll\e[0m\e[92mWords\e[0m---\n";
	std::cout<<"\e[47m                               \e[0m\n";
	std::cout<<"\e[31;1m  -------MAIN MENU-------\e[0m\n";
	std::cout<<"\e[93m 1.  <Open database> \n";
	std::cout<<" 2. <Create database>\n";
	std::cout<<" 3.       <Exit>\e[0m \n ";
	std::cout<<"\e[3mType option: \e[0m";
	std::cin>>option;
	while (option>3 | option<1) {
                std::cout<<"\e[96mError - invalid number\n\e[0m";
                std::cout<<"\n";
                std::cout<<"\e[3mType correct option: \e[0m";
                std::cin>>option;
	}
	system("clear");
        std::vector <Words> database;
        std::fstream dane; //obiekt typu fstream
       /* std::cout<<"Insert name of file: ";
        std::cin>>insert;
        nameoffile = insert + ".txt";
        dane.open(nameoffile, std::ios::in); */
//////////////////////////////////////////////////
	switch(option){
	case 3:
		std::cout<<"B\n";
		usleep(500000);
		system("clear");
                std::cout<<"Y\n";   
                usleep(500000);
                system("clear");
                std::cout<<"E\n";   
                usleep(500000);
                system("clear");
                std::cout<<"\e[94mAllWords by P4steo\n";   
                usleep(100000);
		system("clear");
		std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n";   
                usleep(100000);
		system("clear");
		std::cout<<" \n";
		std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n";   
                usleep(100000);
                system("clear");
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n\e[0m";   
                usleep(100000);
                system("clear");
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<"\e[91mAllWords by P4steo\n\e[0m";   
                usleep(1000000);
                system("clear");
		return 0;
	case 1 :
	std::cout<<"\e[3mInsert name of file: \e[0m";
        std::cin>>insert;
        nameoffile = insert + ".txt";
        dane.open(nameoffile, std::ios::in);

	if (!dane.good()){
		std::cout<<"\e[96mFile did not open\n\e[0m";
	}
	if (dane.eof()){
		std::cout<<"\e[96mFile is empty\n\e[0m";
	}
	std::string line;

	while (std::getline(dane, line))
	 {
		std::string buf;
		std::stringstream ss(line);
		std::string s1, s2;

		ss >> s1;
		ss >> s2;
		database.push_back(Words(s1, s2));
	}

	for (int i=0; i<database.size(); ++i) {
		std::cout<<"\e[33m"<<database[i].wordst<<" "<<database[i].wordnd<<"\n\e[0m";
	}
	usleep(1000000);
	int optswitch;
	std::cout<<"\e[31;1m---MENU---\e[0m\n";
	std::cout<<"\e[93m 1. <Learn>\n";
	std::cout<<" 2. <Exit>\n\e[0m";
	std::cout<<"\e[3mType option: \e[0m";
	std::cin>>optswitch;
	while (optswitch>2 | optswitch<1) {
		std::cout<<"\e[96mError - invalid number\n\e[0m";
		std::cout<<"\n";
		std::cout<<"\e[3mType correct option: \e[0m";
		std::cin>>optswitch;
	}
	switch (optswitch) {
	case 2 :
	usleep(10000);
	break;
	case 1 :
	std::string word;
	std::vector <int> mistakestab; //tablica z indexami błednych odpowiedzi
	int lp=0;
	system("clear");
	for (int j=0; j<database.size(); ++j) {
		std::cout<<database[j].wordnd<<" - ";
		std::cin>>word;
		if (word==database[j].wordst) {
			std::cout<<"\e[92mCorrect!\n\e[0m";
			usleep(1000000);
			system("clear");
		}
		else {
			std::cout<<"\e[91mWrong!\n\e[0m";
			usleep(1000000);
			system("clear");
			std::cout<<"\e[33m"<<database[j].wordst<<"\e[0m"<<std::endl;
			usleep(1000000);
			system("clear");
			mistakestab.push_back(j); //zapisywanie indexu błedu
		}
	lp++;
	}//for
	while (mistakestab.size()>0) { //jeśli mamy jakies błedy program nas z nich odpyta
		int lp=0;
		for (auto element : mistakestab) {
                std::cout<<database[element].wordnd<<" - ";
                std::cin>>word;
                if (word==database[element].wordst) {
                        std::cout<<"\e[92mCorrect!\n\e[0m";
                        usleep(1000000);
                        system("clear");
			mistakestab.erase(mistakestab.begin()+(lp)); //jeśli dobrze odpowiedzieliśmy usuwamy index
                }
                else {
                        std::cout<<"\e[91mWrong!\n\e[0m";
                        usleep(1000000);
			std::cout<<"\e[33m"<<database[element].wordst<<"\e[0m"<<std::endl;
                        usleep(1000000);
                        system("clear");

                }
        lp++;
        	}//for
	}//while

	break;
	}//switch w casie
	}//switch
}//while true
}
