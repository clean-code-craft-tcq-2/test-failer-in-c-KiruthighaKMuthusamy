#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


struct Colorpair
{
	int Number;
	char MajorColor[8];
	char MinorColor[8];
};

Colorpair colorpair[25];

void PrintOnConsole( int i, int j)
{
printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
}

int printColorMap() {
    
    int i = 0, j = 0,ColorPairArrayIndex=0;
    for(i = 0; i < 5; i++) 
	{
        for(j = 0; j < 5; j++)
		{
			ColorPairArrayIndex++;
			colorpair[ColorPairArrayIndex].Number = i * 5 + j;
			strcpy(colorpair[ColorPairArrayIndex].MajorColor , majorColor[i]);
			strcpy(colorpair[ColorPairArrayIndex].MinorColor , minorColor[i]);
			PrintOnConsole(i,j);				
				          
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
	assert(colorpair[23].PairNumber == 23);	
	assert(strcmp(colorpair[23].MajorColor, "Violet") == 0);
	assert(strcmp(colorpair[23].MinorColor, "Green") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
