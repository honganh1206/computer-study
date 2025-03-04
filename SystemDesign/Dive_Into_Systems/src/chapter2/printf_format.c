#include <stdio.h>

int main() {
  float x, y;
  char ch;

  x = 4.50001;
  y = 5.199999;
  ch = 'a'; // ASCII value = 97

  printf("%.1f %.1f\n", x, y); // Single precision
  // Print the values in 6 chars width, right justified
  printf("%6.1f \t %6.1f \t %c\n", x, y, ch);
  printf("%6.1f \t %6.1f \t %c\n", x*20, y*20, ch+2);
  printf("ch value is %d which is the ASCII value of %c\n", ch, ch);

  return 0;
}
