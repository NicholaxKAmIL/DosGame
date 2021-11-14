#include <iostream>
#include "functions.h"
int pogCPP = 150;
int livesCPP = 4;

int main(){
	
	logo(13);
	
	while(1){	
		if(game(position)==0 && gameOver == false){
			livesCPP--;
			revival(livesCPP, pogCPP);
		}
		
		movement(1);
		
		pogCPP = fps(pogCPP);
		
		sleep_for(milliseconds(pogCPP));
		//ClearScreen();
	}
	return 0;
}
