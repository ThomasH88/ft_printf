# ft_printf
My own version of the libc's printf function coded in C.

C library that contains the printf function with the following functionalities:
- Conversions: s, S, p, d, D, i, o, O, u, U, x, X, c, C
- Flags: #, 0, -, +, (space)
- Minimum field-width (e.g %5d)
- Precision (e.g %.5d)
- Flags: hh, h, l, ll, j, z
- Special Cases: double percentage sign (%%)

### How to use
- make --> will compile the library and generate the library named 'libftprintf.a'
- make clean --> to clean the '*.o' files and delete the 'objs' directory
- make fclean --> cleans objects and library
- make re --> cleans objects and library and recompiles library
