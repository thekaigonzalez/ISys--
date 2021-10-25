# How to remove text from string in ISys++?

```

var cap = strremove("hello", "llo")
printf(cap, "\n")

```

Outputs:

`he`

## Why?

This works because of the new "strremove" function introduced in ISysPP Standard 1.0.5.

It searches for the text in a string and removes it.

### Breakdown

`var cap = strremove("hello", "llo")`

Removes "llo" from hello and returns "hello" without it.

`printf(cap, "\n")`

Prints the string.
