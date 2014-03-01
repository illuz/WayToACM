lower_bound,upper_bound,binary_search
==

所需头文件：`#include <algorithm>`

### lower_bound函数

http://www.cplusplus.com/reference/algorithm/lower_bound/

返回[first,last)中指向第一个不小于比较元素val的迭代器(iterator)。（注意是不小于，这里是可以等于的）
可以理解为lower_bound是为了查找第一个这个元素（可能）存在的位置。

lower_bound函数有两个版本，一个是没带比较函数参数，通过<来进行比较，版本二是带了比较函数参数的。元素必须是已排完序的或者可以和val区分开的。（后面会附上源码分析）
lower_bound都返回“假设这样的元素存在时应该出现的位置”或说“可安插的位置”，**如果寻找的val不存在，那么返回值将是last！记住，last指向最后一个元素的下一个位置**

#### 使用：
对于数组：用`pos = lower_bound(num, num + 10, 12) - num`，pos为数组中下标。
对于有序容器，如vector, map, set，list，用`pos = lower_bound(vec.begin(), vec.end(), 12) - vec.begin()`返回下标或直接`ret_it = lower_bound(m.begin(), m.end(), 12)`返回迭代器。（注意：1.需要有序，2.可能需要重载比较函数并带入参数，或者直接重载<运算符）


### upper_bound函数

http://www.cplusplus.com/reference/algorithm/upper_bound/

返回[first,last)中指向第一个大于比较元素val的迭代器(iterator)。（注意是大于的，这里和lower_bound不一样是不可以等于的）
可以理解为upper_bound函数是为了查找这个元素的下一个位置。

upper_bound函数跟lower_bound函数的源码就比较语句不一样，其他都差不多，所以特性和使用都和lower_bound差不多，可以参照lower_bound。
不过如果一个区间最大的元素和要比较的元素一样大，lower_bound会返回最大的那个数的迭代器，而upper_bound则返回last迭代器。

### binary_search函数

http://www.cplusplus.com/reference/algorithm/binary_search/

判断[first,last)中有没有与val相同的元素。返回值为bool型。
函数其实是调用了lower_bound，如果元素不存在，那么lower_bound得到的的是last或大于val的迭代器。（源码见下面）


#### (仅给出版本一没带比较函数参数）源码：
```
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);     // distance函数求出范围
  while (count>0)                   // 二分开始
  {
    it = first;
    step=count/2;                   // 需要向前迭代一半范围
    advance (it,step);              // advance函数让it迭代器向前迭代step步
    if (*it<val) {                  // or: if (comp(*it,val)), for version (2) （版本2的比较是有comp比较函数参数的）
      first=++it;                   // 如果在后半部分，就移动first迭代器到中间位置，并把范围缩小
      count-=step+1;
    }
    else count=step;                // 如果在前半部分，仅缩小范围即可
  }
  return first;
}
```
#### binary_search源码
```
template <class ForwardIterator, class T>
  bool binary_search (ForwardIterator first, ForwardIterator last, const T& val)
{
  first = std::lower_bound(first,last,val);
  return (first!=last && !(val<*first));
}
```

简单实例：
```
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::binary_search, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::sort(myints, myints + 8);
  // 10, 10, 10, 20, 20, 20, 30, 30

  int low, up;
  // find 20
  low = std::lower_bound (myints, myints + 8, 20) - myints;
  up = std::upper_bound (myints, myints + 8, 20) - myints;

  std::cout << "20's lower_bound at position " << low << '\n';	// 3
  std::cout << "20's upper_bound at position " << up << '\n';	// 6

  // find 30
  low = std::lower_bound (myints, myints + 8, 30) - myints;
  up = std::upper_bound (myints, myints + 8, 30) - myints;

  std::cout << "30's lower_bound at position " << low << '\n';	// 6
  std::cout << "30's upper_bound at position " << up << '\n';	// 8 注意这里返回的下标

  // binary_search
  std::cout << "Find 20? " << std::binary_search(myints, myints + 8, 20) << '\n';     // 1
  std::cout << "Find 21? " << std::binary_search(myints, myints + 8, 21) << '\n';     // 0
  return 0;
}

```

更详细的源码分析见sicofield的[STL中的二分查找——lower_bound 、upper_bound 、binary_search](http://blog.csdn.net/sicofield/article/details/8740141)
