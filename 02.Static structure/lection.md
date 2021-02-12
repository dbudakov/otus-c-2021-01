# Static data structures

## Лекция

### Массивы

```c
//многомерный массив(на три строки и 4 колонки(элемента)(row-major order - сначала указываются строки)
int a[3][4]= { 
	{0,1,2,3},
	{4,5,6,7},
	{8,9,10,11}
}
```

`23:30` sizeof не возвращает размер массива через указатель, только массив
Количество элементов в массиве: `sizeof array / sizeof array[0]` (размер всего массива, на массив элемента, не работает с указателем)

`27:38` массивы переменной длины(variable lang array)
При вызове массива переменной длины, не нужно освобождать памыть, память будет использована на уровне стека

```c
float read_andprocess(int n)
{
	float vals[n];

	for(int i = 0; i < n; ++i)
		vals[i] = read_val();

	return process(n,vals);
}
```

`32:56` rlineks, системный вызов для вывода текущего размера стека
адреса на куче начинаются с `7f` а на стеке с `1`
Размещение кода на стеке(не бо лее 1М) на порядок быстрее, но на куче(виртуальная память, как 2GB так и более) надежнее
`33:15` о кучах и стеке будет подробнее в теме POSIX

`35:15` Flexible array member(Гибкий элемент массива)
CPython - референсная имплементация языка python, когда запускается python'овский скрипт, запускается CPython,
Описанани того, что в языке python является строкой:
<CPython/Include/stringobject.h>

```c
typedef struct {
	PyObject_VAR_HEAD 
	long ob_shash; 
	int ob_sstate; 
	char ob_sval[1];
}PyStringObject;
```

### Cтроки 33:20

`char`(8bit) or `wchar_t`(16bit)(т.н. multibyte character sequence, MBCS	)

```c
char* str = "hello";

#include <wchar.h>
wchar_t* wstr = L"hello";
```

### Кодировки

coi8 
русские символы: cp1251,cp866
`55:00`
Кирилический символ `A`: Code points. Cyrillic Capital Letter A - U+0410
Кодировки: UTF-8, UTF-16(LE/BE), UTF-7, UCS-4 и т.д.

#### libicu.h

`58:13` - библиотека libicu.h(international components for unicode), для обработки строк отличных от стандарта asci
`01:00:00` - Unicode sandvich

#### iconv.h

`01:01:01` - <iconv.h>,библиотека для конвертации unicod'a
Важно следить за тем в какой кодировке сохранен файл с исходным кодом

### Функции 01:07:00

`01:07:50` - callback, `C` не является функциональным языком

`01:15:00` - соглашения вызова
Некий протокол определящий каким образом функция получает аргументы и возвращает, возвращает через региста RAX,EAX
`cdecl`, `stdcall`, `fastcall`, `thiscall`

`01:21:00` функции с переменным числом аргументов, <stdarg.h>, va_list(variable argument)
Используются при организации логирования или манипулированием строками

`01:30:31` - `name mangling` коверканье имен

### Файлы 01:36:00

FILE* - т.н. opaque pointer(прозрачный указатель, тж "чеширский кот"), неопределенный тип(incomplete)

```c
#include <stdio.h>

FILE* stdin; 	// 0 дескриптор
FILE* stdout;	// 1 дескриптор
FILE* stderr;	// 2 дескриптор

FILE* fopen(const char* filename, const char* mode);
//mode: "r", "w", "a"; modifiers: "+", "b", "x" ; a-append(rw), + возможность дописывать, b бинарный режим, "x" - возвращает 0-ой указатель если файл существует, используется при обработке ошибок, если fopen вернет 0, значит файл неполучилось открыть

int fclose(FILE* fp); 
//нужно закрывать файлы, так как кол-во файловых дескрипторов ограничено

int  fflush(FILE* fp);
// сброс буферов на диск, например при записи файлов

// Блок функций отвечающих за чтение по сложности: символ, строку, также строку с доп функциями, последняя работает как scanf, только для файлов
int fgetc(FILE* fp); 
char* fgets(char* str, int num, FILE* fp);
size_t fread(void* ptr, size_t size, size_t count, FILE* fp);
int fscanf(FILE* fp, const char* format, ...);

//Блок функций отвечающих за запись
int fputc(int character, FILE* fp)
int fputs(const char* str, FILE* fp);
size_t fwrite(const void* ptr,  size_t size,  size_t count, FILE* fp);
int fprintf(FILE* fp, const char* format, ...);

// 01:47:00 - несколько моментов по прокрутке
// Прокрутка указателя на текущий символ(байт) в файле: файл, offset-место, origin - направление прокрутки(произвольная, произвольная начинаю с текущей, произвольная с конца)
int fseek(FILE* fp, long int offset, int origin);
//origin: SEEK_SET, SEEK_CUR, SEEK_END

// Получение текущего места указателя в файле
long int ftell(FILE* fp)
```

`01:38:00` curl
CURL* - также неопределенный тип

## Фишки

`18:43` Обращение к массиву

```c
// E1[E2] is identical to (*((E1)+(E2))) - во второй части, как я думаю можно поменять местами слагаемые

int array[2];
array[2];
2[array];
*(array[0] + 2);
```

`21:42` Скорость обращения к массиву
Из-за формы row-major order(сначала указываются строки), обращение к массиву по горизонтале работает быстрее чем по вертикали

`22:00` - минимальный размер куска кеша(процессора), который будет запрошен для отдачи информации, для x86 - 64 байта, это порядка 8-ми int'ов

`01:06:00`
Представление длинной строки без выхода за 80 колонку, при компиляции строка склеится

```c
static const char* str = "my very very"
	"very very very"
	"long string constant";
//or
printf("%f; %f\n",
	average(2, 1.0,  2.0),
	average(3, 1.0, 2,0 3,0));
```

## Литература

`~45:00`
Алгоритм маляра Шлемиля (Спольски Дж.Джоэл о программировании).
Poul-Henning Kamp, The Most Expensive One-byte Mistake: <https://queue.acm.org/detail.cfm?id=2010365>
Список строковых функций: <https://en.wikipedia.org/wiki/C_string_handling>

COM-строки(BSTR)
Unicode и кодировки: <https://cyberforum.ru/blogs/33029/blog5139.html>

Отладка Windows приложений Джон Робинс, ассемблер

## Дополнительно

`01:09:00` C gibberish <-> english:<https://cdecl.org>
`slack` Сравнение функиональных языков [link]<https://github.com/cblp/funlangs>
`slack` Библиотека функций для работы с Unicode-строками [link]<http://site.icu-project.org/home>, документация [link]<https://unicode-org.github.io/icu-docs/apidoc/released/icu4c/>  
`slack` Стандарты языка С89(С90) [link]<http://port70.net/~nsz/c/c89/c89-draft.html>, C90 [link]<https://otus-cpp.slack.com/files/U01JQ774V50/F01M6UCLMTQ/c99.pdf?origin_team=T7UJAV3SP&origin_channel=G01J3GB1X35>, C11 [link]<https://otus-cpp.slack.com/files/U01JQ774V50/F01M6UCCG5U/c11.pdf?origin_team=T7UJAV3SP&origin_channel=G01J3GB1X35>.

### При выполнении ДЗ
Статья по _unicode_ на _habr'e_([link](https://habr.com/en/company/xakep/blog/257895/))  

Таблица ascii([link](https://ru.wikipedia.org/wiki/Windows-1251#/media/%D0%A4%D0%B0%D0%B9%D0%BB:Ascii1.gif)) и её раширенный вариант([link](https://ru.wikipedia.org/wiki/Windows-1251#/media/%D0%A4%D0%B0%D0%B9%D0%BB:Windows-1251-upper-half.gif))  
Таблица koi8-r([link](https://ru.wikipedia.org/wiki/%D0%9A%D0%9E%D0%98-8#%D0%9A%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_KOI8-R_(%D1%80%D1%83%D1%81%D1%81%D0%BA%D0%B0%D1%8F%29))  

Вывод _hexdecimal_ значения символа в нужной кодировке:  

```sh
echo -n "а" | iconv -f utf8 -t cp1251 | hexdump -C
echo -n "а" | hexdump -C
```

### Спойлеры

`01:41:00` - открытие файла в бинарном режиме, например картинка png
`01:48:48` - читать файл по строчке `while(fgets(buf,MAXLINE,stdin) != NULL`, а потом собирать строку. Посмотреть `strcat`,`strcpi`

### Домашка

Статья по unicode
Написать аналог `iconv`, но не использовать саму функцию
Посмотреть как все организовано на уровне байтов и что происходит под капотом
обработка флагов
-Wall - все warning
-Wextra - дополнительные warning
-Wpedantic - warning специального режима
-std=c11 - 11 стандарт

Три аргумента для программы Входной файл, заданая кодировка входного файла и выходной файл
аргументы через `getopt`(длинный, короткий), а можно принимать три, проверять что их три, если не три
выходить и также понимать что первый входной файл, второй кодировка, третий выходной файл

Для создание таблиц, вывести числовые коды неанглоязычных символов и перекодировать через `iconv`
