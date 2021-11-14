#include<iostream>
using namespace std;
void ClearScreen(){
	for(int i = 0;i<29;i++)
	cout<<"o"<<"           "<<"o"<<i<<endl;
  }
  
#include <windows.h>

#define FOREGROUND_BLUE       0x0001 
#define FOREGROUND_GREEN      0x0002 
#define FOREGROUND_RED        0x0004
#define FOREGROUND_PURPLE     0x0005
#define FOREGROUND_INTENSITY  0x0008 

int color(int in){
	cout<<"1 = red, 2 = green, 3 = blue or 4 = purple"<<endl;
	cin>>in;
	if (in == 1){
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_RED );
	}
	if (in == 2){
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN );
	}
	if (in == 3){
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE );
	}
	if (in == 4){
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_PURPLE );
	}
}
