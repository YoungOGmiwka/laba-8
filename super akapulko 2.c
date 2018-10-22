#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
// определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);
int main(void)
{
	char line[MAXLINE];
	fgets(line, MAXLINE, stdin);
	process_line(line);
	puts(line);

	getchar();

	return 0;
}
void process_line(char buffer[])
{
	char *buf_ptr; // указатель на текущий символ буфера
	char *end; // указатель на конец слова
	char *begin; // указатель на начало слова
	int flag; // признак слова
	
	// начальные присваивания (инициализация переменных)
	flag = NO;
	

	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	// цикл чтения символов из строки
	do
	{

		if (((*buf_ptr < 'a') || (*buf_ptr > 'z')) && ((*buf_ptr < 'A') || (*buf_ptr > 'Z')))
		{
			// найден разделитель
			if (flag == YES)
			{
				// найден первый разделить после слова
				end = buf_ptr - 1  ; // запомнить указатель на
				// конец слова

				if(*begin == *end )
				{ 
					char *src = end + 1;
					char *dst = begin;
					// удаление слова (перенос оставшейся части строки)
	
					while ((*dst++ = *src++) != '\0');
					buf_ptr = buffer;
					buf_ptr++;
				}
			}
			flag = NO;
		}
		else
		{
			// найдена буква
			if (flag == NO)
			{
				begin = buf_ptr; // запомнить указатель на начало
				flag = YES;
			}
		
		}
		buf_ptr++; // продвинуть вперёд указатель на текущий символ
	} while (*buf_ptr != '\0');
}
