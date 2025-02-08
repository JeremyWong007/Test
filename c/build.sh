export PATH=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin:$PATH

aarch64-linux-gnu-gcc -c example.c -o example.o
ar rcs libexample.a example.o