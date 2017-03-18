# MiniCompiler

This is my mini compiler which only knows the most basic commands, but i am planning on implementing a few interesting features in the near future. I uploaded everything you need to be able to install and compile a program.

**What do we need:**
*  a lexical analyzer, which in this case is [Flex](https://github.com/westes/flex)

* a parser a.k.a [Bison](https://www.gnu.org/software/bison/)

* an assembler, we will use [nasm](http://www.nasm.us/)

After downloading every file you can simply run the _install.bat_ which will install the compiler, subsequently compile my example program (in.txt) with _compile.bat_ and run _p.exe_ . You can change the name of the compiled file and the name of the exe file in the _compile batch_ file.
