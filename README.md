# Truss Force Calculator

This is a project for me to learn C by rewriting the truss force calculator I had previously written in python.

## Building

This project uses meson to build. To build it first run 

```bash
meson init builddir
```

That generates the build directory, afterwards to create the executable (or recompile it) run

```bash
meson compile -C builddir

# OR

cd builddir
meson compile
```
