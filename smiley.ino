
void smileyP1()

{ 
  for(int y = 2; y < 6; y++)                                                  //Kreis (Körper des Smileys)
  {
    for(int x = 0; x < 1; x++)
    {
      matrix.drawPixel(x, y, matrix.Color(225,225,0));
      matrix.show();
    }
  }
      matrix.drawPixel(1, 6, matrix.Color(225,225,0));
      matrix.show(); 
  for(int y = 7; y < 8; y++)
  {
    for(int x = 2; x < 6; x++)
    {
      matrix.drawPixel(x, y, matrix.Color(225,225,0));
      matrix.show();  
    }
  }
      matrix.drawPixel(6, 6, matrix.Color(225,225,0));
      matrix.show();
  for(int y = 6; y > 1; y--)
  {
    for(int x = 7; x < 8; x++)
    {
      matrix.drawPixel(x, y, matrix.Color(225,225,0));
      matrix.show(); 
    }
  }
      matrix.drawPixel(6, 1, matrix.Color(225,225,0));
      matrix.show();
  for(int y = 0; y < 1; y++)
  {
    for(int x = 5; x > 1; x--)
    {
      matrix.drawPixel(x, y, matrix.Color(225,225,0));
      matrix.show(); 
    }
  }
      matrix.drawPixel(1, 1, matrix.Color(225,225,0));
      matrix.show();
  
  matrix.drawPixel(1,2,matrix.Color(225,225,0));                                        // Auge1 
  matrix.drawPixel(2,2,matrix.Color(225,225,0));
  matrix.drawPixel(1,3,matrix.Color(225,225,0));
  matrix.drawPixel(2,3,matrix.Color(225,225,0));
  
  matrix.drawPixel(5,2,matrix.Color(225,225,0));                                        // Auge2
  matrix.drawPixel(6,2,matrix.Color(225,225,0));
  matrix.drawPixel(5,3,matrix.Color(225,225,0));
  matrix.drawPixel(6,3,matrix.Color(225,225,0));
  matrix.show();

  

  
  matrix.drawPixel(1,4,matrix.Color(225,225,0));                                        //Mund
  matrix.drawPixel(2,5,matrix.Color(225,225,0));
  matrix.drawPixel(3,6,matrix.Color(225,225,0));
  matrix.drawPixel(4,6,matrix.Color(225,225,0));
  matrix.drawPixel(5,5,matrix.Color(225,225,0));
  matrix.drawPixel(6,4,matrix.Color(225,225,0));
  matrix.show();
  
  matrix.drawPixel(5,2,matrix.Color(0,0,0));                                         //Auge2 blinker
  matrix.drawPixel(6,2,matrix.Color(0,0,0));

  matrix.drawPixel(1,2,matrix.Color(0,0,0));                                        // Auge1 
  matrix.drawPixel(2,2,matrix.Color(0,0,0));

  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(225,225,0));
  matrix.drawPixel(6,2,matrix.Color(225,225,0));

  matrix.drawPixel(1,2,matrix.Color(225,225,0));                                     // Auge1 
  matrix.drawPixel(2,2,matrix.Color(225,225,0));
  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(0,0,0));                                         
  matrix.drawPixel(6,2,matrix.Color(0,0,0));

  matrix.drawPixel(1,2,matrix.Color(0,0,0));                                        // Auge1 
  matrix.drawPixel(2,2,matrix.Color(0,0,0));
  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(225,225,0));
  matrix.drawPixel(6,2,matrix.Color(225,225,0));
  
  matrix.drawPixel(1,2,matrix.Color(225,225,0));                                     // Auge1 
  matrix.drawPixel(2,2,matrix.Color(225,225,0));
  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(0,0,0));                                         
  matrix.drawPixel(6,2,matrix.Color(0,0,0));

  matrix.drawPixel(1,2,matrix.Color(0,0,0));                                        // Auge1 
  matrix.drawPixel(2,2,matrix.Color(0,0,0));
  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(225,225,0));
  matrix.drawPixel(6,2,matrix.Color(225,225,0));

  matrix.drawPixel(1,2,matrix.Color(225,225,0));                                     // Auge1 
  matrix.drawPixel(2,2,matrix.Color(225,225,0));
  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(0,0,0));                                         
  matrix.drawPixel(6,2,matrix.Color(0,0,0));

  matrix.drawPixel(1,2,matrix.Color(0,0,0));                                        // Auge1 
  matrix.drawPixel(2,2,matrix.Color(0,0,0));
  
  matrix.show();
  delay(300);
  matrix.drawPixel(5,2,matrix.Color(225,225,0));
  matrix.drawPixel(6,2,matrix.Color(225,225,0));
  
  matrix.drawPixel(1,2,matrix.Color(225,225,0));                                     // Auge1 
  matrix.drawPixel(2,2,matrix.Color(225,225,0));
  
  matrix.show();
  delay(300);
}
