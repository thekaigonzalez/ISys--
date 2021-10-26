# How to append data to a variable

```

# Code to append data to variable

# (using standard library)

# define variable "one"
var one = 1;

# ...
println("Variable One before mutation: ", one);

# define variable "two"
var two = 2;

# concat "two" to a string "two_s"
var two_s = tostr(two);

# append "two_s" to "two" as a string (turns to int)
var twelve = append("one", two_s);

# ...
println("Variable one after mutation: ", one);

# Since it should be "twelve"
# Multiply it by 2 to get 24
var t_two = mul(one, 2);

println("Multiplied: ", t_two);

```

## Why?

This works because of the debug function `append`, where it searches the variable memory to find the variable, and appends the data you pass into it.

This one doesn't need a breakdown, all of the info you need is in the code.