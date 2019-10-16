## 001:多模式串字符串匹配模板题

- [查看](http://dapractise.openjudge.cn/2019hw5/001/)

- 描述

  给若干个模式串，以及若干个句子，判断每个句子里是否包含模式串。 句子和模式串都由小写字母组成

- 输入

  第一行是整数n，表示有n个模式串 ( n <= 1000) 接下来n行每行一个模式串。每个模式串长度不超过120 接下来一行是整数m，表示有m个句子 (m <= 1000) 接下来m行，每行一个句子，每个句子长度不超过1000

- 输出

  对每个句子，如果包含某个模式串，则输出 YES, 否则输出 NO

- 样例输入

  `3 abc def gh 2 abcd ak`

- 样例输出

  `YES NO`

- 来源

  Xu Yewen





## 002:Computer Virus on Planet Pandora

- [查看](http://dapractise.openjudge.cn/2019hw5/002/)

- 描述

  Aliens on planet Pandora also write computer programs like us. Their programs only consist of capital letters (‘A’ to ‘Z’) which they learned from the Earth. On planet Pandora, hackers make computer virus, so they also have anti-virus software. Of course they learned virus scanning algorithm from the Earth. Every virus has a pattern string which consists of only capital letters. If a virus’s pattern string is a substring of a program, or the pattern string is a substring of the reverse of that program, they can say the program is infected by that virus. Give you a program and a list of virus pattern strings, please write a program to figure out how many viruses the program is infected by.

- 输入

  There are multiple test cases. The first line in the input is an integer T ( T <= 10) indicating the number of test cases.  For each test case:  The first line is a integer n( 0 < n <= 250) indicating the number of virus pattern strings.  Then n lines follows, each represents a virus pattern string. Every pattern string stands for a virus. It’s guaranteed that those n pattern strings are all different so there are n different viruses. The length of pattern string is no more than 1,000 and a pattern string at least consists of one letter.  The last line of a test case is the program. The program may be described in a compressed format. A compressed program consists of capital letters and “compressors”. A “compressor” is in the following format:  [qx]  q is a number( 0 < q <= 5,000,000)and x is a capital letter. It means q consecutive letter xs in the original uncompressed program. For example, [6K] means ‘KKKKKK’ in the original program. So, if a compressed program is like:  AB[2D]E[7K]G  It actually is ABDDEKKKKKKKG after decompressed to original format. The length of the program is at least 1 and at most 5,100,000, no matter in the compressed format or after it is decompressed to original format.

- 输出

  For each test case, print an integer K in a line meaning that the program is infected by K viruses.

- 样例输入

  ```
  3
  2
  AB
  DCB
  DACB
  3
  ABC
  CDE
  GHI
  ABCCDEFIHG
  4
  ABB
  ACDEE
  BBB
  FEEE
  A[2B]CD[4E]F
  ```

- 样例输出

  ```
  0
  3
  2
  ```

- 提示

  In the second case in the sample input, the reverse of the program is ‘GHIFEDCCBA’, and ‘GHI’ is a substring of the reverse, so the program is infected by virus ‘GHI’.

- Hint

  谁说这是模板我跟谁急

  pattern插入两次时需要考虑AB/BA这种情况，这是两个virus，但是正反插会重复

  直接正反匹配会更快？？Why



## 003:躲不开的病毒

- [查看](http://dapractise.openjudge.cn/2019hw5/003/)

- 描述

  有若干种病毒，每种病毒的特征代码都是一个01串。每个程序也都是一个01串。问是否存在不被病毒感染（不包含任何病毒的特征代码）的无限长的程序。

- 输入

  第一行是整数n，表示有n个病毒 接下来n行，每行是一个由 0,1构成的字符串，表示一个病毒特征代码 所有的病毒的特征代码总长度不超过30000

- 输出

  如果存在无限长的没有被病毒感染的程序，输出 "TAK"，否则输出"NIE"

- 样例输入

  `样例1: 2 10 11 样例2: 2 1 0`

- 样例输出

  `样例1: TAK 样例2: NIE`

- 来源

  test cases by Xu Yewen



## 004:DNA repair

- [查看](http://dapractise.openjudge.cn/2019hw5/004/)

- 描述

  Biologists finally invent techniques of repairing DNA that contains segments causing kinds of inherited diseases. For the sake of simplicity, a DNA is represented as a string containing characters 'A', 'G' , 'C' and 'T'. The repairing techniques are simply to change some characters to eliminate all segments causing diseases. For example, we can repair a DNA "AAGCAG" to "AGGCAC" to eliminate the initial causing disease segments "AAG", "AGC" and "CAG" by changing two characters. Note that the repaired DNA can still contain only characters 'A', 'G', 'C' and 'T'.You are to help the biologists to repair a DNA by changing least number of characters.

- 输入

  The input consists of multiple test cases. Each test case starts with a line containing one integers *N* (1 ≤ *N* ≤ 50), which is the number of DNA segments causing inherited diseases. The following *N* lines gives *N* non-empty strings of length not greater than 20 containing only characters in "AGCT", which are the DNA segments causing inherited disease. The last line of the test case is a non-empty string of length not greater than 1000 containing only characters in "AGCT", which is the DNA to be repaired.The last test case is followed by a line containing one zeros.  

- 输出

  For each test case, print a line containing the test case number( beginning with 1) followed by the number of characters which need to be changed. If it's impossible to repair the given DNA, print -1.

- 样例输入

  ```
  2
  AAA
  AAG
  AAAG    
  2
  A
  TG
  TGAATG
  4
  A
  G
  C
  T
  AGT
  0
  ```

- 样例输出

  ```
  Case 1: 1
  Case 2: 4
  Case 3: -1
  ```