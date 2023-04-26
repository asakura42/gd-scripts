#include <stdio.h>
#include <string.h>

void print_usage(char *program_name) {
  printf("Usage: %s %%GDSEARCH%% %%GDWORD%%\n", program_name);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    print_usage(argv[0]);
    return 1;
  }

  printf("<div class=\"gd-marisa\">\n");

  char *word = strtok(argv[1], " ");
  while (word != NULL) {
    printf("<a href=\"bword:%s\"%s>%s</a> ", word,
           strcmp(word, argv[2]) == 0 ? " class=\"active\"" : "", word);
    word = strtok(NULL, " ");
  }

  printf("</div>\n");
  printf("<style>\n");
  printf(".gd-marisa {\n");
  printf("  font-size: 2rem;\n");
  printf("  margin: 0.05em 0;\n");
  printf("  color: #1268c3;\n");
  printf("}\n");
  printf(".gd-marisa a {\n");
  printf("  color: royalblue;\n");
  printf("  text-decoration: none;\n");
  printf("  border-bottom: dashed 2px currentColor;\n");
  printf("}\n");
  printf(".gd-marisa a:hover {\n");
  printf("  background-color: #ddeeff;\n");
  printf("}\n");
  printf(".gd-marisa a.active {\n");
  printf("  background-color: #f5f5f5;\n");
  printf("}\n");
  printf(".gd-marisa a.active::before {\n");
  printf("  content: '[';\n");
  printf("}\n");
  printf(".gd-marisa a.active::after {\n");
  printf("  content: ']';\n");
  printf("}\n");
  printf("</style>\n");

  return 0;
}
