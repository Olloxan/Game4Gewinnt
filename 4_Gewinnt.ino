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

const uint32_t playerColors_strip[] = {strip.Color(225,225,0), strip.Color(4,0,208)};
const uint16_t playerColors_matrix[] = {matrix.Color(0,0,0), matrix.Color(225,225,0), matrix.Color(4,0,208)};

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
  matrix.setTextWrap(false);
  
  matrix.fillScreen(0);
  Serial.begin(9600);
   matrix.setTextWrap(false);

   for(int i = 0; i < 1;i++)                                 // Begrüßung '4 Gewinnt'
  {
    matrix.setTextColor(matrix.Color(135,53,244));
    for(int x = matrix.width();x >-50;x--)
    {
      matrix.fillScreen(0);
      matrix.setCursor(--x, 0);
      matrix.print(F("4 Gewinnt"));
      matrix.show();
      delay(160);
    }
  }
    
    schlangenmuster2();
    delay(20);
}

    
int nextTurn = 1;
int buttonPress = 0;
int gameState = 0;

void loop() 
{
  
   
  if(gameState == 0)
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
  
    //links - so lassen
    if(IsLow(buttonLeft)&& buttonPress != 1)
    {
      game.ShiftPixelLeft();
      buttonPress = 1;
    }
    
    //rechtes - so lassen
    if(IsLow(buttonRight) && buttonPress != 1)
    {
      game.ShiftPixelRight();
      buttonPress = 1;
    }
    // so lassen
    if(IsLow(buttonMid) && buttonPress != 1)
    {
      int currentPlayer = game.GetCurrentPlayer();
      game.ReleasePixel();
      int before = game.GetLastPixelPos();
      int after = game.GetCurrentPixelPos();
      after /= 8;
      int lastpix = 0;
      for(int y = 0; y < after; y++)
      {                         
          matrix.drawPixel(before, y, playerColors_matrix[currentPlayer]);
          matrix.show();          
          delay(90);
          lastpix = y;
          matrix.drawPixel(before, lastpix, playerColors_matrix[0]);
      }
      
      nextTurn = 1;
      buttonPress = 1;
      gameState = game.GetGameState();
    }
  
    // so lassen
    if(IsNotPressed(buttonLeft) && IsNotPressed(buttonRight) && IsNotPressed(buttonMid))
    {
      buttonPress = 0;
    }
  }
  else if(gameState == 1)
  {
    fillScreenP1();
    player1won();
    delay(100);
    smileyP1();       // lichteffekt player 1
    game.Reset();
    gameState = game.GetGameState();
  }
  else if(gameState == 2)
  {
    fillScreenP2();
    player2won();
    delay(100); 
    smileyP2();     // lichteffekt player 2
    game.Reset();
    gameState = game.GetGameState();
  }
  else
  {
    draw();// lichteffekt unentschieden
    quadrat();
    quadrat2();
    game.Reset();
    gameState = game.GetGameState();
  }
  
  
  //spieler hat gewonnen
  // -lichteffekt
  // spiel reset

  
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

void matrixfillScreen()
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
