#include <cstdio>
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

    *program = fopen(program_name, "r");
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
    
    int cmd;
    stack_el_t a = 0, b = 0, x = 0;
    
    while (true)
    { 
        fscanf(program, "%d", &cmd);
        
        switch (cmd)
        {
            case CMD_PUSH:
            {
                fscanf(program, STK_EL_FORM_SPEC, &x);
                stackPush(stk, x);
                continue;
            }
            case CMD_ADD:
            {
                stackPop(stk, &a);
                stackPop(stk, &b);
                stackPush(stk, a + b);
                continue;
            }
            case CMD_SUB:
            {
                stackPop(stk, &a);
                stackPop(stk, &b);
                stackPush(stk, b - a);
                continue;
            }
            case CMD_MUL:
            {
                stackPop(stk, &a);
                stackPop(stk, &b);
                stackPush(stk, a * b);
                continue;
            }
            case CMD_DIV:
            {
                stackPop(stk, &a);
                stackPop(stk, &b);
                stackPush(stk, b / a);
                continue;
            }
            case CMD_IN:
            {
                scanf(STK_EL_FORM_SPEC, &x);
                stackPush(stk, x);
                continue;
            }
            case CMD_OUT:
            {
                stackPop(stk, &x);
                printf("Stack element is " STK_EL_FORM_SPEC "\n", x);
                continue;
            }
            case CMD_DUMP:
            {
                STACK_DUMP(stk, SUCCESS);
                continue;
            }
            case CMD_HLT:
            {
                break;
            }
        }
        break;
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
