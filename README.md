> **WARNING** The "push_swap" project follows the norms set by the school 42, which some people may not agree with. Some users may feel that the structure of the project does not look aesthetically pleasing or intuitive due to the constraints imposed by these norms. However, it is important to remember that the purpose of the "push_swap" project is to teach students certain programming concepts and techniques, and the strict adherence to the norms set by the school is necessary to ensure that students are able to learn these concepts effectively.

# push_swap

push_swap is a program, a curriculum 42 project, that sorts a list of numbers with the fewest instructions applied to the list.

## How to run

The first thing to note is that this repo uses submodules. Once you have cloned it, run the following commands:

```
git submodule init
git submodule update
```

From now, you can compile the solution with the Makefile provided, using the command `make re`. This will create an executable (for linux), which you can run in the terminal, followed by the data file you want to display.

```
make re && ./push swap <number 1> <number ...>
```
