# Запуск плагинов

```sh
gst-launch-1.0 -v -m --gst-plugin-path="$plugin_path" \
               vimeosource location=https://vimeo.com/59785024 ! decodebin name=dmux \
               dmux. ! queue ! audioconvert ! autoaudiosink \
			   dmux. ! queue ! autovideoconvert ! autovideosink

gst-launch-1.0 -v -m myfilter location=./test.wav ! queue ! audioconvert ! autoaudiosink
gst-launch-1.0 ./build/gst-plugin/libgstMyFilter.s^C location=../test.wav ! wavparse ! audioconvert ! audioresample ! pulsesink

gst-launch-1.0 filesrc location=../test.wav ! wavparse ! audioconvert ! audioresample ! pulsesink
```
