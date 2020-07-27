#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

#include "Game4Gewinnt.h"

#define BUTTON_LEFT 2  //Pineigang hier tauschen (Zahl wechseln)
#define BUTTON_MID 3
#define BUTTON_RIGHT 4
#define PIN_MATRIX 6
#define MAT_WIDTH 8
#define MAT_HEIGHT 8
#define PIN_STRIP 8
#define STRIP_NUMPIXELS 4

Game4Gewinnt game; 
Adafruit_NeoMatrix matrix(MAT_WIDTH, MAT_HEIGHT, PIN_MATRIX);
Adafruit_NeoPixel strip(STRIP_NUMPIXELS,PIN_STRIP,NEO_GRB+NEO_KHZ800);

const uint32_t playerColors_strip[] = {strip.Color(255,0,0), strip.Color(0,0,255)};
const uint16_t playerColors_matrix[] = {matrix.Color(0,0,0), matrix.Color(255,0,0), matrix.Color(0,0,255)};

void setup() 
{
  pinMode(BUTTON_LEFT,INPUT_PULLUP);
  pinMode(BUTTON_MID,INPUT_PULLUP);
  pinMode(BUTTON_RIGHT,INPUT_PULLUP);

  matrix.setBrightness(20);
  matrix.begin();
  strip.begin();
    
  matrix.show();  
  strip.show();

  ClearMatrix();
  Serial.begin(9600);
}

int nextTurn = 1;
int buttonPress = 0;

void loop() 
{
  SetPlayerState(game.GetCurrentPlayer());
  DrawMatchField(game.GetMatchField());
  if(nextTurn == 1)
  {
    game.BeginNextTurn();
    nextTurn = 0;
  }
  int buttonLeft = digitalRead(BUTTON_LEFT);
  int buttonRight = digitalRead(BUTTON_RIGHT);
  int buttonMid = digitalRead(BUTTON_MID);
  
  if(IsLow(buttonLeft)&& buttonPress != 1)
  {
    game.ShiftPixelLeft();
    buttonPress = 1;
  }
  if(IsLow(buttonRight) && buttonPress != 1)
  {
    game.ShiftPixelRight();
    buttonPress = 1;
  }
  if(IsLow(buttonMid) && buttonPress != 1)
  {
    game.ReleasePixel();
    nextTurn = 1;
    buttonPress = 1;
  }

  if(IsNotPressed(buttonLeft) && IsNotPressed(buttonRight) && IsNotPressed(buttonMid))
  {
    buttonPress = 0;
  }
  
  Serial.println(buttonPress); 
  delay(50);
}

void SetPlayerState(int player)
{
  for(int i = 0; i< strip.numPixels();i++)
  {
    strip.setPixelColor(i, playerColors_strip[player-1]);      
  }
  strip.show();
}

void DrawMatchField(int* matchField)
{
  for(int y = 0; y < MAT_HEIGHT;y++)
  {
    for(int x = 0; x < MAT_WIDTH; x++) 
    {
      matrix.drawPixel(x,y, playerColors_matrix[matchField[x + y*MAT_WIDTH]]);
    }
  }
  matrix.show();
}

void ClearMatrix()
{
  for(int x = 0; x<8;x++)
  {
    for(int y = 0;y<8;y++)
    {
      matrix.drawPixel(x, y, matrix.Color(0,0,0)); 
    }
  }  
  matrix.show();
}

bool IsLow(int button)
{
  return button == LOW;
}

bool IsNotPressed(int button)
{
  return button != LOW;
}
