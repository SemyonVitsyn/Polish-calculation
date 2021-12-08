flags = -lm

lab.out : calculating_value.o clipping_expressions.o main.o post_conversion.o post_notation.o stack.o
	gcc calculating_value.o clipping_expressions.o main.o post_conversion.o post_notation.o stack.o -o lab.out $(flags)

calculating_value.o: calculating_value.c
	gcc -c calculating_value.c $(flags)

clipping_expressions.o: clipping_expressions.c 
	gcc -c clipping_expressions.c $(flags)

main.o: main.c
	gcc -c main.c $(flags)

post_conversion.o: post_conversion.c
	gcc -c post_conversion.c $(flags)

post_notation.o: post_notation.c
	gcc -c post_notation.c $(flags)

stack.o: stack.c
	gcc -c stack.c $(flags)


