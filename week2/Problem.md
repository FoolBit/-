## 001:Apple Tree

- [查看](http://dapractise.openjudge.cn/2019hw2/001/)

- 描述

  There is an apple tree outside of kaka's house. Every autumn, a lot of apples will grow in the tree. Kaka likes apple very much, so he has been carefully nurturing the big apple tree.The tree has *N*forks which are connected by branches. Kaka numbers the forks by 1 to *N*and the root is always numbered by 1. Apples will grow on the forks and two apple won't grow on the same fork. kaka wants to know how many apples are there in a sub-tree, for his study of the produce ability of the apple tree.The trouble is that a new apple may grow on an empty fork some time and kaka may pick an apple from the tree for his dessert. Can you help kaka?![img](http://media.openjudge.cn/images/g3523/3321_1.gif)

- 输入

  The first line contains an integer *N* (*N* ≤ 100,000) , which is the number of the forks in the tree. The following *N* - 1 lines each contain two integers *u* and *v*, which means fork *u* and fork *v* are connected by a branch. The next line contains an integer *M* (*M* ≤ 100,000). The following *M* lines each contain a message which is either "**C x**" which means the existence of the apple on fork *x* has been changed. i.e. if there is an apple on the fork, then Kaka pick it; otherwise a new apple has grown on the empty fork. or "**Q x**" which means an inquiry for the number of apples in the sub-tree above the fork *x*, including the apple (if exists) on the fork x Note the tree is full of apples at the beginning

- 输出

  For every inquiry, output the correspond answer per line.

- 样例输入

  `3 1 2 1 3 3 Q 1 C 2 Q 1`

- 样例输出

  `3 2`



## 002:Mobile phones

- [查看](http://dapractise.openjudge.cn/2019hw2/002/)

- 描述

  Suppose that the fourth generation mobile phone base stations in the Tampere area operate as follows. The area is divided into squares. The squares form an S * S matrix with the rows and columns numbered from 0 to S-1. Each square contains a base station. The number of active mobile phones inside a square can change because a phone is moved from a square to another or a phone is switched on or off. At times, each base station reports the change in the number of active phones to the main base station along with the row and the column of the matrix.  Write a program, which receives these reports and answers queries about the current total number of active mobile phones in any rectangle-shaped area.

- 输入

  The input is read from standard input as integers and the answers to the queries are written to standard output as integers. The input is encoded as follows. Each input comes on a separate line, and consists of one instruction integer and a number of parameter integers according to the following table. ![img](http://media.openjudge.cn/images/g197/1195_1.jpg) The values will always be in range, so there is no need to check them. In particular, if A is negative, it can be assumed that it will not reduce the square value below zero. The indexing starts at 0, e.g. for a table of size 4 * 4, we have 0 <= X <= 3 and 0 <= Y <= 3.  Table size: 1 * 1 <= S * S <= 1024 * 1024 Cell value V at any time: 0 <= V <= 32767 Update amount: -32768 <= A <= 32767 No of instructions in input: 3 <= U <= 60002 Maximum number of phones in the whole table: M= 2^30

- 输出

  Your program should not answer anything to lines with an instruction other than 2. If the instruction is 2, then your program is expected to answer the query by writing the answer as a single line containing a single integer to standard output.

- 样例输入

  `0 4 1 1 2 3 2 0 0 2 2  1 1 1 2 1 1 2 -1 2 1 1 2 3  3 `

- 样例输出

  `3 4`

- 来源

  IOI 2001





## 003:不好做的最长上升子序列

- [查看](http://dapractise.openjudge.cn/2019hw2/003/)

- 描述

  一个数的序列*bi*，当*b1* < *b2* < ... < *bS*的时候，我们称这个序列是上升的。对于给定的一个序列(*a1*, *a2*, ..., *aN*)，我们可以得到一些上升的子序列(*ai1*, *ai2*, ..., *aiK*)，这里1 <= *i1* < *i2* < ... < *iK* <= N。比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8).  你的任务，就是对于给定的序列，求出最长上升子序列的长度。 

- 输入

  输入的第一行是序列的长度N (1 <= N <= 300000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到100000000之间。

- 输出

  最长上升子序列的长度。

- 样例输入

  `7 1 7 3 5 9 4 8`

- 样例输出

  `4`