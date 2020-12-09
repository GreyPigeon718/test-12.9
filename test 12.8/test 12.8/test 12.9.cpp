//#include <stdio.h>
//int main()
//{
//    int i, a[10];
//    for (i = 9; i >= 0; i--)  a[i] = 10 - i;
//    printf("%d%d%d", a[2], a[5], a[8]);
//    return 0;
//}
//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//    virtual void print()
//    {
//        cout << "A::print()" << "\n";
//    }
//};
//
//class B : public A
//{
//public: virtual void print()
//{
//    cout << "B::print()" << "\n";
//}
//};
//
//class C : public A
//{
//public: virtual void print()
//{
//    cout << "C::print()" << "\n";
//}
//};
//
//void print(A a)
//{
//    a.print();
//}
//
//int main()
//{
//    A a, * aa, * ab, * ac;
//    B b;
//    C c;
//    aa = &a;
//    ab = &b;
//    ac = &c;
//    a.print();
//    b.print();
//    c.print();
//    aa->print();
//    ab->print();
//    ac->print();
//    print(a);
//    print(b);
//    print(c);
//}
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//
//    string s;
//    while (getline(cin, s))
//    {
//        //string ret = GetRet(s);
//        vector<string> v;
//        int i = 0;
//        while (i < s.size())
//        {
//            int begin = i;
//            if (s[i] == '\"')//有"
//            {
//                i++;
//                while (i < s.size() && s[i] != '\"')
//                {
//                    i++;
//                }
//                //s[begin]=='\"'
//                string tmp = s.substr(begin, i - begin + 1);
//                v.push_back(tmp);
//                i++;
//            }
//            begin = i;
//            while (i < s.size() && s[i] != ' ')
//            {
//                i++;
//            }
//            //s[i]==' '
//            if (i < s.size())
//            {
//                string tmp = s.substr(begin, i - begin);
//                v.push_back(tmp);
//                i++;
//            }
//            else
//            {
//                string tmp = s.substr(begin);
//                v.push_back(tmp);
//            }
//        }
//        cout << v.size() << endl;
//        for (int i = 0; i < v.size(); i++)
//        {
//            cout << v[i] << endl;
//        }
//    }
//    return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
//int main() 
//{
//    string str;
//    while (getline(cin, str)) 
//    {
//        int count = 0;
//        //首先计算参数数量
//        for (int i = 0; i < str.size(); ++i) 
//        {
//            if (str[i] == ' ') 
//            {
//                ++count;
//            }
//            //如果是双引号，向后遍历，直到下一个双引号结束
//            if (str[i] == '"') 
//            {
//                do {
//                    ++i;
//                } while (str[i] == '"');
//            }
//        }
//        //以空格计算个数，空格数量比参数个数少1
//        cout << count + 1 << endl;
//        //用flag表示是否包含双引号，1表示有双引号
//        //双引号中的空格要打印出来
//        //用异或改变flag的值，两个双引号可以使flag复原
//        int flag = 0;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            //有双引号，flag通过异或变为1，下一次再遇到双引号，flag置为0
//            if (str[i] == '"')
//            {
//                flag ^= 1;
//            }
//            //双引号和普通空格不打印
//            if (str[i] != ' ' && str[i] != '"')
//            {
//                cout << str[i];
//            }
//            //双引号中的空格要打印
//            if (str[i] == ' ' && flag == 1) 
//            {
//                cout << str[i];
//            }
//            //遇到双引号之外的空格就换行
//            if (str[i] == ' ' && flag == 0)
//            {
//                cout << endl;
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//计算该数的公约数
void Divisor(int n, vector<int>& buff)
{
    for (size_t i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            buff.push_back(i);
            //如果这个数不是平方数，那么也将另一个数加入到列表中
            if (n / i != i)
                buff.push_back(n / i);
        }
    }
}

int Jump_Slab(int n, int m)
{
    //存放从起始位置到每个位置所需要的步数
    vector<int> Slab(m + 1, 0);
    //从n位置走到n位置只需要1步，所以初始化为1
    Slab[n] = 1;

    for (size_t i = n; i < m; ++i)
    {
        //如果这个位置为0，说明不能走到这个位置，跳出此次循环
        if (0 == Slab[i])
            continue;
        //存放i位置可以走的步数
        vector<int> Jump;
        Divisor(i, Jump);
        //Slab[Jump[j] + i]是当前可以走到的位置
        for (size_t j = 0; j < Jump.size(); ++j)
        {
            //由位置i出发能到达的点为 stepNum[divNum[j]+i]
            if (Jump[j] + i <= m && Slab[Jump[j] + i] != 0)
                //如果到达了这次可以走到的地方没有超过M点，
                //并且这个位置已经来过，要取从起点到这个位置的步数和现在要更新的步数最少的
                Slab[Jump[j] + i] = min(Slab[Jump[j] + i], Slab[i] + 1);
            else if (Jump[j] + i <= m)
                ///将可以走的位置更新，由于是在i位置开始走的下一步，
                //所以走到这里的步数在i位置的基础上加一
                Slab[Jump[j] + i] = Slab[i] + 1;
        }
    }

    if (0 == Slab[m])
        return -1;
    else
        return Slab[m] -= 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << Jump_Slab(n, m) << endl;
    return 0;
}
