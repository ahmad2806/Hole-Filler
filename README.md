**Fill Hole Library:**

Small image processing library that fills holes in an image, the library takes an image,
connectivity object, weight object, and a hole value.

```
1 - Image: the library assumes that the image has a hole pixels with a unique value
from other pixels that also should have a float value between [0-1].

2 - It also takes connectivity objects which describe a role to determine if a certain
pixel is considered a neighbor, (as a default, only 4 and 8 connectivity were added),
but the user can create his connectivity and pass it to the library to work with.

3 - Weight object: this object contains the logic of calculating the value of the hole
pixels (as default the library uses a default weight which calculate it using euclidean
distance between two points), but the user can also create his logic and pass it
to the library.

4 - Hole value: the user pass to the library the hole value in his image, if he didn’t
then the default hole value will be -1.
```
**How the library works:**

it takes an image with the hole, weight object, connectivity object, and a hole value.

```
1 - The library first finds the boundaries based on the connectivity object.
2 - Find the hole based on the hole value.
3 - For each hole pixel, we calculate the value based on the weight function in the
weight object.
4 - Return the result.
```
Time complexity: if we assume the number of boundaries is **m** and the number of holes is **n**
then the time complexity will be is O( **m*n** )

**Command Line Interface**

A new program was created to use the library and it contains three main parts. view,
command, and runner.

```
1 - View: the program view is a CLI, its job is to get input and show output to the user
using the Cout and Cin functions, the user can simply replace this CLI view with any
view he desires, he just has to inherit from the IView class and fill the relative
functions with his code.

2 - Command: this class contains the logic that the program to work with the library
and use it to solve the problem that it should solve.
Meanwhile, the program has only one algorithm, his specification:
fill_hole <img_path> <mask_path> <output_path> <e_value> <z_value> <con_type>
which capable of combining two images (mask and image) into one using the
functions in ImageUtil namespace, and then create a default weight using epsilon
and z. afterward, the command uses the library to fill that hole and save the result in
the path that used provided.

3 - Runner: this piece combines between command and view, it gets the input from
the view, and passes it to the command and vice versa, it also contains a command
storage which has all the commands that were registered to it to work with, and also
connectivity storage which contains all the connectivity that he can work with.
```
Users can add new connectivity and commands to the runner class.

