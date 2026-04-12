
#include <stdio.h>
#include <stdlib.h>
void set_color(int a,int b){
      int c=b+40;
      int d=a+30;
       
     fprintf(stdout,"\033[%d;%dm",c,d);

}
int swap_rb(int c) {
    return ((c & 1) << 2) | (c & 2) | ((c & 4) >> 2);
}

void process_ansi(const char *str) {
    while (*str) {
        if (*str == 27 && *(str+1) == '[') {
            str += 2;
            int fg = 7, bg = 0;

            while (*str && *str != 'm') {
                int code = atoi(str);

                if (code >= 30 && code <= 37)
                    fg = swap_rb(code - 30);
                if (code >= 40 && code <= 47)
                    bg = swap_rb(code - 40);

                while (*str && *str != ';' && *str != 'm') str++;
                if (*str == ';') str++;
            }

            if (*str == 'm') {
                set_color(fg, bg);
                str++;
            }
        } else {
            putchar(*str);
            str++;
        }
    }
}

int main() {
    
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        process_ansi(buffer);
    }

    return 0;
}