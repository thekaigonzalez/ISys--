# Manual Index (The if statement update)

- [baselib](./baselib.md)
- [keywords](./keywords.md)
- [inner workings](./workings.md)
<!-- - [Features](./features.md) -->

One of the newest features of ISys++ 1.0.5 is the new evaluator.

There's a lot of updates to the way data is handled, and to the standard library.

The standard library has changed, please look at [baselib](./baselib.md) for info.

Even after there's just general bug fixes and parser upgrades.

```

if "Hello" == "Hello" {
    println("Hello!");
};

```
<!-- 
Another feature is the new lexer. This fixes issues with the recognition and was easier to use.

`("hello) world")` -> hello

New:

`("hello) world")` -> hello) world -->

<!-- ## Optional Features

You have the option to build the ISys++ project with an experimental feature called module loading.

You can load .so files that use the ISysPP headers.

Example:

```c

#include <iostream>
#include <vector>
#include <isys/ispp_stack.h>

int f_helloworld(std::vector<std::string>arguments) {
    std::cout << "Hello, world!" << std::endl;
}

/// called when library is loaded
int isp_voke() {
    isys_register_c_function("helloworld", &f_helloworld);
}
```

`g++ helloworld.cpp -shared -fPIC -Wall -o helloworld.so`

ISPP code:

```

stack helloworld.so;

helloworld();

``` -->