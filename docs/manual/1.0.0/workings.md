# Inner Workings

## 1.0 - Functions (in C++)

Functions are binds to C++ code. For example, the "println" function.

```c++

int b_println(std::string arguments) {
    std::cout << PrettyPrint(arguments) << std::endl;
    return 1;
}

```

## 1.1 - Eval

Eval works like a loop, it evaluates a statement and returns the evaluation of the statement.

Statements return strings, and the strings are turned into integers, floats, etc ...

Variables have evaluated statements, so 

```

var c = 1 + 1

print(c)

```

Is the same as 

```

print(1 + 1)

```