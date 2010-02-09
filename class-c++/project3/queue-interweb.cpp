#ifndef QUEUE_H
#define QUEUE_H

#include "except"

template< class TYPE >
  class QUEUE_OF
  {
    private:

      TYPE *m_data;
      int m_size;
      int m_writePos;
      int m_readPos;

    public:

      QUEUE_OF():
        m_data( 0 ),
        m_size( 0 ),
        m_writePos( 0 ),
        m_readPos( 0 )
      {
      }

      QUEUE_OF( int size ):
        m_data( new TYPE[ size + 2 ] ),
        m_size( size + 2 ),
        m_writePos( 0 ),
        m_readPos( m_size - 1 )
      {
      }

      ~QUEUE_OF() { delete [] m_data; }

      void resize( int size )
      {
        BGN

        #ifdef TSTBUG
          if( ! isEmpty() )
            THROW_ERR( "Queue is not empty" )
        #endif

        size += 2;
        if( size > m_size )
        {
          delete [] m_data;
          m_data = new TYPE[ size ];
          m_size = size;
          clear();
        }
      }

      int isEmpty() const
      {
        return (m_readPos == m_size - 1 && m_writePos == 0) ||
               (m_readPos + 1 == m_writePos);
      }

      void clear() { m_writePos = 0; m_readPos = m_size - 1; }

      void put( const TYPE &info )
      {
        BGN

        #ifdef TSTBUG
          if( m_data == 0 )
            THROW_ERR( "Trying to put() onto unallocated queue" )
        #endif

        m_data[ m_writePos++ ] = info;
        if( m_writePos >= m_size )
          m_writePos = 0;

        #ifdef TSTBUG
          if( m_writePos == m_readPos )
            THROW_ERR( "Queue overflow" )
        #endif
      }

      TYPE get()
      {
        BGN

        #ifdef TSTBUG
          if( m_data == 0 )
            THROW_ERR( "Trying to get() from unallocated queue" )
        #endif

        if( ++m_readPos >= m_size )
          m_readPos = 0;

        #ifdef TSTBUG
          if( m_readPos == m_writePos )
            THROW_ERR( "Queue underflow" );
        #endif

        return m_data[ m_readPos ];
      }

      TYPE peek()
      {
        BGN

        #ifdef TSTBUG
          if( m_data == 0 )
            THROW_ERR( "Trying to peek() into unallocated queue" )
        #endif

        int readPos;

        readPos = m_readPos + 1;
        if( readPos >= m_size )
          readPos = 0;

        #ifdef TSTBUG
          if( readPos == m_writePos )
            THROW_ERR( "Queue underflow" );
        #endif

        return m_data[ readPos ];
      }
  };

#endif
