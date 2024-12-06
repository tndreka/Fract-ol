# Fractol - Fractal Exploration Program

## Overview

The following program, **Fractol**, is a graphical application developed for exploring and rendering fractals, namely the **Julia Set** and the **Mandelbrot Set**. For this task, I employed the **MLX42** library to handle graphical output, window management, and input from the user. The resulting program allows the user to zoom in and out using the mouse wheel and generate various sets of Julia by passing arguments through the command line.

## Key Concepts Learned

1. **Fractals**:
   - A fractal is a self-replicating geometric shape, and for this project, I focused on the **Julia Set** and **Mandelbrot Set**.
     - **Julia Set**: This set is created by iterating the function `z = z^2 + c`, where `c` is a constant complex number. Each point in the complex plane is tested for divergence.
     - The **Mandelbrot Set** is similar but represents every point in the complex plane by the complex variable `c` and iterates using the formula `z = z^2 + c`.

2. **Graphical Rendering**:
   - **MLX42** was used for rendering, which allowed me to draw pixels and manage windows. The fractals are rendered based on calculating the number of iterations taken by each point to get out of a set boundary; each point is colored by the depth. 

3. **Interacting Features**:
   - The mouse wheel is responsible for the zooming feature in and out of fractals, dynamically changing the view. This requires capturing mouse events and modifying the rendering appropriately.
   - I handle keyboard events, such as pressing the **ESC** key to close the window.

4. **Window Management**:
   - **MLX42** helps manage the creation and interaction with the window. I can resize the window and switch between windows, ensuring smooth interaction during rendering.
   - The program exits cleanly when I press **ESC** or click the close button on the window.

5. **Dynamic Julia Sets**:
   - The parameterization of the **Julia Set** can be made through different parameters passed via the command line. This allows the generation of unique Julia sets with different behaviors.

6. **Error Handling**:
   - I ensure that the program checks for valid parameters. If no parameters or invalid parameters are given, it lists a set of valid options and quits cleanly.

7. **Memory Management**:
   - I learned how to handle memory for efficiently rendering large fractals using `malloc` and `free`.

## Using MLX42

- **Window Creation**:
   - I created a graphical window using `mlx_init` and `mlx_new_window` from MLX42 where the fractals are rendered.
   
- **Drawing Pixels**:
   - **MLX42** has `mlx_pixel_put` for drawing a pixel on the window, which is essential for the fractal shapes to be rendered.

- **Mouse and Keyboard Events**:
   - MLX42 captures mouse events (such as scrolling to zoom) and keyboard events (such as pressing ESC to close the window).

- **Rendering**:
   - The fractals are displayed using `mlx_put_image_to_window`, which places the generated fractal image into the window.

## Program Requirements

- **Fractal Types**: The program supports both the **Julia Set** and **Mandelbrot Set**.
- **Zooming**: Use the mouse wheel for zooming.
- **Julia Sets Customization**: The program draws various Julia sets using parameters passed when the program is run.
- **Error Handling**: In the case of incorrect or absent parameters, the program prints an error message and quits.
- **Window Handling**: The program will handle window resizing and interactions.
- **Proper Quitting**: ESC or the close button closes the program.

## Example Usage

To display a **Mandelbrot Set**:

```bash
./fractol mandelbrot
