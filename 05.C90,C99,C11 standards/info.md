#

Документация по стандартам [link](https://en.cppreference.com/w/)  

## Undefined Behaviou Sanitizer

<https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html#index-fsanitize_003dundefined>

```c
$ cat test.c
int main(int argc, char **argv) {
int k = 0x7fffffff;
k += argc;
return 0;
}
```

```sh
gcc -fsanitize=undefined test.c
./a.out
```

## Address Sanitizer

<https://github.com/google/sanitizers/wiki/AddressSanitizer>

```c
#include <stdlib.h>
int main() {
char *x = (char*)malloc(10 * sizeof(char*));
free(x);
return x[5];
}
```

```sh
$ gcc -fsanitize=address test.c
$ ./a.out
==25480==ERROR: AddressSanitizer: heap-use-after-free on address 0x60700000dfb5 at pc 0x0000004007d4 bp 0x7fff7645f390 sp 0x7fff7645f380

gcc -W... - warning
gcc -o... - optimization
gcc -f... - modification
```

## Статические анализаторы кода [01:20]

Можно встраивать в CI  

- [Clang Static Analyzer](https://clang-analyzer.llvm.org/)  
- [Cppcheck](http://cppcheck.sourceforge.net/)  
- [PCS studio](https://www.viva64.com/ru/pvs-studio)  
  - [блог на Хабре](https://habr.com/ru/company/pvs-studio)

## Best proctices [01:24]

- [SEI CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)  
- [MISRA C](https://www.misra.org.uk/Buyonline/tabid/58/Default.aspx)  
- [NASA C style guide](https://ntrs.nasa.gov/api/citations/19950022400/downloads/19950022400.pdf)  
- [Steve Oualline. C Elements of Style: The Programmer’s Style Manual for](http://www.oualline.com/books.free/style/index.html)  
- [Elegant C and C++ Programs](http://www.oualline.com/books.free/style/index.html)  
- “C с классами”

## Style guides [01:29]

- [Linux kernel coding style](https://www.kernel.org/doc/html/v4.19/process/coding-style.html)  
- [GNU coding standards](https://www.gnu.org/prep/standards/standards.html#Writing-C)  - linux дистрибутив по сути является, совокупностью ядра linux и gnu окружения(утилит)  
- [FreeBSD kernel style guide](https://www.freebsd.org/cgi/man.cgi?query=style&apropos=0&sektion=9&manpath=FreeBSD+12.1-RELEASE+and+Ports&arch=default&format=html)  
- [OpenSSL coding style](https://www.openssl.org/policies/codingstyle.txt)  
- [Apache Developers’ C Language Style Guide](https://httpd.apache.org/dev/styleguide.html)  
- [OpenResty C Coding Style Guide](https://openresty.org/en/c-coding-style-guide.html)  

## Автоматические форматтеры кода [01:33]

- [GNU indent](https://www.gnu.org/software/indent/manual/indent.html)  
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html)  
  – [clang-format configurator](https://zed0.co.uk/clang-format-configurator)

## Нестандартные стандартные библиотеки [01:35]

<http://www.etalabs.net/compare_libcs.html>  

- [MSVCRT](https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/c-run-time-library-reference?view=msvc-160)  
- [FreeBSD libc](https://github.com/freebsd/freebsd-src/tree/master/lib/libc)  
- [GNU libc](https://www.gnu.org/software/libc)  
- [musl libc](https://musl.libc.org/) - alpine  
- [uClibc](https://uclibc.org/about.html)  
- [dietlibc](http://www.fefe.de/dietlibc)  
- [Newlib](http://www.sourceware.org/newlib)  
- [klibc](https://ru.wikipedia.org/wiki/Klibc)  

[01:43]
объявление струкруры
fread в указатель на структуру
нужно искать определенную последовательность, где начинается zip
