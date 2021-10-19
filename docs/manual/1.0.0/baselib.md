# baselib

Contains base functions hard-coded into the ISys++ interpreter.

## print(str: string)

Print `str` to stdout without `\n`. You can write `\n` but it's not recommended. For formatted print, use `println (new)`.

(Direct bind to std::cout from C++ 11)



## len(str: string)

Get the length of str.

Returns: `number of letters in <str> counting NUL`

## println(str: string) (NEW)

Prints `str` with \n, you can write