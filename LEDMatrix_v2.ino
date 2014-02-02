#include <MaxMatrix.h>

//PINS setup
#define PIN_DIN 8
#define PIN_CS	9
#define PIN_CLK	10

#define LED_MATRIX_COUNT 1
#define LED_MATRIX_INTENSITY 1

MaxMatrix maxMatrix(PIN_DIN, PIN_CS, PIN_CLK, LED_MATRIX_COUNT);

void setup()
{
	maxMatrix.init();
	maxMatrix.setIntensity(LED_MATRIX_INTENSITY);
}

void loop()
{
	//effect_1(150);	
	//effect_2(100);	
	effect_3(5);	
	//effect_5(5, 25);	
}

void effect_1(int delayVal)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			maxMatrix.setDot(i, j, HIGH);
			delay(delayVal);
		}
		delay(delayVal);
	}
	maxMatrix.clear();
}

void effect_2(int delayVal)
{	
	for (int row = 0; row < 8; row++)
	{	
		maxMatrix.setDot(0, row, HIGH);	
		delay(delayVal);
		for (int column = 0; column < 8; column++)
		{
			maxMatrix.shiftRight();
			delay(delayVal);
		}		
		maxMatrix.shiftDown();
		delay(delayVal);
	}
	maxMatrix.clear();
}

void effect_3(int delayVal)
{
	int row = random(0, 8);
	int column = random(0, 8);
	maxMatrix.setDot(column, row, HIGH);
	delay(delayVal);	
	maxMatrix.clear();
}

void effect_4(int delayVal, int colIndex)
{
	int row = random(0, 8);
	int rowIndexMax = 8 - row;
	maxMatrix.setDot(colIndex, rowIndexMax, HIGH);
	delay(delayVal);
	for (int rowIndex = rowIndexMax; rowIndex > 0; rowIndex--)
	{
		maxMatrix.shiftUp();
		delay(delayVal);
	}			
}

void effect_5(int delayValMin, int delayValMax)
{
	for (int columnIndex = 0; columnIndex < 8; columnIndex++)
	{
		int delayVal = random(delayValMin, delayValMax);
		effect_4(delayVal, columnIndex);
	}		
}
