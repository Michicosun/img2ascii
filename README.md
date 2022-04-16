# Image to ASCII

This small program convert some image formats to ASCII representation and print it to the terminal in raw format

# Build
```bash
git clone --recursive https://github.com/Michicosun/img2ascii
```

Firstly, you should build OpenCV lib:
```bash
$ cd contrib/
$ rm -rf build
$ mkdir build && cd build
$ cmake .. -G Ninja
$ ninja opencv_imgcodecs
```

If you want a static build of the program, add ***-DBUILD_SHARED_LIBS=OFF*** parameter for cmake 
```bash
$ cmake .. -G Ninja -DBUILD_SHARED_LIBS=OFF
```

On the second stage, build the program:
```bash
$ cd path_to_img2ascii
$ rm -rf build
$ mkdir build && cd build
$ cmake .. -G Ninja
$ ninja img2ascii
```

# Interface:
```bash
$ ./img2ascii <path_to_image> [OPTIONS]
```

Initially it runs with scale factor=1, but you can change it, by adding -r parameter in command

```bash
$ ./img2ascii <path_to_image> -r 0.3
```

Also, you can turn on colored output by adding -c key
```bash
$ ./img2ascii <path_to_image> -r 0.3 -c
```


