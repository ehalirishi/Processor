#include <cstdio>
#include <cstring>
#include <cassert>
#include "../processor.hpp"
#include "../../Stack/stack_print.hpp"

int main(void)
{
    FILE* source_code = fopen("source.txt", "r");
    FILE* executable_code = fopen("program.txt", "w");
    assert (source_code);
    assert (executable_code);

    int code[100] = {};
    char cmd[15] = {};
    size_t ip = 0;

    while (fscanf(source_code, "%s", cmd) != EOF)
    {        
        if (strcmp(cmd, "push") == 0) 
        {
            code[ip++] = CMD_PUSH;
            fscanf(source_code, "%d", &code[ip++]);
            continue;
        } 
        if (strcmp(cmd, "add") == 0)
        {
            code[ip++] = CMD_ADD;
            continue;
        }
        if (strcmp(cmd, "sub") == 0)
        {
            code[ip++] = CMD_SUB;
            continue;
        }
        if (strcmp(cmd, "mul") == 0)
        {
            code[ip++] = CMD_MUL;
            continue;
        }
        if (strcmp(cmd, "div") == 0)
        {
            code[ip++] = CMD_DIV;
            continue;
        }
        if (strcmp(cmd, "in") == 0)
        {
            code[ip++] = CMD_IN;
            continue;
        }
        if (strcmp(cmd, "out") == 0)
        {
            code[ip++] = CMD_OUT;
            continue;
        }
        if (strcmp(cmd, "dump") == 0) 
        {
            code[ip++] = CMD_DUMP;
            continue;
        }
        if (strcmp(cmd, "hlt") == 0) 
        {
            code[ip++] = CMD_HLT;
            continue;
        }
        
        printf(ALERT_COL "Unknown command %s\n" RESET_COL, cmd);
    }

    for (size_t i = 0; i < ip; i++) {
        fprintf(executable_code, "%d ", code[i]);
    }

    fclose(source_code);
    fclose(executable_code);
    
    return 0;
}
