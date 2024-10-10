#include <cstdio>
#include <cstring>
#include "../Stack/stack.hpp"
#include "../Stack/stack_print.hpp"
#include "processor.hpp"

int main(int argc, char* argv[])
{
    if (argc > 2) 
    {
        printf(ALERT_COL "Too many arguments for processor\n" RESET_COL);
        return 1;
    }
    else if (argc < 2)
    {
        printf(ALERT_COL "No program name\n" RESET_COL);
        return 1;
    }
    
    stack_t stk = {};
    FILE* program = NULL;

    getReady(&stk, 10, &program, argv[1]);

    runProgram(&stk, program);

    shutDown(&stk, &program);
    
    return 0;
}
