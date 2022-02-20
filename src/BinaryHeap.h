// CREDITS GO TO MARK WEISS FOR WRITING THE ORIGINAL IMPLEMENTATION
// Work I did: Edit the binary heap to use an array instead of a vector for speed purposes        
        #ifndef _BINARY_HEAP_H_
        #define _BINARY_HEAP_H_

        #include "dsexceptions.h"
        

        // BinaryHeap class
        //
        // CONSTRUCTION: with a negative infinity sentinel and
        //               optional capacity (that defaults to 100)
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // deleteMin( minItem )   --> Remove (and optionally return) smallest item
        // Comparable findMin( )  --> Return smallest item
        // bool isEmpty( )        --> Return true if empty; else false
        // bool isFull( )         --> Return true if full; else false
        // void makeEmpty( )      --> Remove all items
        // ******************ERRORS********************************
        // Throws Underflow and Overflow as warranted

        template <class Comparable>
        class BinaryHeap
        {
          public:
            explicit BinaryHeap( int capacity = 100 );  
            bool isEmpty( ) const;
            bool isFull( ) const;
            const Comparable & findMin( ) const;

            void insert( const Comparable & x );
            void deleteMin( );
            void deleteMin( Comparable & minItem );
            void makeEmpty( );
            
          private:
            int currentSize;  // Number of elements in heap
            Comparable *array; // The heap array
            int maxsize;
            void buildHeap( );
            void percolateDown( int hole );
        };

        #include "BinaryHeap.cpp"
        #endif
