# How to replace text in string ISys++?

```ispp

# Replace text in string

var str = "Hello, world!";

# create new string
var newstr = strreplace(str, "e", "o");

println((tostr(newstr)));

```

## Why?

This works because of the new "strreplace" function.

### Breakdown

`var str = "Hello, world!";`

Create str with "Hello, world!" as value

`var newstr = strreplace(str, "e", "o");`

Create new string with "Hollo, world!" as the value (since we replaced "e" with "o")

`println(newstr);`

Print the new string.

<!-- Search and replace functions usually don't return **Quoted Strings** So you need to either use printf or nest [`tostr`](../manual/1/1.0.4/baselib.md#tostr(i: any)) in it. -->