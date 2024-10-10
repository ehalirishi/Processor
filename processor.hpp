#include "../Stack/stack.hpp"

void getReady(stack_t* stk, size_t capacity, FILE** program, const char* program_name);
void runProgram(stack_t* stk, FILE* program);
void shutDown(stack_t* stk, FILE** program);
