# How to check if input is hello?

```

printf("Type hello please. ");

var input = read();

if input = "hello" { 
    printf("Thanks!", "\n");
};
else { 
    printf("Hey, i said type hello!");
}

```

## Why?

This works because we ask the user to type "hello", if they do, then we do the first branch, if not, then we do the second branch.

### Breakdown

`printf("Type hello please. ");`

Ask user to type hello.

`var input = read();`

Read input from stdin.

`if input = "hello" {`

If the input is "hello", like we asked.

`printf("Thanks!", "\n");`

Thank the user.

`else {`

If it's not any of the above.

`printf("Hey, i said type hello!");`

Remind the user of the objective.