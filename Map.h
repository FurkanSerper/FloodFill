#pragma once
#include "MapInterface.h"
using namespace std;
class Map : public MapInterface
{
public:

    int width;  //X  36
    int height; //Y  24
    int** mapCoord;
    int borderNum = 10;

    // set the sizes of the map.
    void SetSize(const int width, const int height)
    {
        this->width = width;
        this->height = height;
        this->mapCoord = new int* [height];

        for (int i = 0; i < height; i++)
        {
            this->mapCoord[i] = new int[width];
        }

        for (int ii = 0; ii < height; ii++)
        {
            for (int ll = 0; ll < width; ll++)
            {
                this->mapCoord[ii][ll] = 0;
            }
        }
    }
    void GetSize(int& width, int& height)
    {
        width = this->width;
        height = this->height;
    }

    //prints the map out
    void Show()
    {
        for (int iii = 0; iii < (height); iii++)
        {
            for (int lll = 0; lll < (width); lll++)
            {
                // [height][width]
                // it is written for showing the Algormap properly. because after number 9, numbers become 2-digit
                if (this->mapCoord[iii][lll] < 10)
                {
                    cout << this->mapCoord[iii][lll] << "  ";
                }
                else
                {
                    cout << this->mapCoord[iii][lll] << " ";
                }
            }
            cout << endl;
        }
    }

    // sets the cordinate value as 20 (20 as decided as border number)
    void SetBorder(const int x, const int y)
    {
        this->mapCoord[x][y] = borderNum;
    }

    // sets the cordinate value as 0
    void ClearBorder(const int x, const int y)
    {
        this->mapCoord[x][y] = 0;
    }

    //Checks whether it is on border or not
    bool IsBorder(const int x, const int y)
    {
        if (this->mapCoord[x][y] == borderNum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //it gives the value stored in the cordinate.  x ==> row  y==> colon
    int CordinateValue(const int x, const int y)
    {
        return this->mapCoord[x][y];
    }

};
