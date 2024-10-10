#include <cstdio>
#include <cstring>
#include <cmath>
#include "../Stack/stack.hpp"
#include "../Stack/stack_print.hpp"
#include "processor.hpp"

void getReady(stack_t* stk, size_t capacity, FILE** program, const char* program_name)
{
    if (!stk) 
    {
        printf(DEBUG_OUTPUT ALERT_COL "Stack address in NULL\n" RESET_COL, DEBUG_OUTPUT_INFO);
        return;
    }

    stackCtor(stk, capacity);

    *program = fopen(program_name, "rb");
    if (!program) 
    {
        printf(DEBUG_OUTPUT ALERT_COL "Wrong program file\n" RESET_COL, DEBUG_OUTPUT_INFO);
        return;
    }
    
    printf(INFO_COL "Processor is ready to work\n" RESET_COL);
}

void runProgram(stack_t* stk, FILE* program)
{
    if (!stk) 
    {
        printf(DEBUG_OUTPUT ALERT_COL "Stack address in NULL\n" RESET_COL, DEBUG_OUTPUT_INFO);
        return;
    }

    if (!program) 
    {
        printf(DEBUG_OUTPUT ALERT_COL "Wrong program file\n" RESET_COL, DEBUG_OUTPUT_INFO);
        return;
    }
    
    char cmd[15] = {};
    stack_el_t a = 0, b = 0, x = 0;
    
    while (true)
    { 
        fscanf(program, "%s", cmd);
        
        if (strcmp(cmd, "push") == 0) 
        {
            fscanf(program, STK_EL_FORM_SPEC, &x);
            stackPush(stk, x);
            continue;
        } 
        if (strcmp(cmd, "add") == 0)
        {
            stackPop(stk, &a);
            stackPop(stk, &b);
            stackPush(stk, a + b);
            continue;
        }
        if (strcmp(cmd, "sub") == 0)
        {
            stackPop(stk, &a);
            stackPop(stk, &b);
            stackPush(stk, b - a);
            continue;
        }
        if (strcmp(cmd, "mult") == 0)
        {
            stackPop(stk, &a);
            stackPop(stk, &b);
            stackPush(stk, a * b);
            continue;
        }
        if (strcmp(cmd, "div") == 0)
        {
            stackPop(stk, &a);
            stackPop(stk, &b);
            stackPush(stk, b / a);
            continue;
        }
        if (strcmp(cmd, "out") == 0)
        {
            stackPop(stk, &x);
            printf("Stack element is " STK_EL_FORM_SPEC "\n", x);
            continue;
        }
        if (strcmp(cmd, "sqrt") == 0)
        {
            stackPop(stk, &x);
            if (x > 0) {
                stackPush(stk, sqrt(x));
            } 
            else {
                printf(ALERT_COL "You can\'t take square root of negative numbers\n" RESET_COL);
            }
            continue;
        }
        if (strcmp(cmd, "sin") == 0)
        {
            stackPop(stk, &x);
            stackPush(stk, sin(x));
            continue;
        }
        if (strcmp(cmd, "cos") == 0)
        {
            stackPop(stk, &x);
            stackPush(stk, cos(x));
            continue;
        }
        if (strcmp(cmd, "dump") == 0) {
            STACK_DUMP(stk, SUCCESS);
            continue;
        }

        if (strcmp(cmd, "halt") == 0) {
            break;
        }
    }
}

void shutDown(stack_t* stk, FILE** program)
{
    if (!stk) 
    {
        printf(DEBUG_OUTPUT ALERT_COL "Stack address in NULL\n" RESET_COL, DEBUG_OUTPUT_INFO);
        return;
    }

    if (!program) 
    {
        printf(DEBUG_OUTPUT ALERT_COL "Wrong program file\n" RESET_COL, DEBUG_OUTPUT_INFO);
        return;
    }

    stackDtor(stk);

    fclose(*program);

    printf(INFO_COL "Processor finished its work\n" RESET_COL);
}
