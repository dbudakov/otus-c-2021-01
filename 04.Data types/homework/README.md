# Title

## Источники

<https://qipu.ru/tele2/sozdanie-polzovatelskogo-izvestnogo-tipa-faila-dlya-r-studio-signaturnye.html>

<sys/stat.h>  
<https://pubs.opengroup.org/onlinepubs/009604499/basedefs/sys/stat.h.html>
<https://www.opennet.ru/cgi-bin/opennet/man.cgi?topic=stat&category=2>

Процесс:  
<https://blog2k.ru/archives/3391#EOCD>  
<https://blog2k.ru/archives/3392>  

Проверка на чтение, но только владельца файла: <https://www.unix.com/programming/24978-s_irusr.html>  


первое включение конец jpeg файла:
./a.out files/zipjpeg.jpg |sed 's/255 217/255-217/g'|sed 's/ /\n/g'|grep -E '255-217' -no
