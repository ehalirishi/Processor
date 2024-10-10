# MY MAKE ISN'T GOOD, I KNOW, I'M STILL TRYING TO FIGURE OUT HOW IT WORKS

CFLAGS=	-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ \
	  	-Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations \
	  	-Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported \
		-Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral \
		-Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op \
		-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith \
		-Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
		-Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
		-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default \
		-Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast \
		-Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing \
		-Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation \
		-fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer \
		-Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla
		
GPP_COMP_COL = "\033[01;38;05;134mg++ \033[01;38;05;68m-c\033[1;32m"
RESET_COL = "\033[0m"

processor.out: main.o stack.o stack_print.o stack_helping_func.o hash.o processor.o
	g++ main.o stack.o stack_print.o stack_helping_func.o hash.o processor.o -o processor.out
	valgrind -s --leak-check=full ./processor.out

main.o: main.cpp
	@echo $(GPP_COMP_COL) "main.cpp" $(RESET_COL)
	@g++ $(CFLAGS) -c main.cpp

stack.o: ../Stack/stack.cpp
	@echo $(GPP_COMP_COL) "stack.cpp" $(RESET_COL)
	@g++ $(CFLAGS) -c ../Stack/stack.cpp

stack_print.o: ../Stack/stack_print.cpp
	@echo $(GPP_COMP_COL) "stack_print.cpp" $(RESET_COL)
	@g++ $(CFLAGS) -c ../Stack/stack_print.cpp

stack_helping_func.o: ../Stack/stack_helping_func.cpp
	@echo $(GPP_COMP_COL) "stack_helping_func.cpp" $(RESET_COL)
	@g++ $(CFLAGS) -c ../Stack/stack_helping_func.cpp

hash.o: ../Stack/hash.cpp
	@echo $(GPP_COMP_COL) "hash.cpp" $(RESET_COL)
	@g++ $(CFLAGS) -c ../Stack/hash.cpp

processor.o: processor.cpp
	@echo $(GPP_COMP_COL) "processor.cpp" $(RESET_COL)
	@g++ $(CFLAGS) -c processor.cpp

clean: 
	rm -rf *.out *.o
