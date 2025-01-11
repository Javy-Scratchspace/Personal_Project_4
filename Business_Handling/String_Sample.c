
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Declaration of variables used within this program. */
  char first[100] = "Hello World", second[20] = "World";
  int i, j, fsl, ssl, temp, chk = 0;
  
  /* Using the strlen function to calculate length of the given string. */
  fsl = strlen(first);
  ssl = strlen(second);

  /* Loop iteration to remove the second string from the first string. */
  for (i = 0; i < fsl; i++) {
    temp = i;
    for (j = 0; j < ssl; j++) {
      if (first[i] == second[j])
        i++;
    }
    chk = i - temp;
    if (chk == ssl) {
      i = temp;
      for (j = i; j < (fsl - ssl); j++)
        first[j] = first[j + ssl];
      fsl = fsl - ssl;
      first[j] = '\0';
    }
  }
  
  /*Finally, printing the result. */
  printf("\nNew String = %s", first);

  return 0;
}