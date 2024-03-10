#include <iostream>
#include "ship.cpp"
#include <string>

using namespace std;

const int ROWS = 10;
const int COLS = 10;
const int SIZE = 5;

void generateBoard(string[][COLS], Ship[]);
void generatePosition(int, string);
int randomNum(int, int);


int main(){
   
    string board[10][10];

    //Initialize 5 instances of the ship class:
    Ship frigate;
    frigate.setLetter("F");
    frigate.setSpaces(2); //good, 2

    Ship sub;
    sub.setLetter("S");
    sub.setSpaces(3); //good, 3

    Ship destroyer;
    destroyer.setLetter("D");
    destroyer.setSpaces(3); //good, 3

    Ship battleship;
    battleship.setLetter("B");
    battleship.setSpaces(4); //good

    Ship aircraft;
    aircraft.setLetter("A");
    aircraft.setSpaces(5); //godd
    
    //array of ships
    Ship ships[SIZE] = {frigate, sub, destroyer, battleship, aircraft};

    generateBoard(board, ships);
    
    return 0;
}

//Create the board
void generateBoard(string arr[][COLS], Ship ships[]){

    for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			arr[r][c] = "[ ]";
		}
	}

	//cout << "Your current position on the board is [" << currentRow << "][" << currentCol << "] \n";

        //for loop for each ship
    for(int x = 0; x < SIZE; x++){
        //random number to determine row
        ships[x].setRow(randomNum(x,10));

        //random number to determine column
        ships[x].setCol(randomNum(x+1,10));
        
        //random number to determine vertical (Down)/horizontal(Right) (1/0)
        ships[x].setOrientation(randomNum(x+(randomNum(x,2)),2)); 

        //cout << "We just set the rows, cols, and orientation!" << endl;

        //determine spaces size of ship will need
        if(ships[x].getOrientation() == 1){  //if vertical
        //i need to make it so it compares the ship rows with past oones and see if they're occupied
             while((9-ships[x].getRow()) < (ships[x].getSpaces()) && (9-ships[x].getRow()) < (ships[x].getSpaces())){ //while it doesn't fit
                ships[x].setRow(randomNum(x+1,10));  //keep generating numbers until it does fit
                //cout << "Determining spaces the ship will need vertically..." << endl;
             }
        }
        
        if(ships[x].getOrientation() == 0){  //if horizontal
                while((9-ships[x].getCol()) < ships[x].getSpaces() && (9-ships[x].getCol()) < (ships[x].getSpaces())){ //while it doesn't fit
                    ships[x].setCol(randomNum(x+1,10));
                    //cout << "Determining spaces the ship will need horizontally..." << endl;
                }
        }

            // now check if the next rows are occupied
            if(x!=0){
            
             if(ships[x].getOrientation() == 1) { //vertical ↓ (deals with rows)
             cout << ships[x].getLetter() << " has a vertical orientation and we're trying to find the rows" << endl;

             int endRow = ((ships[x].getSpaces()-1)+ships[x].getRow()); //last legal row

             for(int y = ships[x].getRow(); y < endRow+1; y++){ 
                //rerun the original row determing logic
                    int counter = 0;
                    while(arr[y][ships[x].getCol()] != "[ ]"){ //if it's occupied
                                 if((ships[x].getRow()+ships[x].getSpaces()-1)==endRow){
                                    cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                    ships[x].setRow(counter);
                                    y = ships[x].getRow();
                                    if(ships[x].getCol()==9){
                                        ships[x].setCol(0);
                                    }
                                    else{
                                        ships[x].setCol(ships[x].getCol()+1);
                                    }
                                    cout << "Repositioning..." << endl;
                                    cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                                else{
                                     cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                     ships[x].setCol(ships[x].getCol()+1);
                                     cout << "Repositioning..." << endl;
                                     cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                            //cout << "First while loop..." << endl;  
                            //loading();
                            //cout << "This is the row: " << ships[x].getRow() << endl;
                            
                    }
             }
             }


            if(ships[x].getOrientation() == 0) { //horizontal --> (deals with cols)
            cout << ships[x].getLetter() << " has a horizontal orientation and we're trying to find the columns" << endl;

            int endCol = ((ships[x].getSpaces()-1)+ships[x].getCol());

            for(int y = ships[x].getCol(); y<endCol+1; y++){ 
                    int counter = 0;
                    while(arr[ships[x].getRow()][y] != "[ ]"){ //while it's still not open
                                if((ships[x].getCol()+ships[x].getSpaces()-1)==endCol){
                                    cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                    ships[x].setCol(counter);
                                    y = ships[x].getCol();
                                    if(ships[x].getRow()==9){
                                        ships[x].setRow(0);
                                    }
                                    else{
                                        ships[x].setRow(ships[x].getRow()+1);
                                    }
                                    cout << "Repositioning..." << endl;
                                    cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                                else{
                                     cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                     ships[x].setRow(ships[x].getRow()+1);
                                     cout << "Repositioning..." << endl;
                                     cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                                
                    }

            }
            }
            
            cout << "**************************" << endl;
            cout << "* \t Success! \t *" << endl;
            cout << "**************************" << endl;

            }

            //put the ship on the board
            if(ships[x].getOrientation() == 1) { //vertical
                for(int y = ships[x].getRow(); y < ships[x].getRow()+ships[x].getSpaces(); y++){
                    arr[y][ships[x].getCol()] = "[" + ships[x].getLetter() + "]";
                }
            }

            if(ships[x].getOrientation() == 0) { //horizontal
                for(int y = ships[x].getCol(); y < ships[x].getCol()+ships[x].getSpaces(); y++){
                    arr[ships[x].getRow()][y] = "[" + ships[x].getLetter() + "]";
                }
            }
     }

    //***** TEST *****

    cout << "ROW/COL" << endl;
    for(int x = 0; x < SIZE; x++){
        cout << ships[x].getLetter();
        cout << "[" << ships[x].getRow() << "," << ships[x].getCol() << "]"<< endl;
    }

    cout << "ORIENTATION" << endl;
    for(int x = 0; x < SIZE; x++){
        if(ships[x].getOrientation() == 1){
            cout << ships[x].getLetter() << "'s orientation is VERTICAL" << endl;
        }
        else{
            cout << ships[x].getLetter() << "'s orientation is HORIZONTAL" << endl;
        }
    }
    ////****************

    //arr[currentRow][currentCol] = "[X]";

	//Show the current position on the board
	cout << "  0  1  2  3  4  5  6  7  8  9\n";
	for (int r = 0; r < ROWS; r++)
	{
		cout << r;
		for (int c = 0; c < COLS; c++)
		{
			cout << arr[r][c];
		}

		cout << endl;
	}
}

//random number generator
int randomNum(int index, int upperbound){
    int arr[100];
    srand(time(0));

    for(int x=0;x<100;x++){
        arr[x] = (rand() % upperbound); 
    }
    //cout << "We used the randomNum function!" << endl;
    return arr[index];
}

