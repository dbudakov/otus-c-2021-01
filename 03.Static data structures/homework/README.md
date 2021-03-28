# Домашнее задание

## Статические структуры данных

**Цель**: В процессе выполнения ДЗ вы получите навык работы с различными текстовыми кодировками.  

1. Написать конвертор из заданной кодировки (cp-1251, koi8, iso-8859-5) в utf-8.  
2. Сторонние библиотеки не использовать.  

**Требования**:

1. Создано консольное приложение, принимающее аргументами командной строки входной файл, заданную кодировку и выходной файл.  
2. Конвертация из каждой из трёх указанных кодировок корректно отрабатывает(файлы для проверки прилагаются).  
3. Приложение корректно обрабатывает ошибки доступа к файлам.  
4. Код компилируется без warning'ов с ключами компилятора  
`-Wall -Wextra -Wpedantic -std=c11`.  
5. Далее успешность определяется code review.  
  
## Решение

Сборка выполняется через **Makefile**, обрабатываются аргументы **all**, **clean**, **fclean**, **re**:

```sh
git clone https://github.com/dbudakov/c-2021-01
cd "c-2021-01/02.Static data structures/homework/"
make 
```

Для проверки нужно выполнить со следующими параметрами:  
**source_file**: *./other/cp1251.txt*, *./other/koi8.txt*, *./other/iso-8859-5.txt*  
**encoding**: *cp-1251*, *koi8*, *iso-8859-5*  

```sh
./to_utf8 <source_file> <encoding> <output_file>
```

## Дополнительно

Не получилось реализовать полную таблицу символов включая не перчатные, требуется много времени чтобы прийти к решению как достать все коды для cp1251,koi8-r,iso-5589-5 соответсвтвующие кодам символов в диапазоне 127-255 для utf8.  