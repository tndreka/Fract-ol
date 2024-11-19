# Fractol - Fractal Exploration Program

## Overview

The **Fractol** program is a graphical application I created to explore and render fractals, specifically the **Julia Set** and **Mandelbrot Set**. I used the **MLX42** library to handle graphical rendering, window management, and user input. The program offers interactive features like zooming with the mouse wheel and creating different Julia sets by passing parameters via the command line.

## Key Concepts Learned

1. **Fractals**:
   - A fractal is a self-replicating geometric shape, and for this project, I focused on the **Julia Set** and **Mandelbrot Set**.
   - The **Julia Set** is created by iterating the function `z = z^2 + c`, where `c` is a constant complex number. Each point in the complex plane is tested for divergence.
   - The **Mandelbrot Set** works similarly but uses the complex variable `c` to represent points in the complex plane, iterating with `z = z^2 + c`.

2. **Graphical Rendering**:
   - I used **MLX42** for rendering, which allowed me to draw pixels and handle window management. The fractals are rendered by calculating the number of iterations each point takes to escape a set boundary, and colors are used to represent the depth of each point.

3. **Interactive Features**:
   - The mouse wheel is used to zoom in and out of the fractals, changing the view dynamically. This involves capturing mouse events and adjusting the rendering accordingly.
   - I also handle keyboard events, such as pressing the **ESC** key to close the window.

4. **Window Management**:
   - **MLX42** helps manage the creation and interaction with the window. I can resize the window and switch between windows, ensuring smooth interaction during rendering.
   - The program exits cleanly when I press **ESC** or click the close button on the window.

5. **Dynamic Julia Sets**:
   - The **Julia Set** can be customized with different parameters passed via the command line. This allows me to generate unique Julia sets with varied behaviors.

6. **Error Handling**:
   - I check for valid parameters in the program. If no parameters or invalid ones are provided, it displays a list of valid options and exits cleanly.

7. **Memory Management**:
   - I learned how to manage memory for rendering large fractals efficiently using `malloc` and `free`.

## Using MLX42

- **Window Creation**: 
   - I used `mlx_init` and `mlx_new_window` from MLX42 to create a graphical window where the fractals are displayed.
   
- **Drawing Pixels**:
   - **MLX42** provides `mlx_pixel_put` to draw individual pixels on the window, essential for rendering the fractal shapes.

- **Mouse and Keyboard Events**:
   - MLX42 captures mouse events (like scrolling to zoom) and keyboard events (like pressing ESC to close the window).
   
- **Rendering**:
   - The fractals are displayed by using `mlx_put_image_to_window`, which places the generated fractal image into the window.

## Program Requirements

- **Fractal Types**: The program supports both the **Julia Set** and **Mandelbrot Set**.
- **Zooming**: Zoom in and out using the mouse wheel.
- **Customizable Julia Sets**: The program generates different Julia sets by passing parameters when running the program.
- **Error Handling**: If parameters are invalid or missing, the program informs the user and exits properly.
- **Window Management**: The program supports smooth window resizing and interaction.
- **Clean Exit**: Press ESC or click the close button to exit the program.

## Example Usage

To display a **Mandelbrot Set**:

```bash
./fractol mandelbrot
