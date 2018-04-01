----
#### 1.编码
* 题目：假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index. 
* 我的思路：参考别人的思路吧。
* [代码](https://github.com/Tramac/NewCoder/blob/master/Tencent2017/Encoder.cpp)
#### 2.游戏任务标记
* 题目：游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
* 注意：移位操作，与操作，或操作
* [代码](https://github.com/Tramac/NewCoder/blob/master/Tencent2017/GameTaskFlag.cpp)
#### 3.素数对
* 题目：给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)） 
* 我的思路：如果i和（n-i）都是质数，那么就存在一个质数对。我判断是否为质数的方法是最笨的方法。
* [我的代码](https://github.com/Tramac/NewCoder/blob/master/Tencent2017/PrimerNumber.cpp)
