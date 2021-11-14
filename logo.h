#include<windows.h> 
#include<iostream>

void setColor(int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void logo(){
	
	
	for(int i =1;i<20;i++){
		setColor(i);
		std::cout<<"Hi!";
	}
	setColor(15);

}


