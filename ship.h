#ifndef SHIP_H
#define SHIP_H

//Create the ship class
class Ship{
    private:
    string letter;
    int spaces;
    int row;
    int col;
    int orientation;

    public:
    //do prototypes
    void setLetter(string a);
    void setSpaces(int s);
    void setRow (int r);
    void setCol (int c);
    void setOrientation (int o);

    string getLetter();
    int getSpaces();
    int getRow();
    int getCol();
    int getOrientation ();

};

#endif 