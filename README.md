template net.il.compilers compile into net assembly

java -jar antlr-4.9.2-complete.jar -visitor il.g4


javac --release 25 -cp .:antlr-4.9.2-complete.jar *.java



java -cp .:antlr-4.9.2-complete.jar Main my.net




nasm -f elf32 output.asm




ld -m elf_i386 output.o -o programa




./programa
