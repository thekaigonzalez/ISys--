# ISys++

<!-- ## WARNING - Do not venture further!

This is the experimental branch, everything here is not final.

For stable commits and releases, use the `master` branch. 

Thanks! -->

ISys++ is a C++ rewrite of the ISys programming language. ISys++ runs on Android, iOS, PC (Windows), Linux, macOS, and other OSes. It's a fast programming language which supports operations similar to Python 3.9, with the speed of C. It is very lightweight, has no memory, no garbage collection, is relatively easy to program, but is designed to do things with ease, such as reading, writing, opening, closing, hiding, etc., and has been written as a pure C-API language (CPython).

ISys++ is based on another Cython programming principle, which is the use of a pointer, i.e. the operation a parameter to a function has to perform to retrieve the value of another parameter in order to return the parameter it points to. This is similar in spirit to the Unix programming philosophy.

```

kgonzo@me:~/ISys++$ ./isyspp
>>>var hello = ""

>>>var hellostring = append(hello, "Hi!")

>>>printf(hellostring, "\n")

Hi!

>>>

```


You can find the manual for ISys [here](https://thekaigonzalez.github.io/ISysPP)