
void draw()
{
  matrix.setTextColor(matrix.Color(255,146,0));
  for(int x = matrix.width();x > -40;x--) 
    {
      matrix.fillScreen(0);
      matrix.setCursor(--x, 0);
      matrix.print(F("D r a w"));
      matrix.show();
      delay(100);
    }   
}
