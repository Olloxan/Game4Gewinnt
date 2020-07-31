
void player1won()
{
  matrix.setTextColor(matrix.Color(225,225,0));
   for(int x = matrix.width();x > -68;x--) 
    {
      matrix.fillScreen(0);
      matrix.setCursor(--x, 0);
      matrix.print(F("P1 W o n "));
      matrix.show();
      delay(100);
    }    
}
