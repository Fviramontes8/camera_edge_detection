# Camera Edge Detection
## Requirements
- Boost's Program Options
- CMake 3.14+
- OpenCV 3+

CMake will automatically try to find it. It has been tested with installing boost via apt, and installing cmake and opencv from source.
The install location of OpenCV is`/usr/local`, and CMake was installed in `/usr/local/bin`

## Build CMake project
```sh
cmake -B build
```

## Compile project
```sh
cmake --build build
```
or
```sh
cd build
make
```

## To run
```sh
./build/app/camera_edge_detection
```
Will look for camera at index 0 and try to open it

```sh
./build/app/camera_edge_detection -i 2
```
Will try to open camera at index 2

```sh
./build/app/camera_edge_detection --index 2
```
Analogous to previous example

```sh
 ./build/app/camera_edge_detection -h
```
or
```sh
./build/app/camera_edge_detection --help
```
Will bring up the help message