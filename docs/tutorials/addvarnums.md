# how to add two variable numbers in ISys++?

```

var one = 1
var two = 2
var x = sum(one, two)
printf(x, "\n")

```

Output:

`3`

## Why?

Using + on variables is undefined behavior (as of 1.0.4)

```

>>>var one = 1
1
>>>var two = 2
2
>>>one + two
1
>>>sum(one,two)
3
```

### Breakdown

There's a simple, easy to use function called `sum` which works like C++'s `+` operator.

`var one = 1`

This is a tutorial for variables, so we need two variables with two numbers.

`var two = 2`

Read above

`var x = sum(one, two)`

This gets the sum of 1 + 2, equivalent of just writing `var x = 1 + 2`, except this doesn't work on variables.

`printf(x, "\n")`

Prints "x" with a newline.
