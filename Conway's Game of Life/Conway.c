#include <stdio.h>
#include <stdlib.h>

char map[100][100];
void printMap();
void resetMap();
void reCalculate();
int liveNeighbours(int x, int y);
void randomifyMap();

int main(void){
	resetMap();
	randomifyMap(); //random entity spawn
	printf("Keep pressing Enter to update simulation");
	while(true){ //inf loop
		reCalculate(); //recalculate positions
		getchar(); //wait for input
		system("cls"); //clean console
		printMap();	//reprint
	}
}
void reCalculate(){
	for (int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(map[i][j] == ' '){ //if it's dead or empty		
				if (liveNeighbours(i,j) == 3){ //rule 4
					map[i][j] = 'x';// rule 4: Any dead cell with exactly three live neighbors becomes a live cell. 	
				}
			}else{ //it is alive
				if(liveNeighbours(i,j) < 2 || liveNeighbours(i,j) > 3){
					map[i][j] = ' ';//rule 2: Any live cell with more than three live neighbors dies, as if by overcrowding.
				}//rule 1: Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
			}// rule 3: Any live cell with two or three live neighbors lives on to the next generation. 
								
		}	
	}
}
int liveNeighbours(int x, int y){ //check neighbours for live entities
	int count = 0;
	if(map[x+1][y] == 'x'){
		count++;
	}
	if(map[x+1][y+1] == 'x'){
		count++;
	}
	if(map[x+1][y-1] == 'x'){
		count++;
	}
	if(map[x][y+1] == 'x'){
		count++;
	}
	if(map[x][y-1] == 'x'){
		count++;
	}
	if(map[x-1][y+1] == 'x'){
		count++;
	}
	if(map[x-1][y] == 'x'){
		count++;
	}
	if(map[x-1][y-1] == 'x'){
		count++;
	}
	return count;
}
void printMap(){
	for (int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			printf("%c", map[i][j]); //print out the value
			if(j==99)
				printf("\n"); //return at the end
		}	
	}
}
void resetMap(){
	//reset all values to empty
	for (int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			map[i][j] = ' ';//can be modified to change style
		}	
	}
}
void randomifyMap(){ //random config
	for (int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if ((rand() % 10) + 1 ==  1){ // 1 in 10 chance of spawning life
				map[i][j] = 'x';//can be modified to change style
			}else{
				map[i][j] = ' ';
			}
		}	
	}
}