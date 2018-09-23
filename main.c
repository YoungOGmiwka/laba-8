#include <stdio.h>
#define YES 1
#define NO 0
#define LEN 100

int main ()
{
char str[LEN];
char c; 
char prev_c;
char *begin;
char *end;
char *ptr; // указатель на текущий символ 

gets(str); 

begin = str;
end = str;
ptr = str;
prev_c = ' ';

do
{
c = *ptr;
if (c == ' ' && prev_c !=' ')
{
end = ptr-1;
}
if (c!=' ' && prev_c == ' ')
{
begin = ptr;
}
if ((*end == *begin)&&(end!=str))
{
char *src = end + 1; // цикл перезапси 
char *dst = begin;
while( (*dst++ = *src++ ) != '\0' );
begin = ptr;
}
ptr++;
prev_c = c;
}
while (c!='\0');

puts(str);
return 0;
}
