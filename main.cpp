#include <iostream>
#include "ship.cpp"
#include <string>
#include <chrono>
#include <thread>
#include<ctime>

using namespace std;

const int ROWS = 10;
const int COLS = 10;
const int SIZE = 5;

void generateBoard(string[][COLS], Ship[]);
void generatePosition(int, string);
int randomNum(int, int);
void prompt();
void ending();
void warning();
void sleep(int);
void banner();
string time();
string userName;
char tutorial;
string userInput;
bool didTutorial = false;


int main(){
    string board[10][10];
    string tutorialBoard[10][10];

    //Initialize 5 instances of the ship class:
    Ship frigate;
    frigate.setLetter("F");
    frigate.setSpaces(2); 

    Ship sub;
    sub.setLetter("S");
    sub.setSpaces(3); 

    Ship destroyer;
    destroyer.setLetter("D");
    destroyer.setSpaces(3); 

    Ship battleship;
    battleship.setLetter("B");
    battleship.setSpaces(4);

    Ship aircraft;
    aircraft.setLetter("A");
    aircraft.setSpaces(5); 
    
    //array of ships
    Ship ships[SIZE] = {frigate, sub, destroyer, battleship, aircraft};

    //BACKSTORY/FUN STUFF
    cout << "Hello Commander!" <<endl;
    sleep(1);
    cout << "Welcome to BATTLESHIP, a game where you destroy your enemies before they destroy you!"<<endl;
    sleep(1);
    cout << "What's your name?" <<endl;
    cout << ">> ";
    cin >> userName;

    sleep(1);
    cout << "Excellent, Commander " << userName << " it is! It's got a nice ring to it, doesn't it?.\n";
    sleep(1);
    cout << "Please choose one of the options below:\n";
    cout << "START (S)|| TUTORIAL (T)";
    cout <<"\n>> ";
    cin >> tutorial;
    banner();

    if(tutorial == 'T'){
        didTutorial=true;
        cout << "\n[CAPTAIN'S LOG]: Commander Eric, we have entered enemy waters." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: They've taken down our sattelites." <<endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: The enemies are lurking somewhere in the 10x10 grid on our sonar.\n\t\t We must be cautious, as our sonar capabilities are limited, and won't update if they approach us." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: Let's stay vigilant and strike down our foes before they can locate and destroy us." << endl;
        sleep(1);
        cout << endl;
        sleep(1);

        //generate board
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                tutorialBoard[r][c] = "[ ]";
            }
        }

        for(int x = 0; x<5; x++){
            tutorialBoard[x][2] = "[A]";
        }

        cout << "  0  1  2  3  4  5  6  7  8  9\n";
        for (int r = 0; r < ROWS; r++)
        {
            //statement controls the side numbers/letters
            //65 is the ASCII for the uppcase A so the loop
            //iterates through the alphabet
            cout << (char)(65+r);
            for (int c = 0; c < COLS; c++)
            {
                cout << tutorialBoard[r][c];
            }
            cout << endl;
        }
        cout << endl;
        sleep(1);

        cout << "[CAPTAIN'S LOG]: You're not Commander Eric?" << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: You must be the new Commander, Commander " << userName << "." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: I will be teaching you the ropes. Pay attention, I don't have much time, danger is imminent." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: There are 5 enemies in total, all ranging in different sizes. A is an aircraft, it's the biggest of the enemies.\n";
        sleep(1);
        cout << "[CAPTAIN'S LOG]: Hurry, send a cannon at the aircraft by entering the coordinates A2.\n>> ";
        cin >> userInput;
        cout << endl;
        while(userInput!="A2"){
            cout << "[CAPTAIN'S LOG]: That's not A2!\n>> ";
            cin >> userInput;
        }
        sleep(1);
            if(userInput=="A2"){
            tutorialBoard[0][2] = "[X]";
            cout << "Hits: 1" << endl;
            cout << endl;
             cout << "  0  1  2  3  4  5  6  7  8  9\n";
            for (int r = 0; r < ROWS; r++)
            {
                //statement controls the side numbers/letters
                //65 is the ASCII for the uppcase A so the loop
                //iterates through the alphabet
                cout << (char)(65+r);
                for (int c = 0; c < COLS; c++)
                {
                    cout << tutorialBoard[r][c];
                }
                cout << endl;
            }
        }
        
        
        sleep(1);
        cout << endl;
        cout << "[CAPTAIN'S LOG]: Now try missing by hitting A0. You'll notice something.\n>> ";
        cin >> userInput;
        cout << endl;
         while(userInput!="A0"){
            cout << "[CAPTAIN'S LOG]: That's not A0!\n>> ";
            cin >> userInput;
        }
        sleep(1); 

            if(userInput=="A0"){
            
            tutorialBoard[0][0] = "[O]";
            cout << "Misses: 1" << endl;
            cout << "Hits: 1" << endl;
            cout << endl;
             cout << "  0  1  2  3  4  5  6  7  8  9\n";
            for (int r = 0; r < ROWS; r++)
            {
                //statement controls the side numbers/letters
                //65 is the ASCII for the uppcase A so the loop
                //iterates through the alphabet
                cout << (char)(65+r);
                for (int c = 0; c < COLS; c++)
                {
                    cout << tutorialBoard[r][c];
                }
                cout << endl;
            }
        }
         cout << endl;
        cout << "[CAPTAIN'S LOG]: We've recently upgraded to a smart sonar that allows us to track your misses." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: You're should be all set. Don't miss more than 15 times, or our enemies will locate our ship and destroy it." <<endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: Our life is in your hands, Commander " << userName << "." <<endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: Captain's Log, " << endl;
        sleep(1);
        cout << "\t\t " << time();
        sleep(1);
        cout << "\t\t ,signing off." <<endl;
        sleep(1);
        banner();


        cout << "\nSTART (S)|| TUTORIAL (T)";
        cout <<"\n>> ";
        cin >> tutorial;
        if(tutorial == 'S'){
            generateBoard(board, ships); 
        }
        else{
            cout << "[CAPTAIN'S LOG]: There's no time!" << endl;
            cout << endl;
            generateBoard(board, ships); 
        }
    }
    else{
        generateBoard(board, ships); 
    }
       


    

    return 0;
}

//Create the board
void generateBoard(string arr[][COLS], Ship ships[]){

    if(!(didTutorial)){
        cout << "\n[CAPTAIN'S LOG]: Commander "<< userName <<", we have entered enemy waters." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: They've taken down our sattelites." <<endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: The enemies are lurking somewhere in the 10x10 grid on our sonar.\n\t\t We must be cautious, as our sonar capabilities are limited, and won't update if they approach us." << endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: Let's stay vigilant and strike down our foes before they can locate and destroy us." << endl;
        sleep(1);
        cout << endl;
        sleep(1);
    }


    for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			arr[r][c] = "[ ]";
		}
	}

    for(int x = 0; x < SIZE; x++){
        //random number to determine row
        ships[x].setRow(randomNum(x,10));

        //random number to determine column
        ships[x].setCol(randomNum(x+1,10));
        
        //random number to determine vertical (Down)/horizontal(Right) (1/0)
        ships[x].setOrientation(randomNum(x+(randomNum(x,2)),2)); 

        //determine spaces size of ship will need
        if(ships[x].getOrientation() == 1){  //if vertical
       
             while((9-ships[x].getRow()) < (ships[x].getSpaces()) && (9-ships[x].getRow()) < (ships[x].getSpaces())){ //while it doesn't fit
                ships[x].setRow(randomNum(x+1,10));  //keep generating numbers until it does fit
              
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
             //cout << ships[x].getLetter() << " has a vertical orientation and we're trying to find the rows" << endl;

             int endRow = ((ships[x].getSpaces()-1)+ships[x].getRow()); //last legal row

             for(int y = ships[x].getRow(); y < endRow+1; y++){ 
                //rerun the original row determing logic
                    int counter = 0;
                    while(arr[y][ships[x].getCol()] != "[ ]"){ //if it's occupied
                                 if((ships[x].getRow()+ships[x].getSpaces()-1)==endRow){
                                    // cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                    ships[x].setRow(counter);
                                    y = ships[x].getRow();
                                    if(ships[x].getCol()==9){
                                        ships[x].setCol(0);
                                    }
                                    else{
                                        ships[x].setCol(ships[x].getCol()+1);
                                    }
                                    // cout << "Repositioning..." << endl;
                                    // cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                                else{
                                     //cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                     ships[x].setCol(ships[x].getCol()+1);
                                    //  cout << "Repositioning..." << endl;
                                    //  cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                            
                    }
             }
             }


            if(ships[x].getOrientation() == 0) { //horizontal --> (deals with cols)
            //cout << ships[x].getLetter() << " has a horizontal orientation and we're trying to find the columns" << endl;

            int endCol = ((ships[x].getSpaces()-1)+ships[x].getCol());

            for(int y = ships[x].getCol(); y<endCol+1; y++){ 
                    int counter = 0;
                    while(arr[ships[x].getRow()][y] != "[ ]"){ //while it's still not open
                                if((ships[x].getCol()+ships[x].getSpaces()-1)==endCol){
                                    //cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                    ships[x].setCol(counter);
                                    y = ships[x].getCol();
                                    if(ships[x].getRow()==9){
                                        ships[x].setRow(0);
                                    }
                                    else{
                                        ships[x].setRow(ships[x].getRow()+1);
                                    }
                                    // cout << "Repositioning..." << endl;
                                    // cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                                else{
                                     //cout << "Current Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                     ships[x].setRow(ships[x].getRow()+1);
                                    //  cout << "Repositioning..." << endl;
                                    //  cout << "New Row Column : " << ships[x].getRow() << " and " << ships[x].getCol() << endl;
                                }
                                
                    }

            }
            }
            
            // cout << "**************************" << endl;
            // cout << "* \t Success! \t *" << endl;
            // cout << "**************************" << endl;

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

    // cout << "ROW/COL" << endl;
    // for(int x = 0; x < SIZE; x++){
    //     cout << ships[x].getLetter();
    //     cout << "[" << ships[x].getRow() << "," << ships[x].getCol() << "]"<< endl;
    // }

    // cout << "ORIENTATION" << endl;
    // for(int x = 0; x < SIZE; x++){
    //     if(ships[x].getOrientation() == 1){
    //         cout << ships[x].getLetter() << "'s orientation is VERTICAL" << endl;
    //     }
    //     else{
    //         cout << ships[x].getLetter() << "'s orientation is HORIZONTAL" << endl;
    //     }
    // }
    ////****************

    //arr[currentRow][currentCol] = "[X]";

	//Show the current position on the board
	cout << "  0  1  2  3  4  5  6  7  8  9\n";
	for (int r = 0; r < ROWS; r++)
	{
        //statement controls the side numbers/letters
        //65 is the ASCII for the uppcase A so the loop
        //iterates through the alphabet
		cout << (char)(65+r);
		for (int c = 0; c < COLS; c++)
		{
			cout << arr[r][c];
		}

		cout << endl;
	}
    
    int miss=0;
    int hit=0;
    int filler=0; //needs to be here to catch something interferring with the incrementing values
    while(true){ //<----
    //C string wil allow you to isolate each part of the position
    char rowCol[2];
    prompt();
    cin >> rowCol;
    //cout << "[" << rowCol[0] << "," << rowCol[1] << "]" << endl;
    if(rowCol[0]=='-'){
        cout << "Quitting...";
        exit(0);
    }
    else if(rowCol[0]>(char)74 || rowCol[0]<(char)65){
        cout << "Only input letters between A-J for the first coordinate!" << endl;
    }
    else{
        for(int x = 0; x<ROWS; x++){
            if(rowCol[0] == (char)(65+x)){ 

                int row = x;
                int col = rowCol[1]-48;
                
                if(arr[row][col] != "[ ]" && arr[row][col] != "[O]" && arr[row][col] != "[X]"){
                    arr[row][col] = "[X]";
                    filler++; //needs to be here to catch something interferring with the incrementing values
                    hit++;
                }
                else if(arr[row][col] == "[ ]"){
                    arr[row][col] = "[O]";
                    miss++;
                }
                else if(arr[row][col] == "[O]" || arr[row][col] == "[X]"){
                    cout << "You cannot rehit spots you've already targetted!" << endl;
                }
            }
        }

    cout << "Misses: " << miss << endl;
    cout << "Hits: " << hit << endl;
    cout << endl;
    if(miss==10){
        warning();
    }
    cout << "  0  1  2  3  4  5  6  7  8  9\n";
	for (int r = 0; r < ROWS; r++)
	{
        //statement controls the side numbers/letters
        //65 is the ASCII for the uppcase A so the loop
        //iterates through the alphabet
		cout << (char)(65+r);
		for (int c = 0; c < COLS; c++)
		{
			cout << arr[r][c];
		}

		cout << endl;
    }
    if(hit==17){
        cout << endl;
        if(!(didTutorial)){
        cout << "[CAPTAIN'S LOG]: Captain " << userName << ", are you sure this is your first time?" << endl;
        sleep(2);
        }
        cout << "[CAPTAIN'S LOG]: Excellent performance. You've managed to destroy every last ship."<< endl;
        sleep(2);
        cout << "[CAPTAIN'S LOG]: You may now retreat."<< endl;
        sleep(1);
        cout << "[CAPTAIN'S LOG]: Captain's Log, " << endl;
        sleep(1);
        cout << "\t\t " << time();
        sleep(1);
        cout << "\t\t ,signing off." <<endl;
        sleep(1);

        cout << "You won!";
        break;
    }
    else{
        if(miss==15){
        ending();
        exit(0);
        }
    }

    }
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

void prompt(){
    cout << "\nEnter the position you'd like to attack OR Enter -1 to Quit" << endl;
    cout << ">> ";
};

void ending(){
    cout << "\n[CAPTAIN'S LOG]: Mayday, Mayday, Mayday. This is the Captain of the USS John Paul Jones."<< endl;
    sleep(2);
    cout <<"[CAPTAIN'S LOG]: We are located at grid A11. The USS John Paul Jones has been located and has been critically hit." << endl;
    sleep(2);
    cout << "[CAPTAIN'S LOG]: We are in need of immediate assistance. Crew evacuating to lifeboats." << endl;
    sleep(2);
    cout << "[CAPTAIN'S LOG]: I repeat, Mayday." << endl;
    sleep(1);
    cout << "[CAPTAIN'S LOG]: Captain's Log, " << endl;
    sleep(1);
    cout << "\t\t " << time();
    sleep(1);
    cout << "\t\t ,signing off." <<endl;
    sleep(1);
    cout << "You lost!";

    
}

void warning(){
    cout << "[CAPTAIN'S LOG]: Commander " << userName << "! What are you doing?! If you miss 5 more times our ship will sink. Get it together!" << endl;
    cout << endl;
}

void sleep(int second){
    using namespace this_thread; // sleep_for, sleep_until
    using namespace chrono; // nanoseconds, system_clock, seconds

    sleep_until(system_clock::now() + seconds(second));
}

void banner(){
            cout << "\n********************************************************************************\n********************************************************************************" << endl;
}

string time(){
    time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);

    return asctime(tt);
}
