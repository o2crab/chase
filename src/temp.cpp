#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <sstream>
using namespace std;


class Point
{
    public:
        template<class InputIter>
        Point(InputIter first, InputIter last);
        Point(initializer_list<int> il);
        string pos();
    private:
        vector<int> pos_;
};

template<class InputIter>
Point::Point(InputIter first, InputIter last)
    : pos_(first, last)
{}

Point::Point(initializer_list<int> il)
    : Point(il.begin(), il.end())
{}

string Point::pos()
{
    ostringstream sout;
    sout << '(';
    for (int i=0; i<pos_.size()-1; ++i)
        sout << pos_[i] << ", ";
    sout << pos_[pos_.size()-1];
    sout << ')' << '\n';

    return sout.str();
}


int main()
{
    vector<int> v {1,2,3,4};
    Point target(v.begin(),v.end()), you {0,0,3,1};
    cout << setw(7) << "target" << ": " << target.pos();
    cout << setw(7) << "you" << ": " << you.pos();

    return 0;
}

