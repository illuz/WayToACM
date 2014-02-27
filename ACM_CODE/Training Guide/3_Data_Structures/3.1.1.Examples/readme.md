3.1.1.Examples  
==  
  
Root :: AOAPC I: Beginning Algorithm Contests -- Training Guide (Rujia Liu) :: Chapter 3. Data Structures :: Fundamental Data Structures :: Examples  
  
下面题目地址：http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497  
  
所有代码地址：https://github.com/illuz/WayToACM/tree/master/ACM_CODE/Training%20Guide/3_Data_Structures/3.1.1.Examples  
  
---  
  
  
### **11995 - I Can Guess the Data Structure!**  
  
**[题目地址](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3146)**  
  
  
**题意**：  
一个容器，可能是stack,queue,priority queue输入n对数，每对数的第一个数代表操作符，如果是1,第二个数就是增加元素，第二个就是移除元素。问可能是上面容器。  
  
**分析**：  
很容易，以前模拟过，这次直接用STL模拟，当做练手。  
  
  
---  
  
  
  
  
---  
  
### **11991 - Easy Problem from Rujia Liu?**  
  
**[题目地址](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3142)**  
  
  
**题意**：  
给出一个包含n个数的数组，每次询问第k个v的下标。  
  
**分析**：  
用STL里面的`map<int, vector<int> >`模拟即可。  
  
  
  
  
---  
  
### **1203 - Argus**  
  
**[题目地址](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3644)**  
  
  
**题意**：  
一个系统支持:Register Q_num Period命令，这样就产生一个触发器，每Period秒会发生一个事件Q_num。  
输入多个触发器，然后问前n个事件的Q_num。如果事件同时发生，就先进行Q_num小的事件。  
  
**分析**：  
这其实跟多路归并问题一样。只要用优先队列处理下就行了。  
  
  
  
---  
  
### **11997 - K Smallest Sums**  
  
**[题目地址](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3148)**  
  
  
**题意**：  
有k个整数数组，各包含k个元素，在每个数组中取一个元素加起来，求出这些和中最小的k个。  
  
**分析**：  
<s>如果是求最小的那个和，直接把每个数组排序，取最小的那个就行了，但是需要取多个，所以需要思考一下。我们已经知道最小的那个了，那第二小的那个就是最小的那些中换掉一个元素，所以只要找到那个元素即可，后面前k小都能这样求出来。  
问题是如何找出这个数，因为我们是要求接下去小数，所以只要知道所取的数和同数组中下一个数（排过序）的差最小就行了。  
由于数据范围是750,如果每次找那个符合的数，复杂度是O(n^3)，4e8的复杂度是无法接受的。所以我们可以用优先队列维护那个最小的就行了。  
代码·WA。。  
</s>  
  
事实证明刚开始的思路是错的...orz  
那样的话每次只能判断在最小的基础上换掉哪个数能得到第二小...  
没办法，不能偷懒，只能好好研究大白的算法了。  
  
我发现打败的方法和我的差不多。  
它先考虑只有2组k个数的情况，可以用多路归并的思路去解，然后从2组推到k组，只要两两归并就行了，太神了....  
  
**总结**：  
这又是一道从小问题推大问题的题目....  
  
  
---  
  
### **1160 - X-Plosives**  
  
**[题目地址](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3601)**  
  
  
**题意**：  
有多个化合物，每个化合物都由两种元素组成，每次拿一个化合物，如果和车上的化合物满足了（有k种化合物包含k种元素）这一条件就会爆炸，就要拒绝装箱。  
问一路装下来有几个没装上去的。  
  
**分析**：  
一眼看过去差点理解错题意了...k是当前车上的所有化合物种类数...  
原来是只要满足有k个就不行了。  
发现化合物由两种元素组成，那么考虑爆炸的情况：  
如果k=2，那么化合物可能为AB，BA；  
k=3,AB，BC，CA；  
k=4,AB，BC，CD，DA；  
.....  
所以把每个化合物的两种元素连成一条线，只要在图中出现了环，那这个环边上的元素便会构成爆炸物。用并查集就可以了。  
  
  
  
  
---  
  
### **1329 - Corporative Network**  
  
**[题目地址](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=4075)**  
  
  
**题意**：  
有n个节点，初始时每个节点的父节点都不存在。每次执行有两种格式：  
> I u v: 把节点u的父亲设置为v，距离为|u-v|mod1000，保证此时u没有父节点;  
E u:询问u到根节点的距离。  
  
**分析**：  
很明显的并查集既然保证u没有父亲，那么不用判断直接f[u] = v就能建出一棵树了。  
但是寻找距离的时候最坏的情况是O(n^2)，会超时，很明显，需要另开一个数组记录距离，在查找路径的时候，进行路径压缩并维护。  
  
  
---  
