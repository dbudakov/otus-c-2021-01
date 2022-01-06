# Настройка окружения GStreamer

Устрановка:
```sh
git clone https://gitlab.freedesktop.org/gstreamer/gst-build
cd gst-build/
meson builddir
cd buildir
ninja 

# Войти в окружение
ninja devenv
```

## Troubleshooting: 
При запуске `ninja` может возникнуть ошибка, возникает при отсутствии пакета `pixman-devel`  

```sh
# ninja: error: 'subprojects/pixman/pixman/libpixman-mmx.a.p/pixman-mmx.c.o', needed by 'subprojects/#pixman/pixman/libpixman-1.so.0.40.1', missing and no known rule to make

yum install pixman-devel

cd cd ../../gst-build
meson builddir --reconfigure
cd buildir
ninja 

ninja devenv
```
