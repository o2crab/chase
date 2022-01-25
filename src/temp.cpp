#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <sstream>
using namespace std;


// ---------------------------------------------------------
class Point
{
    public:
        template<class InputIter>
        Point(InputIter first, InputIter last);
        Point(initializer_list<int> il);
        string pos();
        template<class InputIter>
        void move(InputIter first, InputIter last);
        void move(initializer_list<int> il);
    private:
        vector<int> pos_;
        int dim_; // dimention
};

template<class InputIter>
Point::Point(InputIter first, InputIter last)
    : pos_(first, last), dim_(pos_.size())
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
    sout << ')';

    return sout.str();
}

template<class InputIter>
void Point::move(InputIter first, InputIter last)
{
    InputIter itr = first;
    for (int i=0; i<dim_; ++i)
    {
        if (itr == last)
            break;
        pos_[i] += *itr;
        ++itr;
    }
}

void Point::move(initializer_list<int> il)
{
    move(il.begin(), il.end());
}

// ---------------------------------------------------------


int main()
{
    vector<int> v {1,2,3,4};
    Point target(v.begin(),v.end()), player {0,0,3,5};

    cout << setw(7) << "target" << ": " << target.pos() << '\n';
    target.move({1,0,0,0});
    cout << setw(7) << "target" << ": " << target.pos() << '\n';
    cout << '\n';

    cout << setw(7) << "player" << ": " << player.pos() << '\n';
    player.move({1,1,0,-1});
    cout << setw(7) << "player" << ": " << player.pos() << '\n';
    player.move({1,1,0,0});
    cout << setw(7) << "player" << ": " << player.pos() << '\n';

    return 0;
}

