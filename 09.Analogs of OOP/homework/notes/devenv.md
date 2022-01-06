# Установка среды разработки под GStreamer

```sh
git clone https://gitlab.freedesktop.org/gstreamer/gst-build
cd gst-build/
meson builddir
cd buildir
ninja
#ninja: error: 'subprojects/pixman/pixman/libpixman-mmx.a.p/pixman-mmx.c.o', needed by 'subprojects/#pixman/pixman/libpixman-1.so.0.40.1', missing and no known rule to make

yum install pixman-devel
cd ..
meson builddir --reconfigure
cd buildir
ninja

# для входа в среду разработки
ninja devenv
```
