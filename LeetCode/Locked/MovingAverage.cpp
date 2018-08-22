/*
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/
#include <iostream>
#include <queue>

using namespace std;

class MovingAverage{
private:
    queue<int> mq;
    int _size;
    double _sum;

public:
    MovingAverage(int size):_size(size), _sum(0){}

    double next(int value){
        _sum += value;
        mq.push(value);
        int q_size = mq.size();
        if(q_size <= _size)
            return _sum/q_size;
        else{
            _sum -= mq.front();
            mq.pop();
            return _sum/_size;
        }
    }
};

int main(){
    MovingAverage mv(3);
    cout<<mv.next(4)<<endl;
    cout<<mv.next(5)<<endl;
    cout<<mv.next(6)<<endl;
    cout<<mv.next(7)<<endl;
    cout<<mv.next(8)<<endl;

    return 0;
}