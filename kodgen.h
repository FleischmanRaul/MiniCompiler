#ifndef MYFILE_H
#define MYFILE_H

char *data;
char *text;

#define DATA_LENGTH 100000

#ifdef _WIN32
#define PROLOGUE ";;;;;;;;;;;;;\n\
; PROLOGUE\n\
;;;;;;;;;;;;;\n\
%include \"_io_win.asm\"\n\
section .text\n\
;;;;;;;;;;;;;\n\
\tglobal _main\n\
_main:\n\
\tenter 0,0\n\
;;;;;;;;;;;;;\n"
#elif linux
#define PROLOGUE ";;;;;;;;;;;;;\n\
; PROLOGUE\n\
;;;;;;;;;;;;;\n\
%include \"_io_lin.asm\"\n\
section .text\n\
;;;;;;;;;;;;;\n\
\tglobal main\n\
main:\n\
\tenter 0,0\n\
;;;;;;;;;;;;;\n"
#elif __APPLE__
#define PROLOGUE ";;;;;;;;;;;;;\n\
; PROLOGUE\n\
;;;;;;;;;;;;;\n\
%include \"_io_mac.asm\"\n\
section .text\n\
;;;;;;;;;;;;;\n\
\tglobal _main\n\
_main:\n\
\tenter 0,0\n\
;;;;;;;;;;;;;\n"
#else
#define PROLOGUE ";UNSUPPORTED OS"
#endif
#define EPILOGUE ";;;;;;;;;;;;;\n\
; EPILOGUE\n\
;;;;;;;;;;;;;\n\
\tleave\n\
\tret\n\
;;;;;;;;;;;;;\n"

void define_var(char *vname);
void movEAX_num(int num);
void movEAX_var(char *vname);
void pushEAX();
void popEBX();
void add();
void sub();
void mul();
void div();
void print_numexpr();
void let_var(char *vname);


void init_asm()
{
    data = new char[DATA_LENGTH];
	text = new char[DATA_LENGTH];
	strcpy(text, "");
	strcpy(data, "\nsection .data\n\
    ;;;;;;;;;;;;\n"); 
}
void generate_asm()
{
    fprintf(stdout, "%s", PROLOGUE);
	fprintf(stdout, "%s", text);
	fprintf(stdout, "%s", EPILOGUE);
	fprintf(stdout, "%s", data);
}
////////////////////////fuggvenyek//////////////////////////////////

void define_var(char *vname){
/* valtozo deklaralasa */
	sprintf(data, "%s\t%s dd 0\n", data, vname);
}

void movEAX_num(int num){
/* a szamot (num) beteszi az EAX-be */
	sprintf(text, "%s\
\tmov eax, %d\n\n", text, num);
}

void movEAX_var(char *vname){
/* a valtozo (vname) erteket bemasolja az EAX-be */
	sprintf(text, "%s\
\tmov eax, [%s]\n\n", text, vname);
}

void print_numexpr(){
/* kiirja EAX-et */
	sprintf(text, "%s\
\tpush eax\n\
\tcall print_int\n\
\tadd esp, 4\n\n", text);
}
void print_nl()
{
    /*uj sor*/
    sprintf(text, "%s\
\tcall print_newline \n\n", text);
}

void pushEAX(){
/* EAX-et a verembe helyezi */
	sprintf(text, "%s\
\tpush eax\n\n", text);
}

void popEBX(){
/* kiveszi a verem felso elemet az EBX-be */
	sprintf(text, "%s\
\tpop ebx\n\n", text);
}

void popEAX(){
/* kiveszi a verem felso elemet az EAX-be */
	sprintf(text, "%s\
\tpop eax\n\n", text);
}

void add(){
/* EAX-hez hozzaadja EBX-et */
	sprintf(text, "%s\
\tadd eax, ebx\n\n", text);
}

void sub(){
/* EBX-bol kivonja EAX-et */
	sprintf(text, "%s\
\tsub ebx, eax\n\
\tmov eax, ebx\n\n", text);
}

void mul(){
/* EAX-et osszeszorozza EBX-el */
	sprintf(text, "%s\
\timul eax, ebx\n\n", text);
}
void div(){
/* EAX-et elossza EBX-el */
	sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tidiv ebx\n\n", text);
}

void let_var(char *vname){
    /* a valtozoba (vname) az EAX-ben levo erteket tolti */
	sprintf(text, "%s\
\tmov [%s], eax\n\n", text, vname);
}

void tceq(int label)
{
    /*egyenlo-e eax ebx*/  
    sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tcmp eax,ebx\n\
\tjne neq%d\n\
\tmov edx,1\n\
\tneq%d:\n\
\tpush edx\n\n", text, label, label);
}

void tcne(int label)
{
    /*nem egyenlo-e eax ebx*/  
    sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tcmp eax,ebx\n\
\tje eq%d\n\
\tmov edx,1\n\
\teq%d:\n\
\tpush edx\n\n", text, label, label);
}

void tcle(int label)
{
    /*kissebb vagy egyenlo eax ebx*/  
    sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tcmp eax,ebx\n\
\tjg greater%d\n\
\tmov edx,1\n\
\tgreater%d:\n\
\tpush edx\n\n", text, label, label);
}

void tcge(int label)
{
    /*nagyobb vagy egyenlo eax ebx*/  
    sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tcmp eax,ebx\n\
\tjl lesser%d\n\
\tmov edx,1\n\
\tlesser%d:\n\
\tpush edx\n\n", text, label, label);
}

void tcl(int label)
{
    /*kissebb eax ebx*/  
    sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tcmp eax,ebx\n\
\tjge ge%d\n\
\tmov edx,1\n\
\tge%d:\n\
\tpush edx\n\n", text, label, label);
}

void tcg(int label)
{
    /*greater eax ebx*/  
    sprintf(text, "%s\
\tmov edx,0\n\
\tpop ebx\n\
\tpop eax\n\
\tcmp eax,ebx\n\
\tjle le%d\n\
\tmov edx,1\n\
\tle%d:\n\
\tpush edx\n\n", text, label, label);
}

void log_link_and()
{
    sprintf(text, "%s\
\tpop ebx\n\
\tand eax,ebx\n\
\tpush eax\n\n", text);
}

void log_link_or()
{
    sprintf(text, "%s\
\tpop ebx\n\
\tor eax,ebx\n\
\tpush eax\n\n", text);
}

void while_start(int label)
{
    sprintf(text, "%s\
\twhile_start%d:\n\n", text, label);
}
void while_start2(int label)
{
    sprintf(text, "%s\
\tcmp eax,0\n\
\tje while_end%d\n\n", text, label);
}
void while_end(int label)
{
    sprintf(text, "%s\
\tjmp while_start%d\n\
 while_end%d:\n\n", text, label, label);
}
void if_start(int label)
{
   sprintf(text, "%s\
\tcmp eax,0\n\
\tje if%d\n\n", text, label);
}
void if_end(int label)
{
   sprintf(text, "%s\
\tif%d:\n\n", text, label);
}

void if_else(int label)
{
   sprintf(text, "%s\
\tjmp if%d \n\
\tif%d:\n\n", text, label+1, label);
}
#endif
