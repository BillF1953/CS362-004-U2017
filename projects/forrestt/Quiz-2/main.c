#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{   const size_t STATE_LENGTH = 9;
    char state [] = {'[',']', '(', ')', '{' , '}', 'a', 'x', ' '};


    // TODO: rewrite this function
return  state[(int) (rand() % STATE_LENGTH)];

}

void inputString(char * s, const size_t STRING_INPUT_LENGTH)
{
    const size_t STRING_STATE_LENGTH = 4;
    memset(s, '\0', STRING_INPUT_LENGTH + 1);
    int i;
    char stringState [] = {'r', 'e', 's', 't'};

     for(i = 0; i < STRING_INPUT_LENGTH; i++){
         s[i] = stringState[rand() % STRING_STATE_LENGTH];
      }

}

void testme()
{
    int tcCount = 0;
    char * s;
    char c;
    int state = 0;
    const size_t STRING_INPUT_LENGTH = 5;

    while (1)
    {
        tcCount++;
        s = malloc((STRING_INPUT_LENGTH + 1) * sizeof(char));

        c = inputChar();
        inputString(s, STRING_INPUT_LENGTH);
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

        if (c == '[' && state == 0) state = 1;
        if (c == '(' && state == 1) state = 2;
        if (c == '{' && state == 2) state = 3;
        if (c == ' '&& state == 3) state = 4;
        if (c == 'a' && state == 4) state = 5;
        if (c == 'x' && state == 5) state = 6;
        if (c == '}' && state == 6) state = 7;
        if (c == ')' && state == 7) state = 8;
        if (c == ']' && state == 8) state = 9;
        if (s[0] == 'r' && s[1] == 'e'
            && s[2] == 's' && s[3] == 'e'
            && s[4] == 't' && s[5] == '\0'
            && state == 9)
        {
            printf("error ");
            exit(200);
        }
        free(s);
    }
}


int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));
    testme();
    return 0;
}
