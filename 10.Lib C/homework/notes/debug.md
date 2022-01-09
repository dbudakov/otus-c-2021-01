# debug

## libcjson.so: cannot open shared object file: No such file or directory

```sh
sudo echo '/usr/local/lib64' >/etc/ld.so.conf.d/libcjson-x86_64.conf 
sudo ldconfig
```
## other

```sh
# rm -f /etc/ld.so.cache
```

```sh
# check link libs
ldconfig -p | grep <lib>

# check links use libs
ldd <progName>

# append flags for build
pkg-config --list-all | grep json
pkg-config --cflags --libs libcjson
```
