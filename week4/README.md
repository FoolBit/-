## 001:Mayor's posters

- [查看](http://dapractise.openjudge.cn/2019hw4/001/)

- 描述

  The citizens of Bytetown, AB, could not stand that the candidates in the mayoral election campaign have been placing their electoral posters at all places at their whim. The city council has finally decided to build an electoral wall for placing the posters and introduce the following rules:  Every candidate can place exactly one poster on the wall.  All posters are of the same height equal to the height of the wall; the width of a poster can be any integer number of bytes (byte is the unit of length in Bytetown).  The wall is divided into segments and the width of each segment is one byte.  Each poster must completely cover a contiguous number of wall segments. They have built a wall 10000000 bytes long (such that there is enough place for all candidates). When the electoral campaign was restarted, the candidates were placing their posters on the wall and their posters differed widely in width. Moreover, the candidates started placing their posters on wall segments already occupied by other posters. Everyone in Bytetown was curious whose posters will be visible (entirely or in part) on the last day before elections.  Your task is to find the number of visible posters when all the posters are placed given the information about posters' size, their place and order of placement on the electoral wall.  

- 输入

  The first line of input contains a number c giving the number of cases that follow. The first line of data for a single case contains number 1 <= n <= 10000. The subsequent n lines describe the posters in the order in which they were placed. The i-th line among the n lines contains two integer numbers li and ri which are the number of the wall segment occupied by the left end and the right end of the i-th poster, respectively. We know that for each 1 <= i <= n, 1 <= li <= ri <= 10000000. After the i-th poster is placed, it entirely covers all wall segments numbered li, li+1 ,... , ri.

- 输出

  For each input data set print the number of visible posters after all the posters are placed.   The picture below illustrates the case of the sample input. ![img](http://media.openjudge.cn/images/2528_1.jpg)

- 样例输入

  `1 5 1 4 2 6 8 10 3 4 7 10 `

- 样例输出

  `4 `

- 来源

  Alberta Collegiate Programming Contest 2003.10.18

- Hint：

  这题我写错了 但是他过了

  神奇



## 02:K-th Number

- [查看](http://dapractise.openjudge.cn/2019hw4/002/)

- 描述

  You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.  That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i...j] segment, if this segment was sorted?"  For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2...5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.

- 输入

  The first line of the input file contains n --- the size of the array, and m --- the number of questions to answer (1 <= n <= 100 000, 1 <= m <= 5 000).  The second line contains n different integer numbers not exceeding 109 by their absolute values --- the array for which the answers should be given.  The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 <= i <= j <= n, 1 <= k <= j - i + 1) and represents the question Q(i, j, k).

- 输出

  For each question output the answer to it --- the k-th number in sorted a[i...j] segment.

- 样例输入

  `7 3 1 5 2 6 3 7 4 2 5 3 4 4 1 1 7 3`

- 样例输出

  `5 6 3`

- 提示

  This problem has huge input,so please use c-style input(scanf,printf),or you may got time limit exceed.

- 来源

  Northeastern Europe 2004, Northern Subregion





## 003:Picture

- [查看](http://dapractise.openjudge.cn/2019hw4/003/)
- [提交](http://dapractise.openjudge.cn/2019hw4/003/submit/)
- [统计](http://dapractise.openjudge.cn/2019hw4/003/statistics/)
- [提问](http://dapractise.openjudge.cn/2019hw4/clarify/003/)

- 总时间限制: 

  2000ms

- 内存限制: 

  65536kB

- 描述

  A number of rectangular posters, photographs and other pictures of the same shape are pasted on a wall. Their sides are all vertical or horizontal. Each rectangle can be partially or totally covered by the others. The length of the boundary of the union of all rectangles is called the perimeter.  Write a program to calculate the perimeter. An example with 7 rectangles is shown in Figure 1. ![img](http://media.openjudge.cn/images/g179/1177_1.jpg) The corresponding boundary is the whole set of line segments drawn in Figure 2. ![img](http://media.openjudge.cn/images/g179/1177_2.jpg) The vertices of all rectangles have integer coordinates.

- 输入

  Your program is to read from standard input. The first line contains the number of rectangles pasted on the wall. In each of the subsequent lines, one can find the integer coordinates of the lower left vertex and the upper right vertex of each rectangle. The values of those coordinates are given as ordered pairs consisting of an x-coordinate followed by a y-coordinate.  0 <= number of rectangles < 5000 All coordinates are in the range [-10000,10000] and any existing rectangle has a positive area.

- 输出

  Your program is to write to standard output. The output must contain a single line with a non-negative integer which corresponds to the perimeter for the input rectangles.

- 样例输入

  `7 -15 0 5 10 -5 8 20 25 15 -4 24 14 0 -6 16 4 2 15 10 22 30 10 36 20 34 0 40 16`

- 样例输出

  `228`

- 来源

  IOI 1998

- Hint

  这题的离散化是对的！抄到了好写的方法！