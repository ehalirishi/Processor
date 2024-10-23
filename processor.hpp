#include "../Stack/stack.hpp"

void getReady(stack_t* stk, size_t capacity, FILE** program, const char* program_name);
void runProgram(stack_t* stk, FILE* program);
void shutDown(stack_t* stk, FILE** program);

enum COMMANDS
{
    CMD_PUSH,
    CMD_ADD,
    CMD_SUB,
    CMD_MUL,
    CMD_DIV,
    CMD_IN,
    CMD_OUT,
    CMD_DUMP,
    CMD_HLT
};
