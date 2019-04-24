// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white  
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by  vegaseat  07nov2004
#include <iostream>
#include <windows.h>   // WinApi header
int main()
{
  HANDLE  hConsole;
int k;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for(k = 1; k < 255; k++){
    // pick the colorattribute k you want
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),k);
    printf("%i I want to be nice today!\n",k);
  }
}
