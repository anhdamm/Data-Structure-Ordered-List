#include <iostream>
#include "OrderedList.h"
using namespace std;

/* insert
 Pre: List is not full
 Post: Inserts newDataItem in its appropiate position within a list.
 */
template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::insert(const DataType &newDataItem) throw (logic_error)
{
    if(isFull())
    {
        throw logic_error ("List is full.");
    }
    
    int i;
    if(binarySearch(newDataItem.getKey(), i))
    {
        dataItems[i] = newDataItem;
        cursor = i;
    }
    else
    {
        List<DataType>::insert(newDataItem);
    }
}


/* replace
 Pre: List is not empty.
 Post: Replaces the data item marked by the cursor with the newDataItem.
 */
template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::replace ( const DataType &newDataItem ) throw ( logic_error )
{
    if(isEmpty())
    {
        throw logic_error ("List is empty. Please add elements to the list.");
    }
    dataItems[cursor] = newDataItem;
}



/* retrieve
 Pre: none
 Post: Searches a list for the data item with key searchKey.
 */
template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType &searchDataItem )
{
    int i;
    if(binarySearch(searchKey,i))
       {
           cursor = i;
           searchDataItem = dataItems[i];
           return true;
       }
       return false;
}

// Binary search routine. Searches a list for the data item with
// key searchKey. If the data item is found, then returns true with
// index returning the array index of the entry containing searchKey.
// Otherwise, returns false with index returning the array index of the
// entry containing the largest key that is smaller than searchKey
// (or -1 if there is no such key).

template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::binarySearch ( KeyType searchKey, int &index )

{
    int low  = 0,           // Low index of current search range
    high = size - 1;    // High index of current search range
    bool result;            // Result returned
    
    while ( low <= high )
    {
        index = ( low + high ) / 2;               // Compute midpoint
        if ( searchKey < dataItems[index].getKey() )
            high = index - 1;                      // Search lower half
        else if ( searchKey > dataItems[index].getKey() )
            low = index + 1;                       // Search upper half
        else
            break;                                 // searchKey found
    }
    
    if ( low <= high )
        result = true;       // searchKey found
    else
    {
        index = high;        // searchKey not found, adjust index
        result = false;
    }
    
    return result;
}





template < typename DataType, typename KeyType >
void OrderedList<DataType,KeyType>:: showStructure () const

// Outputs the keys of the data items in a list. If the list is
// empty, outputs "Empty list". This operation is intended for
// testing and debugging purposes only.

{
    if ( size == 0 )
        cout << "Empty list" << endl;
    else
    {
        cout << "size = " << size
        <<  "   cursor = " << cursor << endl;
        for ( int j = 0 ; j < maxSize ; ++j )
            cout << j << "\t";
        cout << endl;
        for ( int j = 0 ; j < size ; ++j ) {
            if( j == cursor ) {
                cout << "[" << dataItems[j].getKey() << "]\t";
            } else {
                cout << dataItems[j].getKey() << "\t";
            }
        }
        cout << endl;
    }
}

       
       
//Programming Exercise 3

/*
 */
template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::isSubset ( const OrderedList<DataType,KeyType> &other )
{
    int i = 0;
    int j = 0;
    while((i < size) && (j < other.size))
    {
        if(dataItems[i].getKey() < other.dataItems[j].getKey())
        {
            i++;
        }
        else if(dataItems[i].getKey() == other.dataItems[j].getKey())
        {
            i++;
            j++;
        }
        else
        {
            return false;
        }
    }
    if( j == other.size)
    {
        return true;
    }
    else
    {
        return false;
    }
}








