# Introduction

I'm learning about ray tracing and graphics programming, as I haven't really worked on projects in that realm since school.
Currently working through the book "Ray Tracing in One Weekend" by Peter Shirley.

The book can be found and followed here: [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

# Notes

## Chapter 2 

PPM files are a really simple image format. First line is a header (P3 meaning colors are in ASCII), then the height and width, and then a list of RGB values for each pixel.

`cmake -B` is the generate step and generates all targets specified by `CMakeLists.txt`
`cmake --build` is the build step that calls the C++ compiler

## Chapter 3

Vec3 class created and aliased for colors and pixels. You can `inline` functions to have the compiler insert the function body directly into the code, which limits the overhead of function calls by limiting control transfer. The `operator` keyword is used to indicate operator overloads.

## Chapter 4

Review: the equation of a ray is $P(t)=A+tb$, where $P$ is a 3D point, $A$ is the ray origin, and $b$ is the ray direction. The parameter $t$ is a real number (double) that can be used to traverse the ray.

Steps for calculating a ray to send through the viewport, pulled from the book:
> Calculate the ray from the “eye” through the pixel,
> Determine which objects the ray intersects, and
> Compute a color for the closest intersection point.

## Progress:
4.2 Sending Rays Into the Scene
