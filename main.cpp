#include <QCoreApplication>
#include<QString>
#include<QVector>
#include<QTextStream>
#include<iostream>

int find(char *образец, char *строка)
{

    for (int i=0;строка[i];++i) {
        for (int j=0;;++j) {
            if (!образец[j]) return i;
            if(строка[i+j]!=образец[j]) break;
        }

    }

    return -1;
}

QVector<size_t> prefix_function(QString s, bool reg=true)
{

    size_t n = s.length();
    if (!reg)
    {
        s=s.toLower();


    }
    QVector<size_t> pi(n);
    pi[0] = 0;

    for (size_t i = 1; i < n; i++)
    {
        size_t j = pi[i - 1];

        while ((j > 0) && (s[i] != s[j]))
            j = pi[j - 1];

        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }

    return pi;

}

QString construct_string(QString& substr,QString& text )
{
    QString str="";
    QTextStream stream(&str);
    stream<<substr<<"@"<<text;
    return str;
}

void KMP(QString& substr,QString& text,bool reg)
{
    size_t n = substr.length();
    QString result = construct_string(substr,text);
    QVector<size_t> res;
    if(reg)
        res = prefix_function(result);
    else
        res = prefix_function(result, false);

    int count = 0;
    for (auto i : res)
        if (i == n)
            ++count;
    std::cout << count << std::endl;
}
int main(int argc, char *argv[])
{
        QString text="KSILofon";
        QString substr ="ksi";
        KMP(substr,text,true);
        KMP(substr,text,false);



    return 0;
}
