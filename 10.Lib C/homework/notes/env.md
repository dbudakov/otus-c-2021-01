# Установка окружения (cJSON and curl-devel)

## fedora
```sh
sudo yum -y install epel-release
sudo yum -y install curl-devel git cmake3 
git clone https://github.com/DaveGamble/cJSON
cd cJSON
git reset --hard 203a0de
mkdir build
cd build
cmake3 ..
make
make install
```
## add links
```
sudo echo '/usr/local/lib64' >/etc/ld.so.conf.d/libcjson-x86_64.conf 
sudo ldconfig
```
