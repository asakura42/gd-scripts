#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s %%GDSEARCH%% %%GDWORD%%\n", argv[0]);
        return 1;
    }
    printf("<div class=\"gd-marisa\">");
    char *word = strtok(argv[1], " ");
    while (word != NULL) {
        printf("<a href=\"bword:%s\"%s>%s</a> ", word, strcmp(word, argv[2]) == 0 ? " class=\"active\"" : "", word);
        word = strtok(NULL, " ");
    }
    printf("</div>");
    printf("<style>");
    printf(".gd-marisa { font-size: 2rem; margin: 0.05em 0; color: #1268c3; }");
    printf(".gd-marisa a { color: royalblue; text-decoration: none; border-bottom: dashed 2px currentColor; }");
    printf(".gd-marisa a:hover { background-color: #ddeeff; }");
    printf(".gd-marisa a.active { background-color: #f5f5f5; }");
    printf(".gd-marisa a.active::before { content: '['; }");
    printf(".gd-marisa a.active::after { content: ']'; }");
    printf("</style>");
    return 0;
}
