
void schlangenmuster2()
{
  matrix.fillScreen(0);
  for(int y = 0; y < 8; y++ )                                      // 1                                     
  { 
   for(int x = 0; x < 1; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(128, 0, 0));
    matrix.show();
    delay(70);
      
   }
  }

  for(int y = 7; y < 8; y++ )                                         // 2
  {
   for(int x = 1; x < 8; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(130, 40, 40));
    matrix.show();
    delay(65);
      
   }
  }  
   for(int y = 6; y >= 0; y-- )                                       //3 
  {
   for(int x = 7; x < 8; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(141,83,59));
    matrix.show();
    delay(60);
   }
  }
  for(int y = 0; y < 1; y++ )                                    //4
  {
   for(int x = 6; x > 0; x--)
   {
    matrix.drawPixel(x, y, matrix.Color(153, 102, 117));
    matrix.show();
    delay(55);
   }
  }
  for(int y = 1; y < 7; y++)                                      //5
  {
   for(int x = 1; x < 2; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(153, 102, 169));
    matrix.show();
    delay(50);
       
   }
  }
  for(int y = 6; y < 7; y++)                                     //6
  {
   for(int x = 2; x < 7; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(128, 0, 128));
    matrix.show();
    delay(45);
     
   }
  } 
  for(int y = 6; y > 0; y--)                                      //7
  {
   for(int x = 6; x < 7; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(101, 0, 155));
    matrix.show();
    delay(40);
      
   }
  }
  for(int y = 1; y < 2; y++)                                       //8
  {
   for(int x = 6; x > 1; x--)
   {
    matrix.drawPixel(x, y, matrix.Color(72, 0, 225));
    matrix.show();
    delay(35);
    
   }
  }
  for(int y = 2; y < 6; y++ )                                       //9
  {
   for(int x = 2; x < 3; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(4, 0, 208));
    matrix.show();
    delay(30);
      
   }
  }
  for(int y = 5; y < 6; y++ )                                       //10
  {
   for(int x = 2; x < 6; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(0,68,220));
    matrix.show();
    delay(25);
       
   }
  }
  for(int y = 5; y > 1; y-- )                                        //11
  {
   for(int x = 5; x < 6; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(1, 114, 226));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 2; y <3; y++ )                                         //12
  {
   for(int x = 5; x > 2; x--)
   {
    matrix.drawPixel(x, y, matrix.Color(1, 159, 232));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 3; y < 5; y++ )                                        //13
  {
   for(int x = 3; x < 4; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(11, 175, 162));
    matrix.show();
    delay(20);
      
   }
  }  
  for(int y = 4; y > 2; y-- )                                       //14
  {
   for(int x = 4; x < 5; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(23, 179, 77));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 3; y < 6; y++ )                                       //15           
  {
   for(int x = 3; x < 4; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(0, 212, 28));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 5; y < 6; y++ )                                       //16
  {
   for(int x = 4; x < 6; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(0, 255, 0));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 4; y > 1; y-- )                                       //17
  {
   for(int x = 5; x < 6; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(128, 255, 0));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 2; y < 3; y++ )                                       //18
  {
   for(int x = 4; x > 1; x--)
   {
    matrix.drawPixel(x, y, matrix.Color(200, 250, 0));
    matrix.show();
    delay(25);
       
   }
  }
  for(int y = 3; y < 7; y++ )                                       //19
  {
   for(int x = 2; x < 3; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 255, 0));
    matrix.show();
    delay(30);
       
   }
  }
  for(int y = 6; y < 7; y++ )                                       //20
  {
   for(int x = 3; x < 7; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 219, 0));
    matrix.show();
    delay(35);
       
   }
  }
  for(int y = 5; y > 0; y-- )                                       //21
  {
   for(int x = 6; x < 7; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 182, 0));
    matrix.show();
    delay(20);
       
   }
  }
  for(int y = 1; y < 2; y++ )                                       //22
  {
   for(int x = 5; x > 0; x--)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 146, 0));
    matrix.show();
    delay(40);
       
   }
  }
  
  for(int y = 2; y < 8; y++ )                                       //23
  {
   for(int x = 1; x < 2; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 109, 0));
    matrix.show();
    delay(45);
     
   }
  }
  
  for(int y = 7; y < 8; y++ )                                       //24
  {
   for(int x = 2; x < 8; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 73, 0));
    matrix.show();
    delay(50);
       
   }
  }
  
  for(int y = 6; y >= 0; y-- )                                       //25
  {
   for(int x = 7; x < 8; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 0, 0));
    matrix.show();
    delay(55);
       
   }
  }
  
  for(int y = 0; y < 1; y++ )                                       //26
  {
   for(int x = 6; x >= 0; x--)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 0, 128));
    matrix.show();
    delay(60);
     
   }
  }
  
  for(int y = 1; y < 8; y++ )                                       //27
  {
   for(int x = 0; x < 1; x++)
   {
    matrix.drawPixel(x, y, matrix.Color(255, 105, 180));
    matrix.show();
    delay(65);
   }
  }
  
}
