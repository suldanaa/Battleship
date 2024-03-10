#include <iostream>
using namespace std;
#include "ship.h"

//define ship.h functions here

//setters
void Ship::setLetter(string a){
    letter = a;
}
void Ship::setSpaces(int s){
    spaces = s;
}
void Ship::setRow(int r){
    row = r;
}
void Ship::setCol(int c){
    col = c;
}
void Ship::setOrientation(int o){
    orientation = o;
}


//getters
string Ship::getLetter(){
        return letter;
}
int Ship::getSpaces(){
        return spaces;
}
int Ship::getRow(){
        return row;
}
int Ship::getCol(){
        return col;
}
int Ship::getOrientation(){
        return orientation;
}