/* Ghi chuoi ra man hinh */
#include <stdio.h>
#include <dos.h>

char far *video = MK_FP(0xB800, 0);

void writestring(int x, int y, char *s)
{
  unsigned offset, i=0;

  offset = y*160 + x*2;
  while (s[i] != 0)
  {
    video[offset] = s[i];
    offset += 2;
    i++;
  }
}

void main()
{
   char string[] = "Hello World!";
   writestring(10, 10, string);
   getch();
}