#pragma once
#include "ZoneCounterInterface.h"
#include "MapInterface.h"
#include "Map.h"

using namespace std;

class solveMap : public ZoneCounterInterface
{
public:
    int width, height;
    int** solutionArray;
    int borderNum = 10;
    void Init(MapInterface* map)
    {
        map->GetSize(this->width, this->height);

        solutionArray = new int* [height + 2];

        for (int k = 0; k < (height + 2); k++) {
            solutionArray[k] = new int[width + 2];
        }

        for (int i = 0; i < height + 2; i++)
        {
            for (int j = 0; j < width + 2; j++)
            {
                if ((i == 0) || (i == height + 1) || (j == 0) || (j == width + 1))
                {
                    solutionArray[i][j] = borderNum;
                }
                else
                {
                    solutionArray[i][j] = map->CordinateValue((i - 1), (j - 1));
                }
            }
        }
        this->width += 2;
        this->height += 2;
    }
    int Solve()
    {
        int regionCount = 1;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (solutionArray[i][j] == 0) {
                    floodFill(i, j, regionCount);
                    regionCount += 1;
                }
            }
        }
        return regionCount - 1;
    }
private:
    void floodFill(int x, int y, int regionNo) {
        if ((solutionArray[x][y] == borderNum) || (solutionArray[x][y] == regionNo) || (solutionArray[x][y] != 0)) {
            return;
        }
        solutionArray[x][y] = regionNo;

        floodFill(x + 1, y, regionNo);
        floodFill(x - 1, y, regionNo);
        floodFill(x, y + 1, regionNo);
        floodFill(x, y - 1, regionNo);

        return;
    }
};
