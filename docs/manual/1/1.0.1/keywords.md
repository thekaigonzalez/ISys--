# Keywords

Keywords are used in ISys++ to do certain things.

## Keyword 1.1 - var

Variables. Very simple.

`var x = value`

Value can be an integer, or a raw string.

Strings are hardcoded and can be detected using `"`.

`var x = "value"`

(NEW) variables now support return values.

functions haven't been implemented yet, but when they do, you can use returns to tell the interpreter to bind that value and the code
to the function name. And arguments expected.

## Keyword 1.2 - import

Importing files will aid in keeping code maintainable, as well as help traceback to errors or unexpected code.

`import <file>`

## Keyword 1.3 - if

The "If Statement" helps you control your code.

```

if var == "Value" {
    println("var is Value!");
};

```

## Keyword 1.4 - else

The "Else" Keyword basically does functions (or statements) if the if statement isn't valid.

If there's no `if` block then it will return Null & An Error message.

```

if hello = "Not Hello" {
    print("Impossible!\n");
}; else {
    print("There we go.\n");
};

```

`There we go.`

```

else {
    print("There we go.\n");
};

```

`'else' without previous 'if'`