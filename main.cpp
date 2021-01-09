#include <iostream>
#include "Map.h"
#include "MapInterface.h"
#include "solveMap.h"
#include "ZoneCounterInterface.h"
using namespace std;


//borderNumber is the number that is placed into map numerically
int borderNum = 10;

int main()
{
    cout << "Program Starts!" << endl;

    int regionNumber = 1; // it is necessary for counting the number of zones 

    // it is for creating object from Map class (Subclass) which obeys to MapInterface class (Superclass) 
    MapInterface* map1 = new Map();

    ZoneCounterInterface* solveObject = new solveMap();

    //with SetSize function, width and heigth are set.   [y][x]   //it is set as 36-24 acording to the document.
    map1->SetSize(36, 24);

    map1->GetSize(map1->width, map1->height);

    map1->Show();

    // these are the coordinates of border in the document. [row][colomn] 
    int borderCoord[88][2] = { {0,18},{1,16},{1,17},{2,15},{3,14,},{4,13},{4,12},{5,11},
    {6,10},{7,9},{7,8},{8,7},{9,6},{9,5},{10,5},{10,4},{11,3},{12,2},{13,1},
    {13,0},{11,6},{12,7},{13,7},{14,8},{15,8},{16,9},{17,9},{17,10},{17,11},
    {17,12},{18,10},{19,10},{20,11},{21,11},{22,12},{23,12},{16,13},{16,14},
    {16,15},{16, 16},{15,17},{15,18},{15,19},{15,20},{14,21},{14,22},{14,23},{14,24},
    {13,25},{13,26},{13,27},{13,28},{13,29},{0,24}, {1,24},{2, 24},{3, 25},{4, 25},
    {5, 26},{6, 26},{7, 27},{6, 27},{6, 28},{6, 29},{6, 30},{6, 31},{6, 32},{6,33},{6, 34},
    {5, 35},{5, 26},{6, 26},{7, 26},{8, 26},{9, 27},{10, 27},{11, 28},{12, 28},{14, 29},{15, 29},
    {16, 30},{17, 30},{18, 31},{19, 31},{20, 31},{21, 32},{22, 32},{23, 33} };

    cout << "\n\n";
    // it is for implementing the borders (listed in borderCoord array) into the map
    for (int i = 0; i < 88; i++)
    {
        map1->SetBorder(borderCoord[i][0], borderCoord[i][1]);
    }

    //this step is for showing the map after border implementation step.
    map1->Show();

    // IsBorder is for checking whether it is on border or not.
    cout << "\nis on map1->IsBorder(18, 31) border? : " << map1->IsBorder(18, 31) << endl;

    cout << "\n\n";
    solveObject->Init(map1);

    cout << "Number of regions in the map is " << solveObject->Solve() << endl;
}

