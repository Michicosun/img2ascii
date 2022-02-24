
set(CMAKE_BUILD_TYPE "")

set(BUILD_SHARED_LIBS "ON")

set(CMAKE_C_FLAGS "   -fsigned-char -W -Wall -Wreturn-type -Wnon-virtual-dtor -Waddress -Wsequence-point -Wformat -Wformat-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wuninitialized -Winconsistent-missing-override -Wno-delete-non-virtual-dtor -Wno-unnamed-type-template-args -Wno-comment -Wno-deprecated-enum-enum-conversion -Wno-deprecated-anon-enum-enum-conversion -fdiagnostics-show-option -Wno-long-long -pthread -Qunused-arguments -ffunction-sections -fdata-sections  -msse -msse2 -msse3 -fvisibility=hidden -fvisibility-inlines-hidden")

set(CMAKE_C_FLAGS_DEBUG "-g  -O0 -DDEBUG -D_DEBUG")

set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG  -DNDEBUG")

set(CMAKE_CXX_FLAGS "   -fsigned-char -W -Wall -Wreturn-type -Wnon-virtual-dtor -Waddress -Wsequence-point -Wformat -Wformat-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wuninitialized -Winconsistent-missing-override -Wno-delete-non-virtual-dtor -Wno-unnamed-type-template-args -Wno-comment -Wno-deprecated-enum-enum-conversion -Wno-deprecated-anon-enum-enum-conversion -fdiagnostics-show-option -Wno-long-long -pthread -Qunused-arguments -ffunction-sections -fdata-sections  -msse -msse2 -msse3 -fvisibility=hidden -fvisibility-inlines-hidden")

set(CMAKE_CXX_FLAGS_DEBUG "-g  -O0 -DDEBUG -D_DEBUG")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG  -DNDEBUG")

set(CV_GCC "")

set(CV_CLANG "1")

set(ENABLE_NOISY_WARNINGS "OFF")

set(CMAKE_MODULE_LINKER_FLAGS "  -Wl,--gc-sections -Wl,--as-needed -Wl,--no-undefined")

set(CMAKE_INSTALL_PREFIX "/usr/local")

set(OPENCV_PYTHON_INSTALL_PATH "")

set(OpenCV_SOURCE_DIR "/home/michicosun/Desktop/img2ascii/contrib/opencv")

set(OPENCV_FORCE_PYTHON_LIBS "")

set(OPENCV_PYTHON_SKIP_LINKER_EXCLUDE_LIBS "")

set(OPENCV_PYTHON_BINDINGS_DIR "/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator")

set(cv2_custom_hdr "/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_custom_headers.h")

set(cv2_generated_files "/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_enums.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_funcs.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_include.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_modules.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_modules_content.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_types.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_generated_types_content.h;/home/michicosun/Desktop/img2ascii/contrib/build/opencv/modules/python_bindings_generator/pyopencv_signatures.json")
