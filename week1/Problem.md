## 001:冰阔落 I

- [查看](http://dapractise.openjudge.cn/2019hw1/001/)

- 描述

  老王喜欢喝冰阔落。初始时刻，桌面上有n杯阔落，编号为1到n。老王总想把其中一杯阔落倒到另一杯中，这样他一次性就能喝很多很多阔落，假设杯子的容量是足够大的。有m 次操作，每次操作包含两个整数x与y。若原始编号为x 的阔落与原始编号为y的阔落已经在同一杯，请输出"Yes"；否则，我们将原始编号为y 所在杯子的所有阔落，倒往原始编号为x 所在的杯子，并输出"No"。最后，老王想知道哪些杯子有冰阔落。 

- 输入

  有多组测试数据，少于 5 组。 每组测试数据，第一行两个整数 n, m (n, m<=50000)。接下来 m 行，每行两个整数 x, y (1<=x, y<=n)。

- 输出

  每组测试数据，前 m 行输出 "Yes" 或者 "No"。 第 m+1 行输出一个整数，表示有阔落的杯子数量。 第 m+2 行有若干个整数，从小到大输出这些杯子的编号。

- 样例输入

  `3 2 1 2 2 1 4 2 1 2 4 3 `

- 样例输出

  `No Yes 2 1 3  No No 2 1 4 `



## 002:食物链

- [查看](http://dapractise.openjudge.cn/2019hw1/002/)

- 描述

  动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。 现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。 有人用两种说法对这N个动物所构成的食物链关系进行描述： 第一种说法是"1 X Y"，表示X和Y是同类。 第二种说法是"2 X Y"，表示X吃Y。 此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。

  ​	1）	当前的话与前面的某些真的话冲突，就是假话； 

  ​	2）	当前的话中X或Y比N大，就是假话； 

  ​	3）	当前的话表示X吃X，就是假话。 

  ​	你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。 

- 输入

  第一行是两个整数N和K，以一个空格分隔。 以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。 若D=1，则表示X和Y是同类。 若D=2，则表示X吃Y。

- 输出

  只有一个整数，表示假话的数目。

- 样例输入

  `100 7 1 101 1  2 1 2 2 2 3  2 3 3  1 1 3  2 3 1  1 5 5 `

- 样例输出

  `3`





## 003:A Bug's Life

- [查看](http://dapractise.openjudge.cn/2019hw1/003/)

- 描述

  **Background** Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs. **Problem** Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.

- 输入

  The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.

- 输出

  The output for every scenario is a line containing "Scenario #i:", where i is the number of the scenario starting at 1, followed by one line saying either "No suspicious bugs found!" if the experiment is consistent with his assumption about the bugs' sexual behavior, or "Suspicious bugs found!" if Professor Hopper's assumption is definitely wrong.

- 样例输入

  `2 3 3 1 2 2 3 1 3 4 2 1 2 3 4`

- 样例输出

  `Scenario #1: Suspicious bugs found!  Scenario #2: No suspicious bugs found!`