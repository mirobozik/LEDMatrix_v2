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
	run_right_down(50);
	delay(500);
	
	run_left_up(50);
	delay(500);
	
	run_random(10);
	delay(500);
	
	run_matrix(25, 100);
	delay(500);	
}

/*
 * Rozsvecovanie LED diod z prava dolu (po riadkoch)
 */
void run_right_down(int delayVal)
{	
	for (int row = 0; row < 8; row++)
	{	
		maxMatrix.setDot(0, row, HIGH);	
		delay(delayVal);
		for (int column = 0; column < 8; column++)
		{
			maxMatrix.shiftRight(); //posun pozicie doprava
			delay(delayVal);
		}		
		maxMatrix.shiftDown(); //posun pozicie dolu
		delay(delayVal);
	}
	maxMatrix.clear();
}

/*
 * Rozsvecovanie LED diod z lava hore (po riadkoch)
 */
void run_left_up(int delayVal)
{
	for (int row = 7; row >= 0; row--)
	{
		maxMatrix.setDot(7, row, HIGH);
		delay(delayVal);
		for (int column = 0; column < 8; column++)
		{
			maxMatrix.shiftLeft(); //posun pozicie dolava
			delay(delayVal);
		}
		maxMatrix.shiftUp(); //posun pozicie hore
		delay(delayVal);
	}
	maxMatrix.clear();
}

/*
 * Rozsvecovanie LED diod nahodne
 */
void run_random(int delayVal)
{
	for (int i = 0; i < 64; i++)
	{
		int row = random(0, 8);
		int column = random(0, 8);
		maxMatrix.setDot(column, row, HIGH);
		delay(delayVal);
		maxMatrix.clear();
	}	
}

void run_matrix_column(int delayVal, int colIndex)
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

/*
 * Jednoduchy efekt alla Matrix
 */
void run_matrix(int delayValMin, int delayValMax)
{
	for (int columnIndex = 0; columnIndex < 8; columnIndex++)
	{
		int delayVal = random(delayValMin, delayValMax);
		run_matrix_column(delayVal, columnIndex);
	}		
}
