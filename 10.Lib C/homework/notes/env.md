# Установка окружения (cJSON and curl-devel)

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
