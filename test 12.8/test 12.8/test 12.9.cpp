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
//            if (s[i] == '\"')//��"
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
//        //���ȼ����������
//        for (int i = 0; i < str.size(); ++i) 
//        {
//            if (str[i] == ' ') 
//            {
//                ++count;
//            }
//            //�����˫���ţ���������ֱ����һ��˫���Ž���
//            if (str[i] == '"') 
//            {
//                do {
//                    ++i;
//                } while (str[i] == '"');
//            }
//        }
//        //�Կո����������ո������Ȳ���������1
//        cout << count + 1 << endl;
//        //��flag��ʾ�Ƿ����˫���ţ�1��ʾ��˫����
//        //˫�����еĿո�Ҫ��ӡ����
//        //�����ı�flag��ֵ������˫���ſ���ʹflag��ԭ
//        int flag = 0;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            //��˫���ţ�flagͨ������Ϊ1����һ��������˫���ţ�flag��Ϊ0
//            if (str[i] == '"')
//            {
//                flag ^= 1;
//            }
//            //˫���ź���ͨ�ո񲻴�ӡ
//            if (str[i] != ' ' && str[i] != '"')
//            {
//                cout << str[i];
//            }
//            //˫�����еĿո�Ҫ��ӡ
//            if (str[i] == ' ' && flag == 1) 
//            {
//                cout << str[i];
//            }
//            //����˫����֮��Ŀո�ͻ���
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

//��������Ĺ�Լ��
void Divisor(int n, vector<int>& buff)
{
    for (size_t i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            buff.push_back(i);
            //������������ƽ��������ôҲ����һ�������뵽�б���
            if (n / i != i)
                buff.push_back(n / i);
        }
    }
}

int Jump_Slab(int n, int m)
{
    //��Ŵ���ʼλ�õ�ÿ��λ������Ҫ�Ĳ���
    vector<int> Slab(m + 1, 0);
    //��nλ���ߵ�nλ��ֻ��Ҫ1�������Գ�ʼ��Ϊ1
    Slab[n] = 1;

    for (size_t i = n; i < m; ++i)
    {
        //������λ��Ϊ0��˵�������ߵ����λ�ã������˴�ѭ��
        if (0 == Slab[i])
            continue;
        //���iλ�ÿ����ߵĲ���
        vector<int> Jump;
        Divisor(i, Jump);
        //Slab[Jump[j] + i]�ǵ�ǰ�����ߵ���λ��
        for (size_t j = 0; j < Jump.size(); ++j)
        {
            //��λ��i�����ܵ���ĵ�Ϊ stepNum[divNum[j]+i]
            if (Jump[j] + i <= m && Slab[Jump[j] + i] != 0)
                //�����������ο����ߵ��ĵط�û�г���M�㣬
                //�������λ���Ѿ�������Ҫȡ����㵽���λ�õĲ���������Ҫ���µĲ������ٵ�
                Slab[Jump[j] + i] = min(Slab[Jump[j] + i], Slab[i] + 1);
            else if (Jump[j] + i <= m)
                ///�������ߵ�λ�ø��£���������iλ�ÿ�ʼ�ߵ���һ����
                //�����ߵ�����Ĳ�����iλ�õĻ����ϼ�һ
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
