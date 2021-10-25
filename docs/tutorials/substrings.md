# How to get a substring with ISys++

```

var str = "Hello:Goodbye"
var delim = ":"
var delimlocation = locate(str, delim)
var sub = substr(str, 0, delimlocation)
printf(sub, "\n")

```

Output:

`Hello`

## Why?

### Breakdown

`var str = "Hello:Goodbye"`

Declare variable `str`.

`var delim = ":"`

We declare "delim" as the delimiter we want to use.

`var delimlocation = locate(str, delim)`

We want to get the entire string up to "delim", so we need to get the position of the delimiter in the string.

`var sub = substr(str, 0, delimlocation)`

We get the substring of the string from the beginning (char at index 0) to the index of the delimiter location.