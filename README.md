# Image to ASCII

This small program convert some image formats to ASCII representation and print it to the terminal in raw format

# Build
Firstly, you should build OpenCV lib:
```bash
$ cd contrib/
$ rm -rf build
$ mkdir build && cd build
$ cmake .. -G Ninja
$ ninja
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
$ ./img2ascii <path_to_image> [OPTION]
```

Initially it runs with scale factor=1, but you can change it, by adding -r parameter in command

```bash
$ ./img2ascii <path_to_image> -r 0.3
```


