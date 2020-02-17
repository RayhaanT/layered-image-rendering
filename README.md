# Layered Image Rendering
This project uses OpenGL to render an interactive exploded view of an image in 3D. It uses stb_image to load the image layers, GLFW and glad to handle OpenGL, as well as some headers and shaders from Joey De Vries' https://learnopengl.com/.
The exploded view render can be rotated, scaled and the distance between layers can be changed.

Build command (in the main folder):
```
g++ -g src/*.cpp src/*.c -static -Iinclude -iquote include -Llib -lopengl32 -lglfw3 -lgdi32 -o render

```
