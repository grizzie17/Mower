#ifndef HPP_TARRAY2
#define HPP_TARRAY2

#include "math_helper.hpp"

namespace Yogi { namespace Utilities {


template <typename T>
class TArray2
{
public:
    TArray2();
    TArray2( unsigned rows, unsigned cols );
    TArray2( const TArray2<T>& r );
    ~TArray2();

    typedef TArray2<T> TTArray2;

public:
    template <typename U>
    class Row
    {
    public:
        Row( TTArray2& arr, unsigned row );

        U&
        operator[]( unsigned col );
        U
        operator[]( unsigned col ) const;

    protected:
        TTArray2& m_arr;
        unsigned  m_row;
    };

    template <typename U>
    class ConstRow
    {
    public:
        ConstRow( const TTArray2& arr, unsigned row );
        U
        operator[]( unsigned col ) const;

        const TTArray2& m_arr;
        unsigned        m_row;
    };

    Row<T>
    operator[]( unsigned row );
    ConstRow<T>
    operator[]( unsigned row ) const;

    T
    getValue( unsigned row, unsigned col ) const;
    T&
    getRef( unsigned row, unsigned col );

    const TArray2<T>&
    operator=( const TArray2<T>& r );

protected:
    unsigned m_nRows;
    unsigned m_nColumns;
    T*       m_pArray;
};

// Class Lifecycle =======================

template <typename T>
inline TArray2<T>::TArray2()
        : m_nRows( 2 )
        , m_nColumns( 2 )
        , m_pArray( 0 )
{
    m_pArray = new T[m_nRows * m_nColumns]();
}

template <typename T>
inline TArray2<T>::TArray2( unsigned row, unsigned col )
        : m_nRows( row )
        , m_nColumns( col )
        , m_pArray( 0 )
{
    m_nRows = max( 1U, m_nRows );
    m_nColumns = max( 1U, m_nColumns );
    m_pArray = new T[m_nRows * m_nColumns]();
}

template <typename T>
inline TArray2<T>::TArray2( const TArray2<T>& r )
        : m_nRows( r.m_nRows )
        , m_nColumns( r.m_nColumns )
        , m_pArray( 0 )
{
    unsigned TLen = m_nRows * m_nColumns;
    //delete[] m_pArray;
    m_pArray = new T[TLen];
    T* p = m_pArray;
    T* pEnd = p + TLen;
    T* pR = r.m_pArray;
    while ( p < pEnd )
    {
        *p++ = *pR++;
    }
}

template <typename T>
inline TArray2<T>::~TArray2()
{
    delete[] m_pArray;
}

// Allow Array of Arrays notation ===================

template <typename T>
template <typename U>
inline TArray2<T>::Row<U>::Row( TArray2<T>& arr, unsigned row )
        : m_arr( arr )
        , m_row( row )
{}

template <typename T>
template <typename U>
inline U&
TArray2<T>::Row<U>::operator[]( unsigned col )
{
    return m_arr.getRef( m_row, col );
}

template <typename T>
template <typename U>
inline U
TArray2<T>::Row<U>::operator[]( unsigned col ) const
{
    return m_arr.getValue( m_row, col );
}

template <typename T>
template <typename U>
inline TArray2<T>::ConstRow<U>::ConstRow( const TArray2<T>& arr, unsigned row )
        : m_arr( arr )
        , m_row( row )
{}

template <typename T>
template <typename U>
inline U
TArray2<T>::ConstRow<U>::operator[]( unsigned col ) const
{
    return m_arr.getValue( m_row, col );
}

template <typename T>
inline TArray2<T>::Row<T>
TArray2<T>::operator[]( unsigned row )
{
    return Row<T>( *this, row );
}

template <typename T>
inline TArray2<T>::ConstRow<T>
TArray2<T>::operator[]( unsigned row ) const
{
    return ConstRow<T>( *this, row );
}

// Public Functions ===================

template <typename T>
inline T
TArray2<T>::getValue( unsigned row, unsigned col ) const
{
    return m_pArray[row * m_nColumns + col];
}

template <typename T>
inline T&
TArray2<T>::getRef( unsigned row, unsigned col )
{
    return m_pArray[row * m_nColumns + col];
}


template <typename T>
const TArray2<T>&
TArray2<T>::operator=( const TArray2<T>& r )
{
    m_nRows = r.m_nRows;
    m_nColumns = r.m_nColumns;

    unsigned TLen = m_nRows * m_nColumns;
    delete[] m_pArray;
    m_pArray = new T[TLen];
    T* p = m_pArray;
    T* pEnd = p + TLen;
    T* pR = r.m_pArray;
    while ( p < pEnd )
    {
        *p++ = *pR++;
    }
    return *this;
}


}}    // namespace Yogi::Utilities

#endif    // HPP_TARRAY2
