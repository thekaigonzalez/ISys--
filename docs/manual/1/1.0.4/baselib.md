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

## version()

Prints the most recent ISys++ version from the git branch. Non-mutable.

For mutable version strings, use [`ISYSPP_INTERPRETER_VERSION`](#isys_interpreter_version) combined with [`append`](#append) or [`remove_tl`](#remove_tl)

## remove_tl(var, text)

Searches for [text] in [var] and removes it.

## append(var, text)

append "text" to variable and returns the data passed.

NOTE: this blindly places text onto stack.

## ISYS_INTERPRETER_VERSION

Returns a string containing version information.

This is about milestones so it's updated every stable release.

## printf(param ...)

"Print format"

Prints "param" to stdout, takes unlimited arguments.

Stringifies all parameters if they're not already strings.

Takes param as CString. \n, \r, and others are valid.

<!-- KNOWN BUG: Printf currently discards the third parameter, working on fixes! -->
`printf("Hello, ", "New ", "World!"); -> Hello, New World!`

## locate(str, characters)

finds the index of characters in str and returns it.

## limit(int)

Gets string up to `int`

## substr(str, pos1, pos2)

returns a substr between pos1, and pos2.

## Globals

`args` - Global def cache.

```

def argtest() {
    println(args);
}

argtest("Hello");

```

`Hello`

