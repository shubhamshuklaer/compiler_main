%{
    #include<stdio.h>
%}
%%
[a-z]* printf("fasdfasd %s",yytext);
. ;
%%
main(){
    yylex();
}
