# Домашнее задание

## Installation

[link](https://gstreamer.freedesktop.org/documentation/installing/on-linux.html?gi-language=c)
[link](https://developer.ridgerun.com/wiki/index.php?title=Creating_a_New_GStreamer_Element_or_Application_Using_Templates)  

#### notes

Последний раз не нашел модуль fs для meson

## links

wav file structure: [link](https://sites.google.com/site/devusb/waveformat)


## Method compilation

gcc main.c -o app `pkg-config --cflags --libs gstreamer-1.0

## Question

Во первых какой элемент в пайплайне и что мы называем пайплайном получается всю строку из  *** ! ***
Насколько глубоко писать нужно ли настраивать Bus и Clock
какие действия требуются после конфигурации.

## Заметки

[link](notes)   
[systutorials](https://www.systutorials.com/docs/linux/man/1-gst-launch-1.0/)    
