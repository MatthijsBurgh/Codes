#include "PQSortedBinary.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

PQSortedBinary::PQSortedBinary
 
  ( int      maxItems )

{
  maxItems_ = maxItems;

  items_ = new STDITEM[maxItems];
  
  count_ = 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


PQSortedBinary::~PQSortedBinary()

{
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQSortedBinary::clear()

{
  count_ = 0; 
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


bool PQSortedBinary::isEmpty()

{
  return count_ == 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQSortedBinary::put

  ( STDITEM                 item )

{
  int i = -1; 
  int j = count_;

  int p = item.prio;

  // invariant 1: -1 <= i < j <= count_
  // invariant 2: items_[i].prio >= p > items_[j].prio

  while ( i+1 != j ) 
  {
    int m = (i + j) / 2; // rounded down, 0<=i<m<j<=count_

    if ( items_[m].prio >= p ) 
    {
      i = m;
    } 
    else 
    { // p > items_[m].prio
      j = m;
    }
  }
  
  // move all items
 
  int iInsert = i+1;

  for ( i = count_ ; i > iInsert ; i-- )
  {
    items_[i] = items_[i-1];
  }
   
  items_[iInsert] = item;

  count_++;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


STDITEM PQSortedBinary::getPrio()

{
  count_--;

  return items_[ count_ ];
}
