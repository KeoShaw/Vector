/** @file Vector.h - Vector class definition
    @author Keo Tom-Shaw
    @date 18/05/2018
    @version 3
*/

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template <class Type>
///Manages a dynamic array with methods for inserting, resizing the array and accessing elements.
class Vector{
public:
    ///Default Constructor
    Vector();

    /** Copy Constructor
        @param vec The Vector object which is to be copied.
    */
    Vector(const Vector<Type> & vec);

    ///Destructor
    ~Vector();

    /** Overloaded assignment operator.
        @param vec Vector object to be copied into the left operand.
        @return A constant reference to the left operand.
    */
    const Vector<Type>& operator =(const Vector<Type> & vec);

    /** Inserts the given Type into the array at position i. Insertion can also mean appending to the array if the given i is equal to or greater than the amount of elements already in the array.
        @post If the parameter i is equal to or greater than GetSize(), type will be added to the end of the array (position GetSize()). Otherwise, type is inserted at i and all elements (including previous i element) above it shuffled up.
        @param i The number of the array position to be accessed, starts at 0 (unsigned).
        @param type Type variable to be inserted into the array.
        @return void
    */
    void Insert(unsigned i, const Type & type);

    /** Gets the Type variable at array position i. Non-constant.
        @pre i will be equal to or less than GetSize() - 1.
        @param i The number of the array position to be accessed (array starts at 0). it will be equal to or less than GetSize() - 1 (unsigned).
        @return A reference to the Type stored in array position i.
    */

    Type& Get(unsigned i);

    /** Returns the used size of the array (not maximum size).
        @return The used size of the array (unsigned).
    */
    unsigned GetSize() const;

    /** Deletes all elements in the Vector and re-initialises it.
        @return void
    */
    void Reset();


private:
    ///Amount of elements stored in the array.
    unsigned size;
    ///Maximum size of array currently.
    unsigned maxSize;
    ///Variable size array.
    Type *array;

    /** Checks if array is full, and allocates memory accordingly (helper method).
        @return void
    */
    void MemoryResize();
};

template <class Type>
Vector<Type>::Vector(){
    size=0;
    maxSize = 10;
    array = new Type[10];
}

template <class Type>
Vector<Type>::Vector(const Vector<Type> & vec){
    size = vec.size;
    maxSize = vec.maxSize;
    array = new Type[maxSize];
    for(unsigned i=0;i<maxSize;i++){
        array[i] = vec.array[i]; //Copies elements into new object.
    }
}

template <class Type>
Vector<Type>::~Vector(){
    delete [] array;
}

template <class Type>
void Vector<Type>::Reset(){
    delete [] array;
    array = new Type[10];
    size = 0;
    maxSize = 10;
}

template <class Type>
const Vector<Type>& Vector<Type>::operator =(const Vector<Type> & vec){
    if(this!=&vec){ //Ensures self copy doesn't occur
        delete [] array; //Deletes left operand's array
        size = vec.size; //Sets sizes according to right operand values
        maxSize = vec.maxSize;
        array = new Type[maxSize];
        for(unsigned i = 0;i<maxSize;i++){
            array[i] = vec.array[i]; //Copies array elements into left operand's new array
        }
    }

    return *this;
}

template <class Type>
Type& Vector<Type>::Get(unsigned i){
    if(i>=size){ //Can't access elements that don't exist.
        return array[size-1];
    }
    return array[i];
}

template <class Type>
void Vector<Type>::Insert(unsigned i, const Type & type){

    if(size==maxSize)
        MemoryResize(); //Creates space if needed.

    if(i>=size){ //Adds element to the end of the array if user has given an index position not residing between pre-extant elements
        array[size] = type;
    }else{
        for(unsigned j = size;j>i;j--){
            array[j] = array[j-1]; //Goes from the end of the array, shuffling elements up by one until it reaches insertion location.
        }
        array[i] = type; //Element inserted into index i
    }
    size++; //Number of elements incremented
}

template <class Type>
unsigned Vector<Type>::GetSize() const{
    return size;
}

template <class Type>
void Vector<Type>::MemoryResize(){

    maxSize = (int) (maxSize * 1.5);
    Type *newArray = new Type[maxSize]; // Increases new array size by 1.5 times previous.

    for(unsigned i = 0;i<size;i++){ //Copies old array into new.
        newArray[i] = array[i];
    }
    delete [] array; //Deletes old array
    array = newArray;
}

#endif // VECTOR_H_INCLUDED
