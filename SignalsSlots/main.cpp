

#include <Wt/WObject>
#include <Wt/WSignal>
#include <iostream>




using namespace std; 
using namespace Wt;



class MyWidget : public WObject{
    public:
        Signal<> clicked;
        Signal<int> enterPressed;
};


class MySlots : public WObject{
    public:
    void buttonClicked(void){
        cout << "Buton clicked" <<endl;
    }

    void buttonPressed(int count){
        cout << "Buton clicked" <<count <<endl;
    }
};


class MyData : public WObject{
    public:
        Signal<int> value;
};


class MyGetter : public WObject{
    public:
    int receivedValue = 0;

    void dataSet(int val){
        receivedValue = val; 
        cout << "Data is set to" << receivedValue << endl;
    }
};

int main (int argc, char * argv[]){
    MyWidget *myW = new MyWidget();
    MySlots *s = new MySlots();

    myW->clicked.connect(boost::bind(&MySlots::buttonClicked, s));

    myW->enterPressed.connect(boost::bind(&MySlots::buttonPressed,s, _1));

    myW->clicked.emit();
    myW->enterPressed(3);
    
//////////////////////////////
    MyData *myD = new MyData();
    MyGetter *myG = new MyGetter();

    myD->value.connect(boost::bind(&MyGetter::dataSet, myG, _1));

    myD->value.emit(5);


    cout << "My received value: "<< myG->receivedValue<<endl;
    return 1;
}
