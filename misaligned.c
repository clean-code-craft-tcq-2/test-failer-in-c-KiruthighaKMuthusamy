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

void printOnConsole(int ColorPairArrayIndex, int i, int j)
{
printf("%d | %s | %s\n", ColorPairArrayIndex, majorColor[i], minorColor[i]);
}

int printColorMap() {
    
    int i = 0, j = 0,ColorPairArrayIndex = 1;
    for(i = 0; i < 5; i++) 
	{
        for(j = 0; j < 5; j++)
		{
			
			colorpair[ColorPairArrayIndex].Number = ColorPairArrayIndex;
			strcpy(colorpair[ColorPairArrayIndex].MajorColor , majorColor[i]);
			strcpy(colorpair[ColorPairArrayIndex].MinorColor , minorColor[i]);
			printOnConsole(ColorPairArrayIndex,i,j);	
		    ColorPairArrayIndex++;
				          
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
	assert(colorpair[23].Number == 23);	
	assert(strcmp(colorpair[23].MajorColor, "Violet") == 0);
	assert(strcmp(colorpair[23].MinorColor, "Green") == 0);
	assert(colorpair[23].Number == 15);	
	assert(strcmp(colorpair[15].MajorColor, "Black") == 0);
	assert(strcmp(colorpair[15].MinorColor, "Slate") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
