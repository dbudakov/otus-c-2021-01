# Типы данных

Цель:
В процессе выполнения ДЗ вы получите навык работы с файлами со специализированной структурой.

Написать программу, определяющую, является ли заданный файл т.н. Rarjpeg-ом (изображением, в конец которого дописан архив), и выводящую список файлов в архиве, если заданный файл таковым является.
Для простоты подразумевается формат архива zip, а не rar. Сторонние библиотеки не использовать.
Требования:

Создано консольное приложение, принимающее аргументом командной строки входной файл.
Приложение корректно определяет файл, не содержащий внутри архив (файл для проверки прилагается).
Приложение корректно определяет файл, содержащий внутри архив, и выводит список файлов внутри архива (файл для проверки прилагается).
Код компилируется без warning'ов с ключами компилятора -Wall -Wextra -Wpedantic -std=c11.
Далее успешность определяется code review.

# Решение
Для запуска нужно склонировать репозиторий 
```sh
git clone https://github.com/dbudakov/c-2021-01 dbudakov
```
Перейти к каталогу с решением ДЗ
```sh
cd "dbudakov/04.Data types/homework/"
```
Скомпилировать программу и запустить ее
```sh
make
./rarjpeg files/non-zipjpeg.jpg
./rarjpeg files/zipjpeg.jpg
```

## Примечания
Корректно обрабатывает несколько аргументов
```sh
./rarjpeg files/non-zipjpeg.jpg files/non-zipjpeg.jpg
```
## Дополнительно
Сигнатуры первого включение архива в файл и конец jpeg файла:
```sh
./a.out files/zipjpeg.jpg |sed 's/255 217/255-217/g'|sed 's/ /\n/g'|grep -E '255-217' -no
```

## Источники
[qipu.ru](https://qipu.ru/tele2/sozdanie-polzovatelskogo-izvestnogo-tipa-faila-dlya-r-studio-signaturnye.html)  

<sys/stat.h>  
[pubs.opengroup.org](https://pubs.opengroup.org/onlinepubs/009604499/basedefs/sys/stat.h.html), [opennet.ru](https://www.opennet.ru/cgi-bin/opennet/man.cgi?topic=stat&category=2)

Процесс:  
[blog2k.ru](https://blog2k.ru/archives/3391#EOCD), [blog2k.ru](https://blog2k.ru/archives/3392)  

Проверка на чтение, но только для владельца файла: [unix.com](https://www.unix.com/programming/24978-s_irusr.html)  

## Code review 

```
выключить выравнивание в структурах через #pragma pack(1) и аккуратно проверять значения, прочитанных из файла (в этом может помочь вот такая вспомогательная функция: https://gist.github.com/ccbrown/9722406).
