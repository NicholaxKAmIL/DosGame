#include <iostream>
#include "logo.h"
#include "clearScr.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, secon

#include <stdio.h>
#include <conio.h>

#include <stdlib.h>
#include <time.h>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

using namespace std;

int position,dis=50,qu=5; 

int quiz(){
	int x = rand() % (11) ;
	return x;
}

int game(int pos){
	char space[] = " ",car[] = "U";
	string Sarray;
	int s = qu;
	dis--;

	
	for(int i = 0;i<11;i++){
		
		if(pos!=0)Sarray += space;
		if(pos!=0&&s==0){
			if(dis ==0)
				Sarray += "T";
			else
				Sarray += "i";
		}
		if(pos == 0&&s != 0) Sarray += car;
		if(pos == 0&&s == 0) Sarray = Sarray + space+"M" ;
		
		if(pos == 0&&s == 0&&dis ==0){
			cout<<"BOOOOOOOM!"<<endl;
			return 0;
		}
		pos--;s--;
		 
	}

	cout<<"O"<<Sarray<<"O"<<endl;
	if(dis == 0){
		qu = quiz();
		dis = 50;
	}
	
	
}

int movement(int in){
	
	int KB_code=0;

	if (kbhit())
      {
        KB_code = getch();
        //printf("KB_code = %i \n",KB_code);

        switch (KB_code)
        {
            case KB_LEFT:
                       //Do something
                if(position!=0)position--;
            break;

            case KB_RIGHT:
            	if(position!=10)position++;
                       //Do something                     
            break;
		}
	}

}

int main(int argc, char** argv) {
	logo();
	//while?
		//game()
	//;
	while(1){	
		if(game(position)==0){
			cout<<"game over!"<<endl;
			string temp;
			cin>>temp;
			return 0;
		}
		movement(1);
		sleep_for(milliseconds(100));
		//ClearScreen();
	}
	return 0;
}

