#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_usage(char *program_name) {
    printf("Usage: %s [--difficulty] %%GDSEARCH%% %%GDWORD%%\n", program_name);
}

int calculate_difficulty(char* word) {
    int num_vowels = 0;
    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            num_vowels++;
        }
    }
    if (num_vowels <= 2) {
        return 1; // easy
    } else if (num_vowels <= 4) {
        return 2; // medium
    } else {
        return 3; // hard
    }
}

int main(int argc, char *argv[]) {
    int use_difficulty_colors = 0;
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    } else if (argc == 4 && strcmp(argv[1], "--difficulty") == 0) {
        use_difficulty_colors = 1;
        argv++;
    }

    printf("<div class=\"gd-marisa\">\n");

    char *word = strtok(argv[1], " ");
    while (word != NULL) {
        char* bg_color = "";
        if (use_difficulty_colors) {
            int difficulty = calculate_difficulty(word);
            if (difficulty >= 3) {
                bg_color = "style=\"background-color: #ffcccc;\"";
            } else if (difficulty >= 2) {
                bg_color = "style=\"background-color: #ffffcc;\"";
            } else if (difficulty >= 1) {
                /* bg_color = "style=\"background-color: #ccffcc;\""; */
            }
        }
        printf("<a href=\"bword:%s\"%s %s>%s</a> ", word,
            strcmp(word, argv[2]) == 0 ? " class=\"active\"" : "", bg_color, word);
        word = strtok(NULL, " ");
    }

    printf("</div>\n");
    printf("<style>\n");
    printf(".gd-marisa {\n");
    printf(" font-size: 2rem;\n");
    printf(" margin: 0.05em 0;\n");
    printf(" color: #1268c3;\n");
    printf("}\n");
    printf(".gd-marisa a {\n");
    printf(" color: royalblue;\n");
    printf(" text-decoration: none;\n");
    printf(" border-bottom: dashed 2px currentColor;\n");
    printf("}\n");
    printf(".gd-marisa a:hover {\n");
    printf(" background-color: #ddeeff;\n");
    printf("}\n");
    printf(".gd-marisa a.active {\n");
    printf(" background-color: #f5f5f5;\n");
    printf("}\n");
    printf(".gd-marisa a.active::before {\n");
    printf(" content: '[';\n");
    printf("}\n");
    printf(".gd-marisa a.active::after {\n");
    printf(" content: ']';\n");
    printf("}\n");
    printf("</style>\n");

    return 0;
}
