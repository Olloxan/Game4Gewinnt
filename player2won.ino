
void player2won()
{
  matrix.setTextColor(matrix.Color(4,0,208));
   for(int x = matrix.width();x > -68;x--) 
    {
      matrix.fillScreen(0);
      matrix.setCursor(--x, 0);
      matrix.print(F("P2 W o n "));
      matrix.show();
      delay(100);
    } 
    
}
