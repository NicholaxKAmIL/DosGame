#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, secon

#include <stdio.h>
#include <conio.h>

#include <stdlib.h>
#include <time.h>

#include <windows.h>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

using namespace std;

bool gameOver = false;

void setColor(int fg, int bg){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg);
}

void logo(int input){
	
	setColor(4, 0);
	
		int x = (input - 1)/4;
		int c = x;
	for(int i = 0 ; i < x ; i++){
		for(int l = i;l > 0;l--) cout<<" ";
		for(int k = 4 * x + (-x + 2 * (x + (x-3)/2 - i - 1)); k > 0; k--)	cout<<"W";
		cout<<endl;
	}

	for(int i = 1 ; i < x ; i++){
		for(int l = i;l > -x+1;l--) cout<<" ";
		for(int k = -2 * i + (2*x - 1); k > 0; k--)	cout<<"W";
		
		setColor(11, 0);
		
		for(int k = -2 * c + (2*x + 1); k > 0; k--)	cout<<"W";
		c--;
		
		setColor(4, 0);
		
		for(int k = -2 * i + (2*x - 1); k > 0; k--)	cout<<"W";
		cout<<endl;
	}
	c=1;
	int temp = false;
	for(int i = x ; i > 0 ; i--){
		if(temp == false){
			for(int l = i;l > -x+2;l--) cout<<" ";
			temp = true;
		}else if(temp == true){
			for(int l = i;l > -x+1;l--) cout<<" ";
		}
		
		setColor(8, 0);
		
		for(int k = -2 * i + (2*x - 1); k > 0; k--)	cout<<"W";
		
		setColor(11, 0);
		
		for(int k = -2 * c + (2*x +1); k > 0; k--)	cout<<"W";
		c++;
		
		setColor(8,0);
		for(int k = -2 * i + (2*x - 1); k > 0; k--)	cout<<"W";
		cout<<endl;
	}
	for(int i = x ; i > 0 ; i--){
		for(int l = i - 1;l > 0;l--) cout<<" ";
		for(int k = 4 * x + (-x + 2 * (x + (x-3)/2 - i)); k > 0; k--)	cout<<"W";
		cout<<endl;
	}
	setColor(15, 0);
}

int pts = 0;
int position,dis=50,qu=5; 

int score;

int quiz(){
	int x = rand() % (11);
	return x;
}

int points(){
	pts = pts + 10;
	return pts;
}



int fps(int tmp){
	int y = rand() % 11;
		
		if (y == 7 && tmp > 15){
			tmp = tmp - 3;
			cout<<"speedup"<<"         ";
		}else{
			cout<<"       "<<"         ";
		}
		return tmp;
}

int game(int pos){
	char space[] = " ",car[] = "U";
	string Sarray;
	int s = qu;
	dis--;

	
	for(int i = 0;i<11;i++){
		
		if(pos!=0)Sarray += space;
		if(pos!=0&&s==0){
			if(dis == 0)
				Sarray = Sarray  + "t";
			else
				Sarray = Sarray + "i";
		}
		if(pos == 0&&s != 0) Sarray += car;
		if(pos == 0&&s == 0) Sarray = Sarray + space+"M" ;
		
		if(pos == 0&&s == 0&&dis ==0){
			cout<<"BOOOOOOOM!"<<endl;
			return 0;
		}
		pos--;s--;
		 
	}

	cout<<"O"<<Sarray<<"O"<<"           "<<points()<<endl;
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

int revival(int lives, int pog){
	if(lives == 3){
		cout<<"would you like to use 50000 points to revive? [Yes(1)/No(0)]"<<endl;
		int tmp;
		cin>>tmp;
		if(tmp == 1){
			pts = pts - 50000;
			position = 3;
			dis = 50;
			qu=5; 
			while(1){	
			if(game(position)==0 && gameOver == false){
				lives--;
				revival(lives, pog);
			}
		
			movement(1);
		
			pog = fps(pog);
		
			sleep_for(milliseconds(pog));
			//ClearScreen();
			}
		}
	}
	if(lives == 2){
		cout<<"would you like to use 250000 points to revive? [Yes(1)/No(0)]"<<endl;
		int tmp;
		cin>>tmp;
		if(tmp == 1){
			pts = pts - 250000;
			position = 3;
			dis = 50;
			qu=5; 
			while(1){	
			if(game(position)==0 && gameOver == false){
				lives--;
				revival(lives, pog);
			}
		
			movement(1);
		
			pog = fps(pog);
		
			sleep_for(milliseconds(pog));
			//ClearScreen();
			}
		}		
	}
	if(lives == 1){
		cout<<"ngl ur kinda bad"<<endl;
		gameOver = true;
		cout<<"game over"<<endl;
	}
	gameOver = true;
	cout<<"game over"<<endl;
	while(1){
		int tmp;
		cin>>tmp;
	}
}


