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

## tostr(i: any)

Returns `"<i>"`

## read (Add 2 new functions, `read` and `readline`, `read` is the portable function, while readline is POSIX based and can be disabled during compilation.)

Portable input function.

## greadline (Add 2 new functions, `read` and `readline`, `read` is the portable function, while readline is POSIX based and can be disabled during compilation.)

binds to readline() in C. Only available on supported OSes, on windows this function does not exist.

## sum(int, int)

Sum expects two numbers, anything else is undefined behavior. 

Returns int + int

## Globals

`args` - Global def cache.

```

def argtest() {
    println(args);
}

argtest("Hello");

```

`Hello`

