# Fractol - Interactive Fractal Renderer (C + MiniLibX)

## Overview

**Fractol** is a real-time, interactive fractal renderer written in **C** using the **MiniLibX** graphical library.  
It generates and displays **Mandelbrot and Julia sets**, with smooth zooming, parameterized variations, and psychedelic color effects.  
This project combines **complex number math**, **low-level graphics**, and **event-driven programming** to deliver an engaging, educational, and highly optimized experience.

---

## Features

- **Fractal Sets**
  - Mandelbrot Set (default)
  - Julia Sets (customizable via command-line parameters)

- **Interactivity**
  - Zoom in/out using mouse scroll (infinite depth exploration)
  - Parameterized Julia sets via command-line arguments
  - Real-time window updates without lag
  - ESC key or window close button cleanly exits the program

- **Color Mapping**
  - Dynamic color palettes based on iteration depth
  - Encouraged visual experimentation with trippy or gradient-based schemes

- **Graphics Handling**
  - Renders to a window using **MiniLibX**
  - Smooth handling of minimize/restore and OS-level window events

---


## Build & Run

```bash
git clone https://github.com/luizakar2002/fractol.git
cd fractol
make
./fractol mandelbrot        # for Mandelbrot set
./fractol julia 0.285 0.01  # for Julia set with parameters
