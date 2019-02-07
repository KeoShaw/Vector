#include "Vector.h"
#include <iostream>
#include <string>

using namespace std;

void CopyConstructorTest(){
    Vector<string> vec1;
    vec1.Insert(0, "test");

    Vector<string> vec2(vec1);

    cout << vec2.Get(0) << " "; //Expect "test" to be printed
    vec2.Get(0) = "no";

    cout << vec1.Get(0) << " " << vec2.Get(0) << endl; //Expect "test no" to be printed. Checks to make sure array duplication has occurred and modification of vec2 elements doesn't affect vec1 elements
}

void ComplexPrimitiveTest(){
    Vector<string> stringVec;
    stringVec.Insert(0, "test");
    string test = "yes";
    stringVec.Insert(1, test);

    cout << stringVec.Get(0) << " " << stringVec.Get(1) << " "; //Should display "test yes"

    Vector<int> intVec;
    intVec.Insert(0, 100);
    int test2 = 200;
    intVec.Insert(1, test2);

    cout << intVec.Get(0) << " " << intVec.Get(1) << endl; //Should display "100 200"
}

void AssignmentOperatorTest(){
    Vector<string> vec1;
    vec1.Insert(0,"test");

    Vector<string> vec2;
    vec2 = vec1;

    cout << vec2.Get(0) << " "; //Expect to print "test "

    vec2.Get(0) = "yo";

    cout << vec1.Get(0) << endl; //Expect "test" to be printed. Checks to ensure deep copying


}

void InsertionTest(){
    Vector<string> vec;
    vec.Insert(0, "yes"); vec.Insert(1,"no"); vec.Insert(2,"three");
    vec.Insert(1, "inserted");

    for(int i=0;i<4;i++){
        cout << vec.Get(i) << " "; //Expect "inserted" to be printed second
    }
    cout << endl;
}

void AddingTest(){
    Vector<string> vec;
    vec.Insert(0, "first");
    vec.Insert(1, "second");
    vec.Insert(300, "third");

    cout << vec.Get(0) << " " << vec.Get(1) << " " << vec.Get(2) << " " << vec.Get(3) <<  endl; //Expect "first second third third"
}

void GetTest(){
    Vector<string> vec;
    vec.Insert(0,"test");

    cout << vec.Get(0) << " " << vec.Get(1) << " " << vec.Get(100) << endl; //Expect "test" to be printed three times
}

void GetSizeTest(){
    Vector<int> vec;

    cout << vec.GetSize() << " "; //expect 0

    vec.Insert(0,10);

    cout << vec.GetSize() << " "; //expect 1

    vec.Insert(1,11);

    cout << vec.GetSize() << " "; //expect 2

    for(int i=2;i<10;i++){
        vec.Insert(i,i);
    }

    cout << vec.GetSize() << endl; //expect 10
}

void MemExpTest(){
    Vector<int> vec;

    for(int i = 0;i<5000;i++){
        vec.Insert(i,i);
    }
    for(int i = 0;i<5000;i++){
        cout << vec.Get(i) << endl; //Expect 0 to 4999 to be printed out
    }
    cout << vec.GetSize() << endl; //Expect 5000 to be printed out
}

void VectorResetTest(){
    Vector<string> vec;
    vec.Insert(0, "hello");
    vec.Insert(1, "no");
    for(int i = 0; i < 20; i++){
        vec.Insert(21, "test");
    }

    vec.Reset();
    cout << vec.GetSize() << endl; //Should print 0
}

int main(){
    ComplexPrimitiveTest(); //Tests if Vector can be used for primitive types and complex types.
    CopyConstructorTest(); //Tests the copy constructor
    AssignmentOperatorTest(); //tests assignment operator
    InsertionTest(); //Tests inserting an element in the middle of an array
    AddingTest(); //Tests adding to the end of the array rather than inserting
    GetTest(); //Tests get method
    GetSizeTest(); //Tests the GetSize() method
    MemExpTest(); //Tests to make sure memory expands properly
    VectorResetTest();
}
