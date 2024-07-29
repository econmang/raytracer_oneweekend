# Introduction

I'm learning about ray tracing and graphics programming, as I haven't really worked on projects in that realm since school.
Currently working through the book "Ray Tracing in One Weekend" by Peter Shirley.

The book can be found and followed here: [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

# Notes

## Chapter 2 

PPM files are a really simple image format. First line is a header (P3 meaning colors are in ASCII), then the height and width, and then a list of RGB values for each pixel.

`cmake -B` is the generate step and generates all targets specified by `CMakeLists.txt`<br>
`cmake --build` is the build step that calls the C++ compiler

## Chapter 3

Vec3 class created and aliased for colors and pixels. You can `inline` functions to have the compiler insert the function body directly into the code, which limits the overhead of function calls by limiting control transfer. The `operator` keyword is used to indicate operator overloads.

## Chapter 4

Review: the equation of a ray is $P(t)=A+tb$, where $P$ is a 3D point, $A$ is the ray origin, and $b$ is the ray direction. The parameter $t$ is a real number (double) that can be used to traverse the ray.

Steps for calculating a ray to send through the viewport, pulled from the book:
> 1. Calculate the ray from the “eye” through the pixel,<br>
> 2. Determine which objects the ray intersects, and<br>
> 3. Compute a color for the closest intersection point.

Aspect ratio is the ratio of the width to the height ($\text{width}/\text{height}$).
The viewport is the digital rectangle through which our rays pass. Essentially the visible area of the scene.

The camera center is a point in 3D space where all rays originate (commonly called the *eye point*).
The vector from the camera center to the viewport center will be orthogonal to the viewport.
The distance from the camera center to the viewport is the *focal length*.

This creates some conflict since the viewport is using traditional coordinates, but the image coordinates start from the top left corner.
To help navigate the pixel grid, we'll use $\vec{u}$ from the left to right edge and $\vec{v}$ from the top to the bottom edge.

## Chapter 5

Review: Equation for a sphere: $x^2+y^2+z^2=r^2$.<br>
Similarly, we can define a sphere centered at an arbitrary point $(C_x, C_y, C_z)$ as: $$(C_x-x)^2+(C_y-y)^2+(C_z-z)^2 = r^2$$

Given that we want most items to be defined as vectors for ease of use, programmatically, we can rewrite the sphere equation as: $$(\vec{C}\cdot\vec{P}(t))^2=r^2$$

Then, since $\vec{P}(t)$ is our ray equation, and $\vec{P}(t) = \vec{Q}+t\vec{d}$, we can substitute that in to get: $$(\vec{C}-(\vec{Q}+t\vec{d}) \cdot \vec{C}-(Q+t\vec{d}))=r^2$$

Solving for $t$, we get: $$(-t\vec{d}+(\vec{C}-\vec{Q})\cdot(-t\vec{d}+(\vec{C}-\vec{Q})))=r^2 \rightarrow \boxed{t^2\vec{d}\cdot \vec{d} - 2t\vec{d}\cdot(\vec{C}-\vec{Q})+(\vec{C}-\vec{Q})\cdot(\vec{C}-\vec{Q})-r^2=0}$$

Since this is a quadratic equation, we can solve it with the quadratic formula: $$\frac{-b\pm\sqrt{b^2-4ac}}{2a}$$ where: $$a=\vec{d}\cdot\vec{d}$$ $$b=-2\vec{d}\cdot(\vec{C}-\vec{Q})$$ $$c=(\vec{C}-\vec{Q})\cdot(\vec{C}-\vec{Q})-r^2$$

Review: The discriminant is the part of the quadratic formula under the square root.

If the discriminant is positive there are two real solutions, if zero there is one real solution, if negative there are no real solutions.

## Chapter 6

The surface normal vector is the vector perpendicular to the surface of an object at the point of intersection.
We can simplify the hit function by considering the case where $b=-2h$. Then the discriminant is: 
$$\displaylines{\frac{-b \pm \sqrt{b^2-4ac}}{2a} \\ \frac{-(2h) \pm \sqrt{(-2h)^2 - 4ac}}{2a} \\ \frac{2h \pm 2\sqrt{h^2-ac}}{a}}$$
Which we can further simplify to solve for $h$, yielding:
$$\displaylines{b = -2d \cdot (\vec{C}-\vec{Q}) \\ b = -2h \\ h = \frac{b}{-2} = \vec{d} \cdot (\vec{C}-\vec{Q})}$$

We can create a hittable abstraction (ostensibly an interface) to create a common framework for all objects interacting with light in the scene.
This can then be implemented on an object (i.e. a sphere class can be created implementing `hittable`).

We can also make a decision as to the direction of the normal vector. If the ray is coming from inside the sphere, the normal vector should point inwards. Alternatively, if the ray is coming from outside the sphere, the normal vector should point outwards. This decision is important for objects that can have different sides or an inside and outside to be hit by the ray (i.e. glass spheres).

Assume we want the normal vectors to point outwards. We can use the dot product of the ray direction and the normal vector to determine if the ray is coming from inside or outside the sphere.

## Progress:
6.6 Some New C++ Features
