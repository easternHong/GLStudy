1./usr/bin/ld: 找不到 -lGLEW

sudo apt-get install libglew1.5 glew-utils



g++ main.cpp -lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread
g++ -lGL -lGLU -lglut -lGLEW main.cpp -o example


2./usr/bin/ld: 找不到 -lglfw
sudo apt-get install libglfw-dev


3.
```
hds@hds-cylan ~/workspace/cProject/GLTest $ g++ main.cpp -lglfw -lGL 
/tmp/ccIkIaqn.o：在函数‘main’中：
main.cpp:(.text+0x1e)：对‘glutInit’未定义的引用
main.cpp:(.text+0x28)：对‘glutInitDisplayMode’未定义的引用
main.cpp:(.text+0x37)：对‘glutInitWindowPosition’未定义的引用
main.cpp:(.text+0x46)：对‘glutInitWindowSize’未定义的引用
main.cpp:(.text+0x50)：对‘glutCreateWindow’未定义的引用
main.cpp:(.text+0x5f)：对‘glutDisplayFunc’未定义的引用
main.cpp:(.text+0x64)：对‘glutMainLoop’未定义的引用
/tmp/ccIkIaqn.o：在函数‘init()’中：
main.cpp:(.text+0x155)：对‘gluLookAt’未定义的引用
/tmp/ccIkIaqn.o：在函数‘display()’中：
main.cpp:(.text+0x19a)：对‘glutWireTeapot’未定义的引用
collect2: error: ld returned 1 exit status
```
//就没有满足 链接关系
解决：g++ main.cpp -lglut -lGL -lGLU -o test



4.在Clion的CMakeList中添加链接，摆脱命令行

```
link_libraries(-lglut -lGL -lGLU )
```



http://ptbsare.org/2014/05/17/ubuntu%E4%B8%8B%E4%BD%BF%E7%94%A8opengl%E5%9B%BE%E5%BD%A2%E5%BA%93/
http://blog.csdn.net/ffbp89/article/details/60756560
https://stackoverflow.com/questions/34340462/compiling-glfw-application-issues-with-linking-linux

